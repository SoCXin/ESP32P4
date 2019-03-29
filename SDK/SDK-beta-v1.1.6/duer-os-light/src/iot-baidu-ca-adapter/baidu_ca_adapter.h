// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: ca adapter initialize function

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_ADAPTER_BAIDU_CA_ADAPTER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_ADAPTER_BAIDU_CA_ADAPTER_H

#include "baidu_ca.h"

#ifdef __cplusplus
extern "C" {
#endif

void baidu_ca_initialize(void);

int baidu_ca_is_initialized(void);

void bca_sleep(bca_u32_t ms);

#ifdef __cplusplus
}
#endif

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_ADAPTER_BAIDU_CA_ADAPTER_H
