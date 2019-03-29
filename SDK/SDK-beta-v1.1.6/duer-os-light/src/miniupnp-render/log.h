// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Chang Li (changli@baidu.com)
//
// Description: log function for miniupnprender.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_LOG_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_LOG_H

#define DEBUG
#ifdef DEBUG 
#define DUER_LOG_LEVEL (4)
#endif

#include "duer_log.h"

#define MRPRINTF(fmt, arg...) do { \
    printf("[%s:%d] " fmt, __FUNCTION__, __LINE__, ## arg); \
} while (0)

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_LOG_H

