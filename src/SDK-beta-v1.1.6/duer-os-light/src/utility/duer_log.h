// Copyright (2017) Baidu Inc. All rights reserved.
/**
 * File: duer_log.h
 * Auth: Su Hao(suhao@baidu.com)
 * Desc: Print log.
 */

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_DUER_LOG_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_DUER_LOG_H

#include "us_ticker_api.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void duer_log_report(const char* tag, const char* formate, ...);

#ifndef DUER_LOG_LEVEL
#define DUER_LOG_LEVEL (3)
#endif

#ifndef DUER_LOG_REPORT_LEVEL
#define DUER_LOG_REPORT_LEVEL (3)
#endif

#if defined(DUER_LOG_LEVEL)
#define DUER_LOG(_level, ...)     \
    printf("[%s][%lu] %s(%d): ", _level, us_ticker_read(), __FILE__, __LINE__), \
    printf(__VA_ARGS__), \
    printf("\n"), \
    duer_log_report(_level,__VA_ARGS__);
#endif

#if defined(DUER_LOG_LEVEL) && (DUER_LOG_LEVEL >= 5)
#define DUER_LOGV(...)          DUER_LOG("V", __VA_ARGS__)
#else
#define DUER_LOGV(...)
#endif

#if defined(DUER_LOG_LEVEL) && (DUER_LOG_LEVEL >= 4)
#define DUER_LOGD(...)          DUER_LOG("D", __VA_ARGS__)
#else
#define DUER_LOGD(...)
#endif

#if defined(DUER_LOG_LEVEL) && (DUER_LOG_LEVEL >= 3)
#define DUER_LOGI(...)          DUER_LOG("I", __VA_ARGS__)
#else
#define DUER_LOGI(...)
#endif

#if defined(DUER_LOG_LEVEL) && (DUER_LOG_LEVEL >= 2)
#define DUER_LOGW(...)          DUER_LOG("W", __VA_ARGS__)
#else
#define DUER_LOGW(...)
#endif

#if defined(DUER_LOG_LEVEL) && (DUER_LOG_LEVEL >= 1)
#define DUER_LOGE(...)          DUER_LOG("E", __VA_ARGS__)
#else
#define DUER_LOGE(...)
#endif

// the below error will not try to report to server
// see @baidu_duer_log_report.h/.cpp for more info
// these should only be used CA module where handle network connection
#if defined(DUER_LOG_LEVEL) && (DUER_LOG_LEVEL >= 2)
#define DUER_LOGNW(...)          DUER_LOG("NW", __VA_ARGS__)
#else
#define DUER_LOGNW(...)
#endif


#if defined(DUER_LOG_LEVEL) && (DUER_LOG_LEVEL >= 1)
#define DUER_LOGNE(...)          DUER_LOG("NE", __VA_ARGS__)
#else
#define DUER_LOGNE(...)
#endif

#ifdef __cplusplus
}
#endif

#endif/*BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_DUER_LOG_H*/
