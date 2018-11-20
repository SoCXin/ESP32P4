// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Li Chang (changli@baidu.com)
//
// Description: Media Manager adpter for C caller


#ifndef BAIDU_TINYDU_IOT_OS_SRC_MEDIA_DATA_MANAGER_BAIDU_MEDIA_MANAGER_ADAPTER_H
#define BAIDU_TINYDU_IOT_OS_SRC_MEDIA_DATA_MANAGER_BAIDU_MEDIA_MANAGER_ADAPTER_H

#ifdef __cplusplus
extern "C" {
#endif

void timer_start();

void timer_stop();

void timer_reset();

unsigned int timer_read();

void media_play_url(const char* url);

void media_pause_url();

void media_stop_url();


#ifdef __cplusplus
}
#endif

#endif // BAIDU_TINYDU_IOT_OS_SRC_MEDIA_DATA_MANAGER_BAIDU_MEDIA_MANAGER_ADAPTER_H

