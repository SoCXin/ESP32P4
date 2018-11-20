// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Chen Xihao (chenxihao@baidu.com)
//
// Description: Media type

#ifndef BAIDU_TINYDU_IOT_OS_SRC_MEDIA_BASE_BAIDU_MEDIA_TYPE_H
#define BAIDU_TINYDU_IOT_OS_SRC_MEDIA_BASE_BAIDU_MEDIA_TYPE_H

namespace duer {

enum MediaType {
    TYPE_MP3,
    TYPE_AAC,
    TYPE_M4A,
    TYPE_M4A2,   // continue play m4a
    TYPE_WAV,
    TYPE_SPEECH, // low bit rate mp3
    TYPE_TS,
    TYPE_NULL
};

} // namespace duer

#endif // BAIDU_TINYDU_IOT_OS_SRC_MEDIA_BASE_BAIDU_MEDIA_TYPE_H
