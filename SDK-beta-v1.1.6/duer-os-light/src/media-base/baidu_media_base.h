// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Chen Xihao (chenxihao@baidu.com)
//
// Description: Base class of Media

#ifndef BAIDU_TINYDU_IOT_OS_SRC_MEDIA_BASE_BAIDU_MEDIA_BASE_H
#define BAIDU_TINYDU_IOT_OS_SRC_MEDIA_BASE_BAIDU_MEDIA_BASE_H

#include "mbed.h"
#include "baidu_recorder.h"
#include "baidu_media_type.h"

namespace duer {

class MediaBase : public Recorder::IPlugin {
public:
    int start_play(MediaType type);

    int write(const void* data, size_t size);

    int regulate_voice(unsigned char vol);

    int pause_play();

    int stop_play();

    bool is_play_stopped();

    virtual int start_record();

    virtual size_t read(void* data, size_t size);

    virtual int stop_record();

protected:
    virtual int on_start_play(MediaType type) = 0;

    virtual int on_write(const void* data, size_t size) = 0;

    virtual int on_voice(unsigned char vol) = 0;

    virtual int on_pause_play() = 0;

    virtual int on_stop_play() = 0;

    virtual int on_start_record() = 0;

    virtual size_t on_read(void* data, size_t size) = 0;

    virtual int on_stop_record() = 0;

    virtual bool is_play_stopped_internal() = 0;

private:
    static rtos::Mutex      _s_lock;
    static int              _s_status;
};

} // namespace duer

#endif // BAIDU_TINYDU_IOT_OS_SRC_MEDIA_BASE_BAIDU_MEDIA_BASE_H
