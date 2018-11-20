// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: The APIs for debug the programs.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_DEBUG_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_DEBUG_H

#include "baidu_ca_types.h"
//TODO this file don't need any more see duer_log.h
/*
 * debug function
 *
 * @Param level, in, void *, debug level
 * @Param file, in, const char *, debug file
 * @Param line, in, bca_u32_t, debug file line
 * @Param msg, in, debug message
 */
//BCA_INT void bca_debug_print(bca_u32_t level, const char* file,
//                             bca_u32_t line, const char* msg);

/*
 * debug function
 *
 * @Param level, in, void *, debug level
 * @Param file, in, const char *, debug file
 * @Param line, in, bca_u32_t, debug file line
 * @Param fmt, in, debug message print format
 */
//BCA_INT void bca_debug(bca_u32_t level, const char* file,
//                       bca_u32_t line, const char* fmt, ...);

//#ifdef BCA_DEBUG_LEVEL
//#define BCA_DEBUG_EXT(_l, _f, _li, ...) bca_debug(_l, _f, _li, __VA_ARGS__)
//#else
//#define BCA_DEBUG_EXT(...)
//#endif
//
//#if defined(BCA_DEBUG_LEVEL) && (BCA_DEBUG_LEVEL >= 5)
//#define BCA_LOGV_EXT(_f, _l, ...)   BCA_DEBUG_EXT(5, _f, _l, __VA_ARGS__)
//#else
//#define BCA_LOGV_EXT(...)
//#endif
//
//#if defined(BCA_DEBUG_LEVEL) && (BCA_DEBUG_LEVEL >= 4)
//#define BCA_LOGD_EXT(_f, _l, ...)   BCA_DEBUG_EXT(4, _f, _l, __VA_ARGS__)
//#else
//#define BCA_LOGD_EXT(...)
//#endif
//
//#if defined(BCA_DEBUG_LEVEL) && (BCA_DEBUG_LEVEL >= 3)
//#define BCA_LOGI_EXT(_f, _l, ...)   BCA_DEBUG_EXT(3, _f, _l, __VA_ARGS__)
//#else
//#define BCA_LOGI_EXT(...)
//#endif
//
//#if defined(BCA_DEBUG_LEVEL) && (BCA_DEBUG_LEVEL >= 2)
//#define BCA_LOGW_EXT(_f, _l, ...)   BCA_DEBUG_EXT(2, _f, _l, __VA_ARGS__)
//#else
//#define BCA_LOGW_EXT(...)
//#endif
//
//#if defined(BCA_DEBUG_LEVEL) && (BCA_DEBUG_LEVEL >= 1)
//#define BCA_LOGE_EXT(_f, _l, ...)   BCA_DEBUG_EXT(1, _f, _l, __VA_ARGS__)
//#else
//#define BCA_LOGE_EXT(...)
//#endif
//
//#if defined(BCA_DEBUG_LEVEL) && (BCA_DEBUG_LEVEL >= 0)
//#define BCA_LOGWTF_EXT(_f, _l, ...)   BCA_DEBUG_EXT(0, _f, _l, __VA_ARGS__)
//#else
//#define BCA_LOGWTF_EXT(...)
//#endif
//
//#define BCA_DEBUG(_l, ...)      BCA_DEBUG_EXT(_l, __FILE__, __LINE__, __VA_ARGS__)
//#define BCA_LOGV(...)           BCA_LOGV_EXT(__FILE__, __LINE__, __VA_ARGS__)
//#define BCA_LOGD(...)           BCA_LOGD_EXT(__FILE__, __LINE__, __VA_ARGS__)
//#define BCA_LOGI(...)           BCA_LOGI_EXT(__FILE__, __LINE__, __VA_ARGS__)
//#define BCA_LOGW(...)           BCA_LOGW_EXT(__FILE__, __LINE__, __VA_ARGS__)
//#define BCA_LOGE(...)           BCA_LOGE_EXT(__FILE__, __LINE__, __VA_ARGS__)
//#define BCA_LOGWTF(...)         BCA_LOGWTF_EXT(__FILE__, __LINE__, __VA_ARGS__)

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_DEBUG_H
