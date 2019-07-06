// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Chang Li (changli@baidu.com)
//
// Description: utilities for miniupnprender.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_UTILITIES_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_UTILITIES_H

#include <stdarg.h>
#include <stddef.h>
#include "sockets.h"

#define MAX(a,b) ((a) > (b) ? (a) : (b)); 
#define MIN(a,b) ((a) < (b) ? (a) : (b));

struct string_s {
    char* data; // ptr to start of memory area
    size_t off;
    size_t size;
};

/* String functions */
/* We really want this one inlined, since it has a major performance impact */
static inline int
__attribute__((__format__(__printf__, 2, 3)))
strcatf(struct string_s* str, const char* fmt, ...) {
    int ret;
    int size;
    va_list ap;

    if (str->off >= str->size)
        return 0;

    va_start(ap, fmt);
    size = str->size - str->off;
    ret = vsnprintf(str->data + str->off, size, fmt, ap);
    str->off += MIN(ret, size);
    va_end(ap);
    return ret;
}
static inline void strncpyt(char* dst, const char* src, size_t len) {
    strncpy(dst, src, len);
    dst[len - 1] = '\0';
}

/**
 *  @brief get the seconds from the boot time
 *  @ret the seconds
 */
unsigned int internal_time();

/**
 *  @brief get the time stamp from the boot time
 *  @ret the miliseconds
 */
unsigned int gettimeofday(struct timeval* tm, void* /* timezone */);

/**
 *  @brief strcasesstrc
 *  @param[in] s source
 *  @param[in] p find str
 *  @param[in] t division char
 *  @return[out] soket id if return -1 , create socket fail
 */
char* strcasestrc(const char* s, const char* p, const char t);

/**
 *  @brief strcat_char
 *  @param[in] str dst string
 *  @param[in/out] len when add c to str's tail , the str's len 
 *  @param[in/out] templen now str's len
 *  @param[in] c which want to str's tail
 *  @return[out] new str 
 */
char* strcat_char(char* str, int* len, int* tmplen, char c);

/**
 *  @brief strcat_str
 *  @param[in] str dst string
 *  @param[in/out] len when add s2 to str's tail , the str's len 
 *  @param[in/out] templen now str's len
 *  @param[in] s2 which want to str's tail
 *  @return[out] new str 
 */
char* strcat_str(char* str, int* len, int* tmplen, const char *s2);

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_UTILITIES_H

