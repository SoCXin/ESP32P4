// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Duan Lian (duanlian01@baidu.com)
//
// Description: OTA Coap Downloader

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_COAP_DOWNLOADER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_COAP_DOWNLOADER_H

#include "baidu_iot_ota_url.h"
#include "baidu_iot_ota_downloader.h"
#include "baidu_iot_ota_coap_client.h"

namespace duer {

class OTACoapDownloader : public IOTADownloader {
public:
    OTACoapDownloader(URL* url, const char* cert);

    virtual ~OTACoapDownloader();

    virtual int connect();

    virtual int disconnect();

    virtual int get(data_available_cb cb, void* ctx);

private:
    URL* _m_p_url;

    CoapsClient* _m_p_coaps_client;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_COAP_DOWNLOADER_H
