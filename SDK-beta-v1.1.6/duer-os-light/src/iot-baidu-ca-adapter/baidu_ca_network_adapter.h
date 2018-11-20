// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: socket function adapter

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_ADAPTER_BAIDU_CA_NETWORK_ADAPTER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_ADAPTER_BAIDU_CA_NETWORK_ADAPTER_H

#include "baidu_ca.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

bca_socket_t bca_soc_create(bca_context ctx);

bca_status_t bca_soc_connect(bca_socket_t ctx, const bca_addr_t* addr);

bca_status_t bca_soc_send(bca_socket_t ctx,
                          const void* data,
                          bca_size_t size,
                          const bca_addr_t* addr);

bca_status_t bca_soc_recv(bca_socket_t ctx,
                          void* data,
                          bca_size_t size,
                          bca_addr_t* addr);

bca_status_t bca_soc_close(bca_socket_t ctx);

bca_status_t bca_soc_destroy(bca_socket_t ctx);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_ADAPTER_BAIDU_CA_NETWORK_ADAPTER_H
