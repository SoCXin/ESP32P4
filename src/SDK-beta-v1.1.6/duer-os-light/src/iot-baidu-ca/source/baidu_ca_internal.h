// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: The internal common header.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_INTERNAL_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_INTERNAL_H

#include "baidu_ca.h"
#include "baidu_ca_memory.h"

#define BCA_MEMCPY(...)     memcpy(__VA_ARGS__)
#define BCA_MEMCMP(...)     memcmp(__VA_ARGS__)
#define BCA_MEMSET(...)     memset(__VA_ARGS__)
#define BCA_STRLEN(...)     strlen(__VA_ARGS__)
#define BCA_SNPRINTF(...)   snprintf(__VA_ARGS__)

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_INTERNAL_H
