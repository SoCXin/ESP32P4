// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Desc: Provide the API for external applications.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_INCLUDE_BAIDU_CA_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_INCLUDE_BAIDU_CA_H

#include "baidu_ca_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * The message codes.
 */
typedef enum {

    // Request message code
    BCA_MSG_REQ_GET                             = 1,
    BCA_MSG_REQ_POST                            = 2,
    BCA_MSG_REQ_PUT                             = 3,
    BCA_MSG_REQ_DELETE                          = 4,

    // Response message code
    BCA_MSG_RSP_CREATED                         = 65,   // 2.01
    BCA_MSG_RSP_DELETED                         = 66,   // 2.02
    BCA_MSG_RSP_VALID                           = 67,   // 2.03
    BCA_MSG_RSP_CHANGED                         = 68,   // 2.04
    BCA_MSG_RSP_CONTENT                         = 69,   // 2.05
    BCA_MSG_RSP_CONTINUE                        = 95,   // 2.31
    BCA_MSG_RSP_BAD_REQUEST                     = 128,  // 4.00
    BCA_MSG_RSP_UNAUTHORIZED                    = 129,  // 4.01
    BCA_MSG_RSP_BAD_OPTION                      = 130,  // 4.02
    BCA_MSG_RSP_FORBIDDEN                       = 131,  // 4.03
    BCA_MSG_RSP_NOT_FOUND                       = 132,  // 4.04
    BCA_MSG_RSP_METHOD_NOT_ALLOWED              = 133,  // 4.05
    BCA_MSG_RSP_NOT_ACCEPTABLE                  = 134,  // 4.06
    BCA_MSG_RSP_REQUEST_ENTITY_INCOMPLETE       = 136,  // 4.08
    BCA_MSG_RSP_PRECONDITION_FAILED             = 140,  // 4.12
    BCA_MSG_RSP_REQUEST_ENTITY_TOO_LARGE        = 141,  // 4.13
    BCA_MSG_RSP_UNSUPPORTED_CONTENT_FORMAT      = 143,  // 4.15
    BCA_MSG_RSP_INTERNAL_SERVER_ERROR           = 160,  // 5.00
    BCA_MSG_RSP_NOT_IMPLEMENTED                 = 161,  // 5.01
    BCA_MSG_RSP_BAD_GATEWAY                     = 162,  // 5.02
    BCA_MSG_RSP_SERVICE_UNAVAILABLE             = 163,  // 5.03
    BCA_MSG_RSP_GATEWAY_TIMEOUT                 = 164,  // 5.04
    BCA_MSG_RSP_PROXYING_NOT_SUPPORTED          = 165,  // 5.05

} bca_msg_code_e;

/**
 * CoAP Message type, used in CoAP Header
 */
typedef enum {
    BCA_MSG_TYPE_CONFIRMABLE       = 0x00, // Reliable Request messages
    BCA_MSG_TYPE_NON_CONFIRMABLE   = 0x10, // Non-reliable Request and Response messages
    BCA_MSG_TYPE_ACKNOWLEDGEMENT   = 0x20, // Response to a Confirmable Request
    BCA_MSG_TYPE_RESET             = 0x30  // Answer a Bad Request
} bca_msg_type_e;

/*
 * The resource operation permission
 */
typedef enum {
    BCA_RES_OP_GET      = 0x01,     // Get operation allowed
    BCA_RES_OP_PUT      = 0x02,     // Put operation allowed
    BCA_RES_OP_POST     = 0x04,     // Post operation allowed
    BCA_RES_OP_DELETE   = 0x08      // Delete operation allowed
} bca_resource_operation_e;

/*
 * The resource mode
 */
typedef enum {
    BCA_RES_MODE_STATIC,            // Static resources have some value that doesn't change
    BCA_RES_MODE_DYNAMIC,           // Dynamic resources are handled in application
} bca_resource_mode_e;

enum _baidu_ca_protocol_enum {
    BCA_PROTO_TCP,
    BCA_PROTO_UDP
};

/*
 * The message definition
 */
typedef struct _bca_message_s {
    bca_u16_t token_len;

    bca_u8_t  msg_type;
    bca_u8_t  msg_code;
    bca_u16_t msg_id;

    bca_u16_t path_len;
    bca_u16_t query_len;
    bca_u16_t payload_len;

    bca_u8_t* token;
    bca_u8_t* path;
    bca_u8_t* query;
    bca_u8_t* payload;
} bca_msg_t;

/*
 * Adapt the memory management functions.
 */
typedef void* (*bca_malloc_f)(bca_context context, bca_size_t size);

typedef void* (*bca_realloc_f)(bca_context context, void*, bca_size_t size);

typedef void (*bca_free_f)(bca_context context, void* p);

/*
 * The network address structure
 */
typedef struct _bca_address_s {
    bca_u8_t    type;       // the socket type
    bca_u16_t   port;       // the host port
    void*       host;       // the host address
    bca_size_t  host_size;  // the host address length
} bca_addr_t;

/*
 * The network transfer data callbacks.
 * See the detail in @{link baidu_ca_transport_init}
 */
typedef void* bca_socket_t;

typedef bca_socket_t (*bca_soc_create_f)(bca_context ctx);

typedef bca_status_t (*bca_soc_connect_f)(bca_socket_t sock,
                                          const bca_addr_t* addr);

typedef bca_status_t (*bca_soc_send_f)(bca_socket_t sock,
                                       const void* data,
                                       bca_size_t size,
                                       const bca_addr_t* addr);

typedef bca_status_t (*bca_soc_recv_f)(bca_socket_t sock,
                                       void* data,
                                       bca_size_t size,
                                       bca_addr_t* addr);

typedef bca_status_t (*bca_soc_recv_timeout_f)(bca_socket_t sock,
                                               void* data,
                                               bca_size_t size,
                                               bca_u32_t timeout,
                                               bca_addr_t* addr);

typedef bca_status_t (*bca_soc_close_f)(bca_socket_t sock);

typedef bca_status_t (*bca_soc_destroy_f)(bca_socket_t sock);

/*
 * The mutex callbacks
 */

typedef void* bca_mutex_t;
typedef bca_mutex_t (*bca_mutex_create_f)();
typedef bca_status_t (*bca_mutex_lock_f)(bca_mutex_t mtx);
typedef bca_status_t (*bca_mutex_unlock_f)(bca_mutex_t mtx);
typedef bca_status_t (*bca_mutex_destroy_f)(bca_mutex_t mtx);

/*
 * The timestamp callbacks
 */

// Return the timestamp by milliseconds
typedef bca_u32_t (*bca_timestamp_f)();

/*
 * The random callbacks
 */

// Return the random number
typedef bca_s32_t (*bca_random_f)();

/*
 * The handler
 */
typedef void* bca_handler;

/*
 * The status notification to user.
 */

typedef bca_status_t (*bca_notify_f)(bca_context ctx,
                                     bca_msg_t* msg,
                                     bca_addr_t* addr);

/*
 * The debug output
 */
typedef void (*bca_debug_f)(bca_context ctx,
                            bca_u32_t level,
                            const char* file,
                            bca_u32_t line,
                            const char* fmt);

/*
 * The resource for user
 */
typedef struct _bca_resource_s {
    bca_u8_t    mode: 2;    // the resource mode, SEE in ${link bca_resource_mode_e}
    bca_u8_t    allowed: 6; // operation permission, SEE in ${link bca_resource_operation_e}
    char*       path;       // the resource path identify

    union {
        bca_notify_f   f_res;   // dynamic resource handle function, NULL if static
        struct {
            void*       data;   // static resource value data, NULL if dynamic
            bca_size_t  size;   // static resource size
        } s_res;
    } res;
} bca_res_t;

/*
 * Set the debug output
 *
 * @Param ctx, bca_context, the debug context for user
 * @Param f_debug, bca_debug_f, the debug output function
 */
BCA_EXT void baidu_ca_debug_init(bca_context ctx, bca_debug_f f_debug);

/*
 * Set the memory management functions.
 *
 * @Param ctx, bca_context, in, the memory context for user
 * @Param f_malloc, bca_malloc_f, the memory alloc function for user
 * @Param f_realloc, bca_realloc_f, the memory realloc function for user,
 * @Param f_free, bca_free_f, the memory free function for user
 *
 * If f_malloc or f_free set to NULL, we will use default libc instead all of it;
 * If only f_realloc set to NULL, we will realized it by f_malloc and f_free.
 */
BCA_EXT void baidu_ca_memory_init(bca_context context,
                                  bca_malloc_f f_malloc,
                                  bca_realloc_f f_realloc,
                                  bca_free_f f_free);

/*
 * Set network input/ouput function
 *
 * @Param f_create, in, the function create socket context
 * @Param f_conn, in, the function connect socket to host
 * @Param f_send, in, the function send message
 * @Param f_recv, in, the function receive message
 * @Param f_recv_timeout, in, the function receive message with timeout
 * @Param f_close, in, the function close the socket
 * @Param f_destroy, in, the function destroy the socket context
 */
BCA_EXT void baidu_ca_transport_init(bca_soc_create_f f_create,
                                     bca_soc_connect_f f_conn,
                                     bca_soc_send_f f_send,
                                     bca_soc_recv_f f_recv,
                                     bca_soc_recv_timeout_f f_recv_timeout,
                                     bca_soc_close_f f_close,
                                     bca_soc_destroy_f f_destroy);

/*
 * Initial the mutex callbacks for Baidu CA
 *
 * @Param f_create, in, the function create mutex context
 * @Param f_lock, in, the function mutex lock
 * @Param f_unlock, in, the function mutex unlock
 * @Param f_destroy, in, the function destroy mutex context
 */
BCA_EXT void baidu_ca_mutex_init(bca_mutex_create_f f_create,
                                 bca_mutex_lock_f f_lock,
                                 bca_mutex_unlock_f f_unlock,
                                 bca_mutex_destroy_f f_destroy);

/*
 * Initial the timestamp callbacks for Baidu CA
 *
 * @Param f_timestamp, in, the function obtain the timestamp
 */
BCA_EXT void baidu_ca_timestamp_init(bca_timestamp_f f_timestamp);

/*
 * Initial the random callbacks for Baidu CA
 *
 * @Param bca_random_f, in, the function random generator function
 */
BCA_EXT void baidu_ca_random_init(bca_random_f f_random);

/*
 * Acquire the handler
 *
 * @Param data, in, the configuration data
 * @Param size, in, the data size
 * @Param soc_ctx, in socket context
 * @Return bca_handler, the global context handler
 */
BCA_EXT bca_handler baidu_ca_acquire(const void* data,
                                     bca_size_t size,
                                     bca_context soc_ctx);

/*
 * Acquire the resources for response
 *
 * @Param hdlr, in, the handler will be operated
 * @Param list_res, in, resource list
 * @Param list_res_size, in resource list length
 * @Return bca_status_t, in, the operation result
 */
BCA_EXT bca_status_t baidu_ca_add_resources(bca_handler hdlr,
                                            const bca_res_t list_res[],
                                            bca_size_t list_res_size);

/*
 * Start run the Baidu CA, prepare the environment.
 *
 * @Param hdlr, in, the handler will be operated
 * @Return bca_status_t, in, the operation result
 */
BCA_EXT bca_status_t baidu_ca_start(bca_handler hdlr);

/*
 * Set the Reporter report response callback.
 *
 * @Param hdlr, in, the handler will be operated
 * @Param f_response, in, the callback for notify user the report data response
 * @Return bca_status_t, in, the operation result
 */
BCA_EXT bca_status_t baidu_ca_report_set_response_callback(bca_handler hdlr,
                                                           bca_notify_f f_response,
                                                           bca_context context);

/*
 * Build the message body that will be reported.
 *
 * @Param hdlr, in, the handler will be operated
 * @Param data, in, the message report data
 * @Param size, in, the data size
 * @Param confirmable, in, the report data QoS
 * @Return bca_msg_t *, in, the generated message body,
 *         it SHOULD be released by ${link baidu_ca_release_message}
 */
BCA_EXT bca_msg_t* baidu_ca_build_report_message(bca_handler hdlr,
                                                 bca_bool confirmable);

/*
 * Build the message body that will be responsed to remote.
 *
 * @Param hdlr, in, the handler will be operated
 * @Param msg, in, the message that remote requested
 * @Param msg_code, out, the response message code
 * @Return bca_msg_t *, in, the generated message body,
 *         it SHOULD be released by ${link baidu_ca_release_message}
 */
BCA_EXT bca_msg_t* baidu_ca_build_response_message(bca_handler hdlr,
                                                   const bca_msg_t* msg,
                                                   bca_u8_t msg_code);

/*
 * Release the message that generated by baidu_ca_build_XXXX_message.
 *
 * @Param hdlr, in, the handler will be operated
 * @Param msg, in, the message that remote requested
 */
BCA_EXT void baidu_ca_release_message(bca_handler hdlr, bca_msg_t* msg);

/*
 * Send the message
 *
 * @Param hdlr, in, the handler will be operated
 * @Param msg, in, the msg will be sent
 * @Param addr, in, the remote addr
 * @Return bca_status_t, in, the operation result
 */
BCA_EXT bca_status_t baidu_ca_send_data(bca_handler hdlr,
                                        const bca_msg_t* msg,
                                        const bca_addr_t* addr);

/*
 * When the message data has ready to be received
 *
 * @Param hdlr, in, the handler will be operated
 * @Param addr, in, the remote addr
 * @Return bca_status_t, in, the operation result
 */
BCA_EXT bca_status_t baidu_ca_data_available(bca_handler hdlr,
                                             const bca_addr_t* addr);

/*
 * Execute the cached CoAP data, such as blockwise, resending...
 *
 * @Param hdlr, in, the handler will be operated
 * @Return bca_status_t, in, the operation result
 */
BCA_EXT bca_status_t baidu_ca_exec(bca_handler hdlr);

/*
 * Stop the Baidu CA.
 *
 * @Param hdlr, in, the handler will be operated
 * @Return bca_status_t, in, the operation result
 */
BCA_EXT bca_status_t baidu_ca_stop(bca_handler hdlr);

/*
 * Release the handler
 *
 * @Param hdlr, in, the handler will be operated
 * @Return bca_status_t, in, the operation result
 */
BCA_EXT bca_status_t baidu_ca_release(bca_handler hdlr);

#ifdef __cplusplus
}
#endif

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_INCLUDE_BAIDU_CA_H
