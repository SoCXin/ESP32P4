// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: Define the encrypted networks I/O.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_TRANS_ENCRYPTED_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_TRANS_ENCRYPTED_H

#include "baidu_ca_transport.h"

/*
 * Connect to the host.
 *
 * @Param hdlr, in, the context for the transport
 * @Param addr, in, the target address infomations
 * @Return bca_status_t, the operation result
 */
BCA_INT bca_status_t bca_trans_encrypted_connect(bca_trans_ptr trans,
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
BCA_INT bca_status_t bca_trans_encrypted_send(bca_trans_ptr trans,
                                              const void* data,
                                              bca_size_t size,
                                              const bca_addr_t* addr);

/*
 * Set the timeout for receiving data.
 *
 * @Param hdlr, in, the context for the transport
 * @Param timeout, in, the recv data timeout interval
 * @Return bca_status_t, the operation result
 */
BCA_INT bca_status_t bca_trans_encrypted_set_read_timeout(bca_trans_ptr trans,
                                                          bca_u32_t timeout);

/*
 * Receive data.
 *
 * @Param hdlr, in, the context for the transport
 * @Param data, out, the data will be read
 * @Param size, in, the data size
 * @Param addr, out, the target address infomations
 * @Return bca_status_t, the operation result
 */
BCA_INT bca_status_t bca_trans_encrypted_recv(bca_trans_ptr trans,
                                              void* data,
                                              bca_size_t size,
                                              bca_addr_t* addr);

/*
 * Disconnect from the remote host.
 *
 * @Param hdlr, in, the context for the transport
 * @Return bca_status_t, the operation result
 */
BCA_INT bca_status_t bca_trans_encrypted_close(bca_trans_ptr trans);

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_TRANS_ENCRYPTED_H
