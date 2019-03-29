// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Chen Xihao (chenxihao@baidu.com)
//
// Description: Media file storer

#ifndef BAIDU_TINYDU_IOT_OS_SRC_MEDIA_DATA_MANAGER_BAIDU_MEDIA_FILE_STORER_H
#define BAIDU_TINYDU_IOT_OS_SRC_MEDIA_DATA_MANAGER_BAIDU_MEDIA_FILE_STORER_H

#include <stdio.h>

namespace duer {

class MediaFileStorer {
public:
    static MediaFileStorer& instance();

    int open(int type);

    int write(const void* buff, size_t size);

    int close();

private:
    MediaFileStorer();

    MediaFileStorer(const MediaFileStorer&);

    MediaFileStorer& operator=(const MediaFileStorer&);

    void initialize();

    static MediaFileStorer _s_instance;
    bool _initialized;
    FILE* _file;
    int _file_index;
};

} // namespace duer

#endif // BAIDU_TINYDU_IOT_OS_SRC_MEDIA_DATA_MANAGER_BAIDU_MEDIA_FILE_STORER_H
