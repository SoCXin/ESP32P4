// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Zhong Shuai (zhongshuai@baidu.com)
//
// Description: Heap monitor

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_HEAP_MONITOR_HEAP_MONITOR_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_HEAP_MONITOR_HEAP_MONITOR_H

#include <stdlib.h>

#ifdef HEAP_MONITOR

#define MALLOC(size, module) malloc_t(size, module)
#define REALLOC(ptr, size, module) realloc_t(ptr, size, module)
#define CALLOC(nmemb, size, module) calloc_t(nmemb, size, module)
#define FREE(ptr) free_t(ptr)
#define NEW(module) new (module)

#ifdef __cplusplus
extern "C" {
#endif

enum Module {
    OS          = 0,
    APP         = 1,
    OTA         = 2,
    CA          = 3,
    HTTP        = 4,
    MEDIA       = 5,
    RECORDER    = 6,
    SPEEX_LIB   = 7,
    UTILITY     = 8,
    UPNP        = 9,
    MAX_MODULE  = 10,
};

extern void init_heap_info(void);
extern void show_heap_info(void);
extern void* malloc_t(size_t size, enum Module module);
extern void* calloc_t(size_t nmemb, size_t size, enum Module module);
extern void* realloc_t(void* ptr, size_t size, enum Module module);
extern void free_t(void* ptr);

#ifdef __cplusplus
}

void* operator new (std::size_t size, int module);
void* operator new[](std::size_t size, int module);

#endif

#else

#define MALLOC(size, module) malloc(size)
#define REALLOC(ptr, size, module) realloc(ptr, size)
#define CALLOC(nmemb, size, module) calloc(nmemb, size)
#define FREE(ptr) free(ptr)
#define NEW(module) new

#endif  // HEAP_MONITOR

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_HEAP_MONITOR_HEAP_MONITOR_H

