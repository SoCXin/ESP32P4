// Copyright (2016) Baidu Inc. All rights reserved.
/**
 * File: duer_app.cpp
 * Desc: Demo for how to start Duer OS.
 */

#include "duer_app.h"
#include "baidu_ca_scheduler.h"
#include "baidu_media_manager.h"
#include "duer_log.h"
#include "device_controller.h"
#include "events.h"
#if defined(TARGET_UNO_91H)
#include "gpadckey.h"
#endif
// #include "baidu_json.h"
// 
#include "duer_play_command_manager.h"

namespace duer {

#if defined(TARGET_UNO_91H)
#define LED_RED LED1
#define LED_GREEN LED2
#define LED_BLUE LED3

static GpadcKey s_button(KEY_A0);
static GpadcKey s_pause_button(KEY_A1);
static GpadcKey s_test(KEY_A5);
#else
#define DUER_APP_RECORDER_BUTTON  SW2
static mbed::InterruptIn s_button = mbed::InterruptIn(DUER_APP_RECORDER_BUTTON);
#endif

static const char BAIDU_DEV_CONNECT_SUCCESS_PROMPT_FILE[] = "/sd/cloud_connected.mp3";
static const char BAIDU_DEV_DISCONNECTED_PROMPT_FILE[] = "/sd/cloud_disconnected.mp3";

static const unsigned int RECONN_DELAY_MIN = 2000;
static const unsigned int RECONN_DELAY_MAX = 32001;

class SchedulerEventListener : public Scheduler::IOnEvent {
public:
    SchedulerEventListener(DuerApp* app) :
            _app(app) {
        Scheduler::instance().set_on_event_listener(this);
    }

    virtual ~SchedulerEventListener() {
    }

    virtual int on_start() {
        DUER_LOGI("SchedulerEventListener::on_start");

        MEMORY_STATISTICS("Scheduler::on_start");

        device_controller_init();

        event_set_handler(EVT_KEY_REC_PRESS, _app, &DuerApp::talk_start);
        event_set_handler(EVT_KEY_REC_RELEASE, _app, &DuerApp::talk_stop);
        event_set_handler(EVT_KEY_PAUSE, _app, &DuerApp::pause_play);
        event_set_handler(EVT_KEY_TEST, _app, &DuerApp::test);

        _app->set_color(DuerApp::CYAN);

        MediaManager::instance().play_local(BAIDU_DEV_CONNECT_SUCCESS_PROMPT_FILE);

        return 0;
    }

    virtual int on_stop() {
        _app->set_color(DuerApp::PURPLE);

        MediaManager::instance().stop();
        _app->talk_stop();

        event_set_handler(EVT_KEY_REC_PRESS, NULL);
        event_set_handler(EVT_KEY_REC_RELEASE, NULL);
        event_set_handler(EVT_KEY_PAUSE, NULL);
        event_set_handler(EVT_KEY_TEST, NULL);

        MEMORY_STATISTICS("Scheduler::on_stop");

        DUER_LOGI("SchedulerEventListener::on_stop");

        _app->restart();

        return 0;
    }

    virtual int on_action(const char* url, bool is_speech, bool is_continue_previous) {
        DUER_LOGI("SchedulerEventListener::on_action: %s", url);
        _app->set_color(DuerApp::BLUE);
        MediaManager::instance().play_url(url, is_speech, is_continue_previous);

        return 0;
    }

    virtual int on_data(const char* data) {
        DUER_LOGV("SchedulerEventListener::on_data: %s", data);
        // baidu_json* value = baidu_json_Parse(data);
        // baidu_json* payload = baidu_json_GetObjectItem(value, "payload");

        // if (payload != NULL) {
        //     baidu_json* audio_item_id = baidu_json_GetObjectItem(payload, "audio_item_id");

        //     if (audio_item_id != NULL) {
        //         DUER_LOGI("track id: %s", audio_item_id->valuestring);
        //     }
        // }
        // baidu_json_Delete(value);

        return 0;
    }

private:
    DuerApp* _app;
};

class RecorderListener : public Recorder::IListener {
public:
    RecorderListener(DuerApp* app) :
        _app(app),
        _start_send_data(false) {
    }

    virtual ~RecorderListener() {
    }

    virtual int on_start() {
        _app->set_color(DuerApp::RED);
        DUER_LOGI("RecorderObserver::on_start");
        MEMORY_STATISTICS("Recorder::on_start");
        return 0;
    }

    virtual int on_resume() {
        return 0;
    }

    virtual int on_data(const void* data, size_t size) {
        if (!_start_send_data) {
            _start_send_data = true;
        }

        DUER_LOGV("RecorderObserver::on_data: data = %p, size = %d", data, size);
        Scheduler::instance().send_content(data, size, false);
        return 0;
    }

    virtual int on_pause() {
        return 0;
    }

    virtual int on_stop() {
        if (_start_send_data) {
            Scheduler::instance().send_content(NULL, 0, false);
            _start_send_data = false;
        }

        MEMORY_STATISTICS("Recorder::on_stop");
        DUER_LOGI("RecorderObserver::on_stop");
        _app->set_color(DuerApp::GREEN);
        return 0;
    }

private:
    DuerApp* _app;
    bool _start_send_data;
};

DuerApp::DuerApp()
    : _recorder_listener(new RecorderListener(this))
    , _on_event(new SchedulerEventListener(this))
#if !defined(TARGET_UNO_91H)
    , _indicate(LED_BLUE, LED_GREEN, LED_RED)
#endif
    , _timer(this, &DuerApp::start, osTimerOnce)
    , _delay(RECONN_DELAY_MIN)
#if defined(TEST_BOARD)
    , _send_ticker(this, &DuerApp::send_timestamp, osTimerPeriodic)
#endif
{
    _recorder.set_listener(_recorder_listener);

#if !defined(TARGET_UNO_91H)
    _indicate = OFF;
#endif
}

DuerApp::~DuerApp() {
    delete _recorder_listener;
    delete _on_event;
}

void DuerApp::start() {
    Scheduler::instance().start();

    s_button.fall(this, &DuerApp::button_fall_handle);
    s_button.rise(this, &DuerApp::button_rise_handle);
#if defined(TARGET_UNO_91H)
    s_pause_button.fall(this, &DuerApp::pause_button_fall_handle);
    s_test.fall(this, &DuerApp::test_handle);
#endif
}

void DuerApp::stop() {
    s_button.fall(NULL);
    s_button.rise(NULL);
#if defined(TARGET_UNO_91H)
    s_pause_button.fall(NULL);
#endif
    Scheduler::instance().stop();
}

void DuerApp::restart() {
    if (_delay < RECONN_DELAY_MAX) {
        _timer.start(_delay);
        _delay <<= 1;
    } else {
        MediaManager::instance().play_local(BAIDU_DEV_DISCONNECTED_PROMPT_FILE);
    }
}

void DuerApp::talk_start() {
    MediaManager::instance().stop();
    Scheduler::instance().clear_content();
    _recorder.start();
}

void DuerApp::talk_stop() {
    _recorder.stop();
}

void DuerApp::set_color(Color c) {
#if !defined(TARGET_UNO_91H)
    _indicate = c;
#endif

    if (c == CYAN) {
        _delay = RECONN_DELAY_MIN;
#if defined(TEST_BOARD)
        _send_ticker.start(60 * 1000);//update interval to 1min
#endif
    } else if (c == PURPLE) {
#if defined(TEST_BOARD)
        _send_ticker.stop();
#endif
    }
}

void DuerApp::button_fall_handle() {
    event_trigger(EVT_KEY_REC_PRESS);
}

void DuerApp::button_rise_handle() {
    event_trigger(EVT_KEY_REC_RELEASE);
}

void DuerApp::pause_button_fall_handle() {
    event_trigger(EVT_KEY_PAUSE);
}

void DuerApp::test_handle() {
    event_trigger(EVT_KEY_TEST);
}

void DuerApp::pause_play() {
    MediaManager::instance().pause_or_resume();
}

void DuerApp::test()
{
    static int i = 0;
    switch (i % 3) {
    case 0:
        duer::PlayCommandManager::instance().next();
        break;
    case 1:
        duer::PlayCommandManager::instance().previous();
        break;
    case 2:
        duer::PlayCommandManager::instance().repeat();
        break;
    }
    i++;
}

#if defined(TEST_BOARD)
void DuerApp::send_timestamp() {
    Object data;
    data.putInt("time", us_ticker_read());
    Scheduler::instance().report(data);
}
#endif

} // namespace duer
