// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Gang Chen (chengang12@baidu.com)
//
// Description: This header file is wrapper for OS mutex

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_MUTEX_BAIDU_IOT_MUTEX_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_MUTEX_BAIDU_IOT_MUTEX_H

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void* iot_mutex_t;

typedef enum {
    IOT_MUTEX_OK = 0,       // function completed; no error or event occurred.
    IOT_MUTEX_TIMEOUT,	    // Failed to lock mutex in specified time
    IOT_MUTEX_ERROR,
} iot_mutex_status;

/*
 * Create mutex
 *
 * @Return: the created mutex's pointer
 */
iot_mutex_t iot_mutex_create(void);

/*
 * Lock a mutex
 *
 * @param mutex[in]: a pointer point to the mutex
 * @param timeout_ms[in]: timeout value or 0 in case of no time-out
 *
 * @Return: iot_mutex_status
 */
iot_mutex_status iot_mutex_lock(iot_mutex_t mutex, uint32_t timeout_ms);

/*
 * Try to lock a mutex, and return immediately
 *
 * @param mutex[in]: a pointer point to the mutex
 *
 * @return: true if the mutex was acquired, false otherwise.
 */
bool iot_mutex_try_lock(iot_mutex_t mutex);

/*
 * Unlock a mutex
 *
 * @param mutex[in]: a pointer point to the mutex
 *
 * @Return: iot_mutex_status
 */
iot_mutex_status iot_mutex_unlock(iot_mutex_t mutex);

/*
 * Destroy the mutex context
 *
 * @param mutex[in]: a pointer point to the mutex
 *
 * @Return: iot_mutex_status
 */
iot_mutex_status iot_mutex_destroy(iot_mutex_t mutex);

#ifdef __cplusplus
}
#endif

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_MUTEX_BAIDU_IOT_MUTEX_H

