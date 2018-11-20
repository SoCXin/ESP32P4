// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Chen Xihao (chenxihao@baidu.com)
//
// Description: Media Manager

#ifndef BAIDU_TINYDU_IOT_OS_SRC_MEDIA_DATA_MANAGER_BAIDU_MEDIA_MANAGER_H
#define BAIDU_TINYDU_IOT_OS_SRC_MEDIA_DATA_MANAGER_BAIDU_MEDIA_MANAGER_H

#include <stddef.h>
#include "baidu_media_play_type.h"

namespace duer {

class MediaManager {
public:
    static MediaManager& instance();

    /*
     * Initialize MediaManager object.
     *
     * @Return bool, success: true, fail: false
     */
    bool initialize();

    /*
     * Initialize MediaManager object by buffer .
     *
     * @Param buffer, buffer for media data
     * @Param size, size of buffer
     * @Return bool, success: true, fail: false
     */
    bool initialize(void* buffer, size_t size);

    /*
     * Play network media file
     *
     * @Param url, media file's url
     * @param[in] is_speech, indicate the url data is speech or not
     * @param[in] is_continue_previous, whether continue play previous music
     *      after this url play end
     * @Return MediaPlayerStatus, the last status of media player
     */
    MediaPlayerStatus play_url(const char* url, bool is_speech, bool is_continue_previous);

    /*
     * Play local media file
     *
     * @Param path, media file's path
     * @Return MediaPlayerStatus, the last status of media player
     */
    MediaPlayerStatus play_local(const char* path);

    /*
     * If media player's status is playing/pause, pause/resume it
     *
     * @Return MediaPlayerStatus, the last status of media player
     */
    MediaPlayerStatus pause_or_resume();

    /*
     * Stop media player
     *
     * @Return MediaPlayerStatus, the last status of media player
     */
    MediaPlayerStatus stop();

    /*
     * Get status of media player
     *
     * @Return MediaPlayerStatus, the current status of media player
     */
    MediaPlayerStatus get_media_player_status();

    /*
     * Register the callback function which is called when media player stop
     * Can't register more than 5 function
     *
     * @Param callback, callback function
     * @Return int, success: 0, fail: -1
     */
    int register_stop_callback(media_player_stop_callback callback);

    /*
     * Unregister the callback function
     *
     * @Param callback, callback function
     * @Return int, success: 0, fail: -1
     */
    int unregister_stop_callback(media_player_stop_callback callback);

    /*
     * Set volume of audio
     *
     * @Param vol, effective range is 0~15
     */
    void set_volume(unsigned char vol);

    /*
     * Get http download progress
     *
     * PARAM:
     * @param[out] total_size: to receive the total size to be download
     *                         if chunked Transfer-Encoding is used, we cannot know the total size
     *                         untile download finished, in this case the total size will be 0
     * @param[out] recv_size:  to receive the data size have been download
     *
     * @return     none
     */
    void get_download_progress(size_t* total_size, size_t* recv_size);

    /*
     * Seek media file playing now
     *
     * PARAM:
     * @param[in] offset, seek offset to current postion
     */
    void seek(int offset);

private:
    MediaManager();

    static MediaManager _s_instance;
    static bool _s_initialized;
};

} // namespace duer

#endif // BAIDU_TINYDU_IOT_OS_SRC_MEDIA_DATA_MANAGER_BAIDU_MEDIA_MANAGER_H
