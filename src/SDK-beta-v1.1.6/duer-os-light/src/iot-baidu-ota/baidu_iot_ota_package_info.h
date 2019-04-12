// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Duan Lian (duanlian01@baidu.com)
//
// Description: OTA Package Information

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_PACKAGE_INFO_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_PACKAGE_INFO_H

#include <stdint.h>

namespace duer {

#define MAX_NAME_LENGTH 64
#define MAX_VERSION_LENGTH 24
#define MAX_APPID_LENGTH 16

struct os_info {
    char name[MAX_NAME_LENGTH + 1];
    char developer[MAX_NAME_LENGTH + 1];
    char version[MAX_VERSION_LENGTH + 1];
    char staged_version[MAX_VERSION_LENGTH + 1];
};

struct app_info {
    char id[MAX_APPID_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];
    char developer[MAX_NAME_LENGTH + 1];
    char version[MAX_VERSION_LENGTH + 1];
    char staged_version[MAX_VERSION_LENGTH + 1];
    char os_version[MAX_VERSION_LENGTH + 1];
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_PACKAGE_INFO_H
