// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: Wrapper for mutex

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_MUTEX_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_MUTEX_H

#include "baidu_ca_types.h"
#include "baidu_ca.h"

/*
 * Create mutex context
 *
 * @Return bca_mutex_t, the created mutex context
 */
BCA_INT bca_mutex_t bca_mutex_create(void);

/*
 * Mutex lock
 *
 * @Return bca_mutex_t, the mutex context
 */
BCA_INT bca_status_t bca_mutex_lock(bca_mutex_t mutex);

/*
 * Mutex unlock
 *
 * @Return bca_mutex_t, the mutex context
 */
BCA_INT bca_status_t bca_mutex_unlock(bca_mutex_t mutex);

/*
 * Destroy the mutex context
 *
 * @Return bca_mutex_t, the mutex context
 */
BCA_INT bca_status_t bca_mutex_destroy(bca_mutex_t mutex);

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_MUTEX_H
