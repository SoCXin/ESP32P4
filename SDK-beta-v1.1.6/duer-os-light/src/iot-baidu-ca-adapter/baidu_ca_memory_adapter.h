// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: memory function adapter

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_ADAPTER_BAIDU_CA_MEMORY_ADAPTER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_ADAPTER_BAIDU_CA_MEMORY_ADAPTER_H

#include "baidu_ca.h"

#ifdef __cplusplus
extern "C" {
#endif

void* bca_memory_alloc(bca_context ctx, bca_size_t size);

void* bca_memory_realloc(bca_context ctx, void* ptr, bca_size_t size);

void bca_memory_free(bca_context ctx, void* ptr);

#ifdef __cplusplus
}
#endif

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_ADAPTER_BAIDU_CA_MEMORY_ADAPTER_H
