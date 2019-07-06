// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: The hashcode algorithm

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_HASHCODE_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_HASHCODE_H

#include "baidu_ca_types.h"

/*
 * Generate the hashcode by data
 *
 * @Param data, in, the data will be computed
 * @Param size, in, the data size
 * @Param seed, in, the hash seed
 * @Return bca_u32_t, the hashcode value
 */
BCA_INT bca_u32_t bca_hashcode(const char* data,
                               bca_size_t size,
                               bca_u32_t seed);

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_HASHCODE_H
