// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: Network util tools.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_UTIL_NETWORK_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_UTIL_NETWORK_H

#include "baidu_ca_types.h"

/*
 * Determine whether the system byte order is little endian
 *
 * @Return bca_ut_t, if big endian return 0, else return 1.
 */
BCA_INT bca_u8_t bca_is_little_endian(void);

/*
 * Convert the byte order from host to network for 16bit value
 *
 * @Param value, in, the host value
 * @Param bca_u16_t, the network result
 */
BCA_INT bca_u16_t bca_htons(bca_u16_t value);

/*
 * Convert the byte order from host to network for 32bit value
 *
 * @Param value, in, the host value
 * @Param bca_u32_t, the network result
 */
BCA_INT bca_u32_t bca_htonl(bca_u32_t value);

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_UTIL_NETWORK_H
