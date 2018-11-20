// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: tai xiurong (taixiurong@baidu.com)
//
// Description:

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_RECORDER_BAIDU_OS_SPEEX_ENCODER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_RECORDER_BAIDU_OS_SPEEX_ENCODER_H

#include "baidu_recorder.h"

namespace duer {

class SpeexEncoder: public Recorder::MiddleWare {

public:

    SpeexEncoder(size_t buff_size, void* buff);
    SpeexEncoder();

    virtual ~SpeexEncoder();

    virtual int on_start();

    virtual int on_resume();

    virtual int on_data(const void* data, size_t size);

    virtual int on_pause();

    virtual int on_stop();

private:
    static void recorder_output_handler(void* ctx, char* data, int size, int flush);
    void*   _buff;
    size_t  _capacity;
    char*   _data;
    size_t  _size;
    void* _encoder_buffer;
    bool _valid_record;
    const int _min_valid_size = 512;
};
}//duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_RECORDER_BAIDU_OS_SPEEX_ENCODER_H
