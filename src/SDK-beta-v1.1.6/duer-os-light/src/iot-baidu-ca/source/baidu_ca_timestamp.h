// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: The timestamp APIs.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_TIMESTAMP_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_TIMESTAMP_H

#include "baidu_ca_types.h"

/*
 * Obtain the system timestamp by milliseconds
 *
 * @Return bca_u32_t, the system timestamp by milliseconds
 */
BCA_INT bca_u32_t bca_timestamp(void);

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_TIMESTAMP_H
