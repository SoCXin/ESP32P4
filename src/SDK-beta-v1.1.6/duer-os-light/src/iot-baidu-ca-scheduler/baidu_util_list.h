// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: baidu_util_list

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_UTIL_LIST_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_UTIL_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void* bu_list_t;

typedef enum {
    BU_NO_ERR,
    BU_ERR_UNEXPECTED = -10000,
    BU_ERR_INVALID_PARAMETER,
    BU_ERR_MEMORY_OVERLOW,
    BU_ERR_NODE_EXISTS,
} bu_errors_t;

bu_list_t baidu_util_list_create(void);

int baidu_util_list_append(bu_list_t list, void* data);

int baidu_util_list_is_empty(bu_list_t list);

void* baidu_util_list_get(bu_list_t list, int index);

void* baidu_util_list_remove(bu_list_t list, int index);

int baidu_util_list_destroy(bu_list_t list);

#ifdef __cplusplus
}
#endif

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_UTIL_LIST_H
