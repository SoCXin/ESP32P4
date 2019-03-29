// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Chen Xihao (chenxihao@baidu.com)
//
// Description: Media player API

#ifndef BAIDU_TINYDU_IOT_OS_SRC_MEDIA_PLAYER_BAIDU_MEDIA_PLAY_H
#define BAIDU_TINYDU_IOT_OS_SRC_MEDIA_PLAYER_BAIDU_MEDIA_PLAY_H

#include "baidu_media_play_type.h"
#include "baidu_media_type.h"
#include "baidu_media_play_buffer.h"

namespace duer {

enum MediaPlayerCmd {
    PLAYER_CMD_START,       //to start playing media
    PLAYER_CMD_CONTINUE,    //media data stream
    PLAYER_CMD_STOP         //to stop mediaplayer
};

struct MediaPlayerMessage {
    MediaPlayerCmd cmd;     //command to mediaplayer
    MediaType type;
    int size;               //data size in MediaPlayBuffer
};

void start_media_play_thread();
void start_media_voice_thread();
// return last status of media player
MediaPlayerStatus media_play_pause_or_resume();
MediaPlayerStatus media_play_stop();
MediaPlayerStatus media_play_get_status();
int media_play_register_stop_callback(media_player_stop_callback callback);
int media_play_unregister_stop_callback(media_player_stop_callback callback);
void media_play_set_volume(unsigned char vol);
int media_play_get_write_size();
int media_play_seek_m4a_file(int position);

extern MediaPlayBuffer* g_media_play_buffer;

} // namespace duer

#endif // BAIDU_TINYDU_IOT_OS_SRC_MEDIA_PLAYER_BAIDU_MEDIA_PLAY_H
