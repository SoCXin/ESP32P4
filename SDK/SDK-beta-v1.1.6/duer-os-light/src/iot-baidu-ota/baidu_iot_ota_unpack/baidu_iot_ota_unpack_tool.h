// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Duan Lian (duanlian01@baidu.com)
//
// Description: OTA Unpack Tool

#ifndef BAIDU_OTA_BAIDU_IOT_OTA_BAIDU_IOT_OTA_UNPACK_BAIDU_IOT_OTA_UNPACK_TOOL_H
#define BAIDU_OTA_BAIDU_IOT_OTA_BAIDU_IOT_OTA_UNPACK_BAIDU_IOT_OTA_UNPACK_TOOL_H

#include "IOtaUpdater.h"

namespace duer {

class OTAReporter;

class NewFirmwareImageUnpackTool {
public:
    NewFirmwareImageUnpackTool(unsigned int decompress_chunk_size,
                               unsigned int resource_size,
                               IOtaUpdater* updater,
                               void* update_ctx,
                               OTAReporter* reporter);

    virtual ~NewFirmwareImageUnpackTool();

    virtual int unpack_ota_package_begin();

    virtual int unpack_ota_package(unsigned char* data, unsigned int len);

    virtual int unpack_ota_package_end();

    virtual int update_image_begin();

    virtual int update_image();

    virtual int update_image_end();

private:
    unsigned int _resource_size;

    unsigned int _resource_offset;

    double _download_percent;

    unsigned int _chunk_size;

    unsigned char* _cache;

    unsigned int  _in_size;

    void* _verification_cxt;

    void* _decompress_ctx;

    IOtaUpdater* _updater;

    void* _update_ctx;

    OTAReporter* _m_p_reporter;
};

} // namespace duer

#endif // BAIDU_OTA_BAIDU_IOT_OTA_BAIDU_IOT_OTA_UNPACK_BAIDU_IOT_OTA_UNPACK_TOOL_H
