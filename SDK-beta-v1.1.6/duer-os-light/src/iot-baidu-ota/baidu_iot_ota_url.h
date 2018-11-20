// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Duan Lian (duanlian01@baidu.com)
//
// Description: OTA URL

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_URL_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_URL_H

namespace duer {

class URL {
public:
    URL(const char* url);

    ~URL();

    bool valid() const {
        return _valid;
    };

    const char* scheme() const {
        return _scheme;
    };

    const char* host() const {
        return _host;
    };

    unsigned short port() const {
        return _port;
    };

    const char* path() const {
        return _path;
    };

    const char* url() const {
        return _url;
    };
private:
    bool parse(const char* url);

    bool _valid;

    char* _scheme;

    char* _host;

    char* _path;

    char* _url;

    unsigned short _port;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_URL_H
