// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Chen Xihao (chenxihao@baidu.com)
//
// Description: Media data Manager

#ifndef BAIDU_TINYDU_IOT_OS_SRC_MEDIA_DATA_MANAGER_BAIDU_MEDIA_DATA_MANAGER_H
#define BAIDU_TINYDU_IOT_OS_SRC_MEDIA_DATA_MANAGER_BAIDU_MEDIA_DATA_MANAGER_H

#include <stddef.h>
#include "baidu_media_play_type.h"

namespace duer {

struct MediaReport {
    unsigned int play_url_count;
    unsigned int invalid_url_count;
    unsigned int play_url_failed_count;
};

void mdm_send_media_file_path(const char* media_file_path);

void mdm_send_media_url(const char* media_url, bool is_speech, bool is_continue_previous);

MediaPlayerStatus mdm_notify_to_stop();

void mdm_reset_stop_flag();

int mdm_check_need_to_stop();

const MediaReport& get_media_report();

void start_media_data_mgr_thread();

void mdm_speed_get_statistic(float* speed);

void mdm_get_download_progress(size_t* total_size, size_t* recv_size);

void mdm_seek_media(int offset);

} // namespace duer

#endif // BAIDU_TINYDU_IOT_OS_SRC_MEDIA_DATA_MANAGER_BAIDU_MEDIA_DATA_MANAGER_H
