// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: The CoAP endpoint definitions.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_COAP_EP_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_COAP_EP_H

#include "baidu_ca_internal.h"

#define LIFETIME_MAX_LEN    (10)

/**
 * Endpoint registration parameters
 */
typedef struct _baidu_ca_coap_endpoint_s {
    char*          name_ptr;           // Endpoint name
    bca_size_t     name_len;

    char*          type_ptr;           // Endpoint type
    bca_size_t     type_len;

    char*          lifetime_ptr;       // Endpoint lifetime in seconds. eg. "1200" = 1200 seconds
    bca_size_t     lifetime_len;

    bca_addr_t*    address; // Endpoint address to be accessed by the server, optional, default NULL
} bca_coap_ep_t, *bca_coap_ep_ptr;

/*
 * Create the endpoint.
 *
 * @Param hdlr, in, the global context for baidu ca
 * @Param name, in, the endpoint name
 * @Param type, in, the endpoint type
 * @Param lifetime, in, the lifetime of the endpoint
 * @Param addr, in, the endpoint address to be accessed by the server, optional, default NULL
 * @Return bca_coap_ep_ptr, the endpoint context pointer
 */
BCA_INT bca_coap_ep_ptr bca_coap_ep_create(const char* name,
                                           const char* type,
                                           bca_u32_t lifetime,
                                           const bca_addr_t* addr);


/*
 * Destroy the endpoint that created by ${link bca_coap_ep_create}.
 *
 * @Param hdlr, in, the global context for baidu ca
 * @Param ptr, in, the endpoint context pointer
 * @Return bca_status_t, the operation result
 */
BCA_INT bca_status_t bca_coap_ep_destroy(bca_coap_ep_ptr ptr);

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_COAP_EP_H
