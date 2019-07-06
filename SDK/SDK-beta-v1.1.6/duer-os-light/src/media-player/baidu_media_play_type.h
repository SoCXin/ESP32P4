// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Chen Xihao (chenxihao@baidu.com)
//
// Description: define export type of media module

#ifndef BAIDU_TINYDU_IOT_OS_SRC_MEDIA_PLAYER_BAIDU_MEDIA_PLAY_TYPE_H
#define BAIDU_TINYDU_IOT_OS_SRC_MEDIA_PLAYER_BAIDU_MEDIA_PLAY_TYPE_H

namespace duer {

enum MediaPlayerStatus {
    MEDIA_PLAYER_IDLE,
    MEDIA_PLAYER_PLAYING,
    MEDIA_PLAYER_PAUSE
};

typedef void (*media_player_stop_callback)();

} // namespace duer

#endif // BAIDU_TINYDU_IOT_OS_SRC_MEDIA_PLAYER_BAIDU_MEDIA_PLAY_TYPE_H
