// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Zhang Leliang (zhangleliang@baidu.com)
//
// Description: baidu common used timer

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_COMMON_TIMER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_COMMON_TIMER_H

#include "baidu_timer_interface.h"
#include "baidu_iot_mutex.h"

namespace duer {
/**
 * The common used timer
 */
class BaiduCommonTimer {
public:
    class ChildrenPuzzleSilentTimerArgument {
    public:
        ChildrenPuzzleSilentTimerArgument(const char* argument);
        ~ChildrenPuzzleSilentTimerArgument();

        const char* get_resource() const;
    private:
        const char* _resource;
    };

    /**
     * create the children_puzzle_silent_timer
     * @param interval the interval to invoke the callback, in milli-second
     * @param priv_data the private data use in the callback, will be free when destroy the timer
     *        priv_data is string as below
     *      {"data":{"query":"ai.dueros.puzzle.timeout","timeout":30},"type":"children_puzzle_ref"}
     * @return >0 OK, <0 fail
     */
    static int create_s_children_puzzle_silent_timer(int interval, void* priv_data);
    /**
     * start the children_puzzle_silent_timer
     */
    static int start_s_children_puzzle_silent_timer();
    /**
     * stop the children_puzzle_silent_timer
     */
    static int stop_s_children_puzzle_silent_timer();
    /**
     * stop the children_puzzle_silent_timer
     */
    static void audio_play_stop_call_back();

private:
    // forbid to create
    BaiduCommonTimer();
    ~BaiduCommonTimer();

    // release the priv_data for children puzzle silent timer
    static void release_children_puzzle_silent_timer_priv_data(void* argument);
    // this callback used in puzzle, timeout
    static void children_puzzle_silent_timer_callback(void* argument);

    // timer used in puzzle
    static volatile baidu_timer_t _s_children_puzzle_silent_timer;
    static volatile iot_mutex_t _s_children_puzzle_silent_timer_mutex;
};

} // namespace duer


#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_COMMON_TIMER_H
