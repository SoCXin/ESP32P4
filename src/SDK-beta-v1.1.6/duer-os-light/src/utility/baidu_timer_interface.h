// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Zhang Leliang (zhangleliang@baidu.com)
//
// Description: baidu timer interface

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_TIMER_INTERFACE_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_TIMER_INTERFACE_H

#ifdef __cplusplus
extern "C" {
#endif

// the type of timer
typedef enum {
    TIMER_TYPE_ONCE = 1,
    TIMER_TYPE_PERIODIC
} baidu_timer_type;

// the return value of the timer API
typedef enum {
    TIMER_RET_INVALID_PARAM = -1,  // invalid input parameter
    TIMER_RET_INTERNAL_ERR  = -2,  // internal error
    TIMER_RET_OK = 0,
} baidu_timer_ret_value;

typedef void* baidu_timer_t;

typedef void (*baidu_timer_callback)(void* argument);
typedef void (*baidu_timer_release_priv_data)(void* argument);

/**
 * create a baidu_timer
 * @param timer_callback: the callback function
 * @param timer_priv_data_release: priv_data release function, if NULL free will be used
 * @param timer_type: the timer type, periodic or one-shot
 * @priv_data: the argument will transfer to the callback function
 *            the lifecycle will be end in the baidu_timer_destroy
 * @interval: the interval to call the callback function in milli-second
 * @return the new create baidu_timer or NULL if error happen
 */
extern baidu_timer_t baidu_timer_create(baidu_timer_callback timer_callback,
                                        baidu_timer_release_priv_data timer_priv_data_release,
                                        baidu_timer_type timer_type,
                                        void* priv_data,
                                        int interval);

/**
 * start the timer
 * @param timer: the baidu_timer
 * @return TIMER_RET_OK if success,
 *         TIMER_RET_INTERNAL_ERR, TIMER_RET_INVALID_PARAM when error
 */
extern int baidu_timer_start(baidu_timer_t timer);

/**
 * stop the timer
 * @param timer: the baidu_timer
 * @return TIMER_RET_OK if success,
 *         TIMER_RET_INTERNAL_ERR, TIMER_RET_INVALID_PARAM when error
 */
extern int baidu_timer_stop(baidu_timer_t timer);

/**
 * destroy the timer, release the resource
 * @param timer: the baidu_timer
 * @return TIMER_RET_OK if success,
 *         TIMER_RET_INTERNAL_ERR, TIMER_RET_INVALID_PARAM when error
 */
extern int baidu_timer_destroy(baidu_timer_t timer);

#ifdef __cplusplus
}
#endif

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_TIMER_INTERFACE_H
