// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: The CoAP adapter.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_COAP_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_COAP_H

#include "baidu_ca_coap_ep.h"

typedef void* bca_coap_handler;

typedef bca_status_t (*bca_coap_result_f)(bca_context ctx,
                                          bca_coap_handler hdlr,
                                          const bca_msg_t* msg,
                                          const bca_addr_t* addr);

#define BCA_COAP_MESSAGE_ID_INVALID     (0)

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Acquire the coap handler.
 *
 * @Param f_result, in, the callback for user handling events
 * @Param context, in, the user context for f_result callback
 * @Param ctx_context, in, the user socket context
 * @Return bca_coap_handler, the coap context
 */
BCA_INT bca_coap_handler bca_coap_acquire(bca_coap_result_f f_result,
                                          bca_context context,
                                          bca_context ctx_context);

/*
 * Connect to remote CoAP server
 *
 * @Param hdlr, in, the CoAP context
 * @Param addr, in, the remote server address
 * @Param data, in, the security suite data
 * @Param size, in, the data size
 * @Return bca_status_t, the connect status
 */
BCA_INT bca_status_t bca_coap_connect(bca_coap_handler hdlr,
                                      const bca_addr_t* addr,
                                      const void* data,
                                      bca_size_t size);

/*
 * Disconnect from remote CoAP server
 *
 * @Param hdlr, in, the CoAP context
 * @Return bca_status_t, the connect status
 */
BCA_INT bca_status_t bca_coap_disconnect(bca_coap_handler hdlr);

/*
 * Add the resource for CoAP request from other endpoints
 *
 * @Param hdlr, in, the CoAP context
 * @Param res, in, the resource information
 * @Return bca_status_t, the result
 */
BCA_INT bca_status_t bca_coap_resource_add(bca_coap_handler hdlr,
                                           const bca_res_t* res);

/*
 * Remove the resource for CoAP request from other endpoints
 *
 * @Param hdlr, in, the CoAP context
 * @Param path, in, the resource path
 * @Return bca_status_t, the result
 */
BCA_INT bca_status_t bca_coap_resource_remove(bca_coap_handler coap,
                                              const char* path);

/*
 * Register endpoint by LWM2M
 *
 * @Param hdlr, in, the CoAP context
 * @Param ep, in, the endpoint information
 * @Return bca_status_t, if > 0, the result is the register message id, else is the error status
 */
BCA_INT bca_status_t bca_coap_register(bca_coap_handler coap,
                                       const bca_coap_ep_t* ep);

/*
 * Unregister the endpoint by LWM2M
 *
 * @Param hdlr, in, the CoAP context
 * @Return bca_status_t, if > 0, the result is the unregister message id, else is the error status
 */
BCA_INT bca_status_t bca_coap_unregister(bca_coap_handler coap);

/*
 * Update registration by LWM2M
 *
 * @Param hdlr, in, the CoAP context
 * @Param lifetime, in, the endpoint lifetime
 * @Return bca_status_t, if > 0, the result is the update registration message id,
 *                       else is the error status
 */
BCA_INT bca_status_t bca_coap_update_registration(bca_coap_handler coap,
                                                  bca_u32_t lifetime);

/*
 * Send the CoAP message
 *
 * @Param hdlr, in, the CoAP context
 * @Param msg, in, the CoAP message
 * @Return bca_status_t, the result
 */
BCA_INT bca_status_t bca_coap_send(bca_coap_handler coap, const bca_msg_t* msg);

/*
 * Receive the CoAP message
 *
 * @Param hdlr, in, the CoAP context
 * @Return bca_status_t, the result
 */
BCA_INT bca_status_t bca_coap_data_available(bca_coap_handler coap);

/*
 * Execute the cached CoAP data
 *
 * @Param hdlr, in, the CoAP context
 * @Param timestamp, in, the timestamp for mark the message
 * @Return bca_status_t, the result
 */
BCA_INT bca_status_t bca_coap_exec(bca_coap_handler hdlr, bca_u32_t timestamp);

/*
 * Release the CoAP context
 *
 * @Param hdlr, in, the CoAP context
 * @Return bca_status_t, the result
 */
BCA_INT bca_status_t bca_coap_release(bca_coap_handler coap);

/*
 * Set read timeout
 *
 * @Param hdlr, in, the CoAP context
 * @Param timeout, in, the timeout value by milliseconds
 * @Return bca_bool, if match return BCA_TRUE, else return BCA_FALSE
 */
BCA_INT bca_status_t bca_coap_set_read_timeout(bca_coap_handler coap, bca_u32_t timeout);

#ifdef __cplusplus
}
#endif

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_COAP_H
