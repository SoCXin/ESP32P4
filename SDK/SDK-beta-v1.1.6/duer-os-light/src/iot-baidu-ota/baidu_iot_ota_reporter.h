// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Duan Lian (duanlian01@baidu.com)
//
// Description: OTA Reporter

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_REPORTER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_REPORTER_H

#include "rtos.h"
#include "baidu_ca_object.h"
#include "baidu_iot_ota_package_info.h"

namespace duer {

class OTAReporter {
public:
    enum {
        OTA_STATE_IDLE = 0,
        OTA_STATE_DOWNLOADING,
        OTA_STATE_DOWNLOADED,
        OTA_STATE_INSTALLING,
        OTA_STATE_INSTALLED
    };

    enum {
        OTA_EVENT_BEGIN,
        OTA_EVENT_CONNECT_FAIL,
        OTA_EVENT_CONNECTION_LOST,
        OTA_EVENT_TIMEOUT,
        OTA_EVENT_DOWNLOADING,
        OTA_EVENT_DOWNLOAD_COMPLETE,
        OTA_EVENT_DOWNLOAD_FAIL,
        OTA_EVENT_INSTALLING,
        OTA_EVENT_IMAGE_INVALID,
        OTA_EVENT_WRITE_ERROR,
        OTA_EVENT_INSTALLED,
        OTA_EVENT_DELETED,
        OTA_EVENT_REJECT,
    };

    OTAReporter(const char* transaction_id);

    ~OTAReporter();

    int report_state(int state, ...);

    int report_event(int event, ...);

    static int report_package_info(struct os_info& os);

    static void ota_report_status(Object& values);

private:
    static void get_packager_info(Object& obj);

    char* _m_p_sztransaction_id;

    int _m_current_event;

    rtos::Mutex _m_lock;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_REPORTER_H
