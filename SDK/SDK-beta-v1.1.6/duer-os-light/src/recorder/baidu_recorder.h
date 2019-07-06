// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: tai xiurong (taixiurong@baidu.com)
//
// Description:

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_RECORDER_BAIDU_OS_RECORDER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_RECORDER_BAIDU_OS_RECORDER_H

#include <mbed.h>

#include "baidu_ca_adapter.h"

// #define O_BUFFER_LEN        (800)
// #define I_BUFFER_LEN        ((O_BUFFER_LEN - 1) / 4 * 3)

//#define REC_LOG(_fmt, ...)      //LOG("[REC]"_fmt, ##__VA_ARGS__)

namespace duer {
static const unsigned int s_o_buffer_len = 800;
static const unsigned int s_i_buffer_len = (s_o_buffer_len -1)/4 *3;
class Recorder {
public:

    class IPlugin {
    public:

        virtual int start_record() = 0;

        virtual size_t read(void* data, size_t size) = 0;

        virtual int stop_record() = 0;

        virtual ~IPlugin() = 0;

    };

    class IListener {
    public:

        virtual int on_start() = 0;

        virtual int on_resume() = 0;

        virtual int on_data(const void* data, size_t size) = 0;

        virtual int on_pause() = 0;

        virtual int on_stop() = 0;

        virtual ~IListener() = 0;

    };

    class MiddleWare: public IListener {
    public:

        MiddleWare();

        virtual ~MiddleWare();

        int set_listener(IListener* listener);

    protected:

        int process_start();

        int process_resume();

        int process_data(const void* data, size_t size);

        int process_pause();

        int process_stop();

    private:

        IListener* _listener;
    };

    Recorder(IPlugin* plugin, size_t  size, void* data);
    Recorder(IPlugin* plugin, size_t  size);
    Recorder(IPlugin* plugin);

    virtual ~Recorder();

    int start();

    int resume();

    int pause();

    int stop();

    int set_listener(IListener* listener);

    static void add_drop_invalid_record();

private:
    void run();
    IPlugin*            _plugin;
    IListener*          _listener;
    rtos::Thread        _thread;
    int                 _state;
    size_t              _capacity;
    void*               _buff;

};

}//duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_RECORDER_BAIDU_OS_RECORDER_H
