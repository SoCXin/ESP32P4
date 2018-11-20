// Copyright (2016) Baidu Inc. All rights reserved.

#ifndef BAIDU_IOT_TINYDU_DEMO_DUER_APP_H
#define BAIDU_IOT_TINYDU_DEMO_DUER_APP_H

#include "baidu_recorder_manager.h"
#include "baidu_ca_scheduler.h"

namespace duer
{

class DuerApp
{
public:
    enum Color {
        WHITE,
        YELLOW,
        PURPLE,
        RED,
        CYAN,
        GREEN,
        BLUE,
        OFF
    };

    DuerApp();

    ~DuerApp();

    void start();

    void stop();

    void talk_start();

    void talk_stop();

    void set_color(Color c);

    void restart();

    int get_topic_id() const;

    void pause_play();

    void test();

private:
    void button_fall_handle();

    void button_rise_handle();

    void pause_button_fall_handle();

    void test_handle();

#if defined(TEST_BOARD)
    void send_timestamp();
#endif

    RecorderManager      _recorder;
    Recorder::IListener* _recorder_listener;

    duer::Scheduler::IOnEvent* _on_event;

#if !defined(TARGET_UNO_91H)
    mbed::BusOut                    _indicate;
#endif

    rtos::RtosTimer                 _timer;
    unsigned int                    _delay;

#if defined(TEST_BOARD)
    rtos::RtosTimer                 _send_ticker;
#endif
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_DEMO_DUER_APP_H
