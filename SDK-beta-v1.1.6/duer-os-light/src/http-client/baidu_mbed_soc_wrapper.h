// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Pan Haijun, Gang Chen(chengang12@baidu.com)
//
// This header file provide the wrapper of the socket APIs for http module.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_HTTP_CLIENT_BAIDU_MBED_SOC_WRAPPER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_HTTP_CLIENT_BAIDU_MBED_SOC_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif
int mbed_socket_init(void* socket_args);
int mbed_socket_open(int socket_handle);
int mbed_socket_connect(int socket_handle, const char* host, const int port);
void mbed_socket_set_blocking(int socket_handle, int blocking);
void mbed_socket_set_timeout(int socket_handle, int timeout);
int mbed_socket_recv(int socket_handle, void* data, unsigned size);
int mbed_socket_send(int socket_handle, const void* data, unsigned size);
int mbed_socket_close(int socket_handle);
void mbed_socket_destroy(int socket_handle);

#ifdef __cplusplus
}
#endif

#endif//BAIDU_IOT_TINYDU_IOT_OS_SRC_HTTP_CLIENT_BAIDU_MBED_SOC_WRAPPER_H

