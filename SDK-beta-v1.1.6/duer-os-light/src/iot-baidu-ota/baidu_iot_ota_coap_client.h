// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Duan Lian (duanlian01@baidu.com)
//
// Description: OTA Coap Client

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_COAP_CLIENT_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_COAP_CLIENT_H

#include "baidu_ca.h"
#include "baidu_ca_coap.h"
#include "baidu_ca_network_socket.h"

namespace duer {

class CoapsClient {
public:
    CoapsClient(const char* ip,
            unsigned short port,
            const char* path,
            const char* cert);

    ~CoapsClient();

    int connect();

    int disconnect();

    int get(unsigned int nOffset, unsigned char chBuffer[], unsigned int nSize);

private:
    void network_signal_handler(const bca_addr_t* addr);

    bool _m_b_connected;

    bca_addr_t _m_peer;

    const char* _m_szpath;

    const char* _m_szcert;

    bca_coap_handler _m_coap_instance;

    SocketAdapter::Callback _on_network_data_signal;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_COAP_CLIENT_H
