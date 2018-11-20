// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: SocketAdapter

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_ADAPTER_BAIDU_CA_NETWORK_SOCKET_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_ADAPTER_BAIDU_CA_NETWORK_SOCKET_H

#include "mbed.h"
#include "baidu_ca.h"

namespace duer {

class SocketAdapter {
public:

    typedef mbed::Callback<void (const bca_addr_t*)> Callback;

    SocketAdapter();

    virtual ~SocketAdapter();

    int connect(const bca_addr_t* addr);

    int send(const void* data, size_t size);

    int recv(void* data, size_t size);

    int close();

    void attach(Callback callback);

    template <typename T, typename M>
    void attach(T* obj, M method) {
        attach(Callback(obj, method));
    }

    static void set_network_interface(NetworkInterface* ifc);

    static NetworkInterface* get_network_interface();

    // the unit of speed is k/s
    static void bca_coap_get_statistic(float* upload_speed, float* download_speed);
private:

    void on_read();

    Socket*    _socket;
    bca_addr_t _addr;
    Callback   _callback;

    static NetworkInterface* _s_interface;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_ADAPTER_BAIDU_CA_NETWORK_SOCKET_H
