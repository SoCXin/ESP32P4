// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Duan Lian (duanlian01@baidu.com)
//
// Description: OTA Shared Buffer

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_SHARED_BUFFER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_SHARED_BUFFER_H

#include "rtos.h"

namespace duer {

class SharedBuffer {
public:
    SharedBuffer(unsigned int size);

    ~SharedBuffer();

    unsigned int read(unsigned char out[], unsigned int size);

    unsigned int write(const unsigned char in[], unsigned int size);

    void wait();

private:
    unsigned int _m_n_buffer_size;

    unsigned int _m_n_write_offset;

    unsigned int _m_n_data_size;

    unsigned char* _m_p_buffer;

    rtos::Semaphore _sem_read;

    rtos::Semaphore _sem_write;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_SHARED_BUFFER_H
