// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Chang Li (changli@baidu.com)
//
// Description: miniupnprender header file.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_MINIRENDER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_MINIRENDER_H

#ifdef __cplusplus
extern "C" {
#endif

void set_uuid(const char* uuid);

void set_friendly_name(const char* name); 

int upnp_test(const char* host_ip, const char* host_mac);

#ifdef __cplusplus
}
#endif

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_MINIUPNPRENDER_MINIRENDER_H

