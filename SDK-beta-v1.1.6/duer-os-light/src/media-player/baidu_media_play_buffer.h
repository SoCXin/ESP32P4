// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Chen Xihao (chenxihao@baidu.com)
//
// Description: Buffer for media player

#ifndef BAIDU_TINYDU_IOT_OS_SRC_MEDIA_PLAYER_BAIDU_MEDIA_PLAY_BUFFER_H
#define BAIDU_TINYDU_IOT_OS_SRC_MEDIA_PLAYER_BAIDU_MEDIA_PLAY_BUFFER_H

#include "rtos.h"

namespace duer {

// FIFO circle buffer
class MediaPlayBuffer {
public:
    MediaPlayBuffer(void* buffer, size_t size);

    ~MediaPlayBuffer();

    // write buffer until buffer has enough space
    void write(const void* data, size_t size);

    // read buffer until buffer has enough data
    void read(void* data, size_t size);

    void clear();

    static const size_t MIN_BUFFER_SIZE = 5 * 1024;

    static const size_t DEFAULT_BUFFER_SIZE = 10 * 1024;

private:
    MediaPlayBuffer(const MediaPlayBuffer&);

    MediaPlayBuffer& operator=(const MediaPlayBuffer&);

    char* const _buffer;
    const size_t _BUFFER_SIZE;
    Mutex _mutex;
    bool _wait;
    Semaphore _semaphore;
    int _start;
    int _end;
};

} // namespace duer

#endif // BAIDU_TINYDU_IOT_OS_SRC_MEDIA_PLAYER_BAIDU_MEDIA_PLAY_BUFFER_H
