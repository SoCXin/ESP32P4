// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: Define the adapter for networks.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_TRANSPORT_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_TRANSPORT_H

#include "baidu_ca_types.h"
#include "baidu_ca.h"

#define BCA_READ_FOREVER        ((bca_u32_t)-1)

/*
 * The handler operate transfer.
 */
typedef void* bca_trans_handler;

typedef struct _bca_trans_s {
    bca_socket_t ctx;
    bca_context  secure;
    bca_context  soc_context;
    void*        cert;
    bca_size_t   cert_len;
    bca_u32_t    read_timeout;
    bca_addr_t   addr;
} bca_trans_t, *bca_trans_ptr;

/*
 * Acquire the handler.
 *
 * @Param hdlr, in, the global context for baidu ca
 * @Param flag, in, the flag mark the transport properties, see in ${link bca_trans_flag_e}
 * @Param ctx, in, the socket context for user
 * @Return bca_trans_handler, the transport context
 */
BCA_INT bca_trans_handler bca_trans_acquire(bca_context ctx);

/*
 * Set the public key or certificate.
 *
 * @Param hdlr, in, the context for the transport
 * @Param data, in, the content of the public key or certificate
 * @Param size, in, the size of the data
 * @Return bca_status_t, the operation result
 */
BCA_INT bca_status_t bca_trans_set_pk(bca_trans_handler hdlr,
                                      const void* data,
                                      bca_size_t size);

/*
 * Set the timeout for receiving data.
 *
 * @Param hdlr, in, the context for the transport
 * @Param timeout, in, the recv data timeout interval
 * @Return bca_status_t, the operation result
 */
BCA_INT bca_status_t bca_trans_set_read_timeout(bca_trans_handler hdlr,
                                                bca_u32_t timeout);

/*
 * Connect to the host.
 *
 * @Param hdlr, in, the context for the transport
 * @Param addr, in, the target address infomations
 * @Return bca_status_t, the operation result
 */
BCA_INT bca_status_t bca_trans_connect(bca_trans_handler hdlr,
                                       const bca_addr_t* addr);

/*
 * Send data.
 *
 * @Param hdlr, in, the context for the transport
 * @Param data, in, the data will be sent
 * @Param size, in, the data size
 * @Param addr, in, the target address infomations
 * @Return bca_status_t, the operation result
 */
BCA_INT bca_status_t bca_trans_send(bca_trans_handler hdlr,
                                    const void* data,
                                    bca_size_t size,
                                    const bca_addr_t* addr);

/*
 * Receive data.
 *
 * @Param hdlr, in, the context for the transport
 * @Param data, out, the data will be read
 * @Param size, in, the data size
 * @Param addr, out, the target address infomations
 * @Return bca_status_t, the operation result
 */
BCA_INT bca_status_t bca_trans_recv(bca_trans_handler hdlr,
                                    void* data,
                                    bca_size_t size,
                                    bca_addr_t* addr);

/*
 * Disconnect from the remote host.
 *
 * @Param hdlr, in, the context for the transport
 * @Return bca_status_t, the operation result
 */
BCA_INT bca_status_t bca_trans_close(bca_trans_handler hdlr);

/*
 * Release the handler.
 *
 * @Param hdlr, in, the context for the transport
 * @Return bca_status_t, the operation result
 */
BCA_INT bca_status_t bca_trans_release(bca_trans_handler hdlr);

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_TRANSPORT_H
