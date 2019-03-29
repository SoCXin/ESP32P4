// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Duan Lian (duanlian01@baidu.com)
//
// Description: OTA HTTP Downloader

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_HTTP_DOWNLOADER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_HTTP_DOWNLOADER_H

#include "baidu_iot_ota_url.h"
#include "baidu_http_client.h"
#include "baidu_iot_ota_downloader.h"

namespace duer {

class OTAHttpDownloader : public IOTADownloader {
public:
    OTAHttpDownloader(URL* url);

    virtual ~OTAHttpDownloader();

    virtual int connect();

    virtual int disconnect();

    virtual int get(data_available_cb cb, void* ctx);

private:
    static int data_available(void* ctx, e_data_pos pos,
                              const char* buf,
                              size_t len,
                              const char* type);
    char* _m_p_url;

    HttpClient* _p_http_client;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_HTTP_DOWNLOADER_H
