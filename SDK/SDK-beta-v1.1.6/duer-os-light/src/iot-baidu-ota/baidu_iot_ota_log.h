// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Duan Lian (duanlian01@baidu.com)
//
// Description: OTA Debuger

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_LOG_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_LOG_H

#include <stdio.h>

#define DEBUG_LEVEL_INF 3
#define DEBUG_LEVEL_DBG 2
#define DEBUG_LEVEL_WRN 1
#define DEBUG_LEVEL_ERR 0
#define OTA_DEBUG_LEVEL DEBUG_LEVEL_ERR

#define OTA_LOG(format, level, ...) do { \
                                        if (OTA_DEBUG_LEVEL >= level) { \
                                            printf("%s:%s: "format, \
                                            __FILE__, __FUNCTION__, ##__VA_ARGS__); \
                                        } \
                                    } while (0);

#define OTA_LOG_INFO(format, ...) OTA_LOG(format, DEBUG_LEVEL_INF, __VA_ARGS__)
#define OTA_LOG_DBG(format, ...)  OTA_LOG(format, DEBUG_LEVEL_DBG, __VA_ARGS__)
#define OTA_LOG_WARN(format, ...) OTA_LOG(format, DEBUG_LEVEL_WRN, __VA_ARGS__)
#define OTA_LOG_ERR(format, ...)  OTA_LOG(format, DEBUG_LEVEL_ERR, __VA_ARGS__)

#define OTA_FUNC_ENTER() OTA_LOG_INFO("Enter %s:%s\n", __FILE__, __FUNCTION__)
#define OTA_FUNC_LEAVE() OTA_LOG_INFO("Leave %s:%s\n", __FILE__, __FUNCTION__)

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_LOG_H
