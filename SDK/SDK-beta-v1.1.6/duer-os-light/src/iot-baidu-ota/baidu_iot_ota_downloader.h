// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Duan Lian (duanlian01@baidu.com)
//
// Description: OTA Downloader Interface

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_DOWNLOADER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_DOWNLOADER_H

namespace duer {

typedef int (*data_available_cb)(unsigned char* data, unsigned int len, void* ctx);

class IOTADownloader {
public:
    virtual ~IOTADownloader() {};

    virtual int connect() = 0;

    virtual int disconnect() = 0;

    virtual int get(data_available_cb cb, void* ctx) = 0;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_DOWNLOADER_H
