// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: Baidu CA configuration.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_CONF_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_CONF_H

#include "baidu_ca_types.h"

typedef void* bca_conf_handler;

/*
 * Create the configuation from buffer
 *
 * @Param data, in, the configuation stream
 * @Param size, in, the data size
 * @Return bca_conf_handler, the handler for operating the configuation
 */
BCA_INT bca_conf_handler bca_conf_create(const void* data, bca_size_t size);

/*
 * Get the string from the configuration by the key
 *
 * @Param hdlr, in, the handler for configuation
 * @Param key, in, the key of the item
 * @Return const char *, the string value of the key
 */
BCA_INT const char* bca_conf_get_string(bca_conf_handler hdlr, const char* key);

/*
 * Get the unsigned short from the configuration by the key
 *
 * @Param hdlr, in, the handler for configuation
 * @Param key, in, the key of the item
 * @Return bca_u16_t, the unsigned short value of the key
 */
BCA_INT bca_u16_t bca_conf_get_ushort(bca_conf_handler hdlr, const char* key);

/*
 * Get the unsigned int from the configuration by the key
 *
 * @Param hdlr, in, the handler for configuation
 * @Param key, in, the key of the item
 * @Return bca_u32_t, the unsigned int value of the key
 */
BCA_INT bca_u32_t bca_conf_get_uint(bca_conf_handler hdlr, const char* key);

/*
 * Get the string from the configuration by the key
 *
 * @Param hdlr, in, the handler for configuation
 */
BCA_INT void bca_conf_destroy(bca_conf_handler hdlr);

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_CONF_H
