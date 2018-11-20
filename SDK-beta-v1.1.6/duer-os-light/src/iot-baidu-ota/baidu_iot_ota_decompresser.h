// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Duan Lian (duanlian01@baidu.com)
//
// Description: OTA Decompresser

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_DECOMPRESSER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_DECOMPRESSER_H

namespace duer {

class OTADecompresser {
public:
    OTADecompresser();

    ~OTADecompresser();

    unsigned int decompress(unsigned char buffer[],
                            unsigned int size,
                            unsigned char output[],
                            unsigned int out_size);
};

} // name_space duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_DECOMPRESSER_H
