// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: The common type definitions.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_INCLUDE_BAIDU_CA_TYPES_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_INCLUDE_BAIDU_CA_TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MBED_CLIENT_C_VERSION
#define MBED_CLIENT_C_VERSION (30001) // 3.0.1
#endif

typedef void* bca_context;
typedef int bca_status_t;
typedef unsigned int bca_size_t;
typedef unsigned int bca_u32_t;
typedef unsigned short bca_u16_t;
typedef unsigned char bca_u8_t;
typedef signed int bca_s32_t;

typedef char bca_bool;

enum _baidu_ca_bool_e {
    BCA_FALSE,
    BCA_TRUE
};

// Declaration for local varaible & function.
#define BCA_LOC         static
// Definition for local varaible & function.
#define BCA_LOC_IMPL    static

// Declaration for internal varaible & function.
#define BCA_INT         extern
// Definition for internal varaible & function.
#define BCA_INT_IMPL

// Declaration for external varaible & function.
#define BCA_EXT         extern
// Definition for external varaible & function.
#define BCA_EXT_IMPL

/*
 * The error codes.
 */
typedef enum {
    BCA_NO_ERR,
    BCA_ERR_INTERNAL                = -0x0001,
    BCA_ERR_TRANS_INTERNAL_ERROR    = -0x0030,
    BCA_ERR_TRANS_WOULD_BLOCK       = -0x0031,
    BCA_ERR_TRANS_TIMEOUT           = -0x0032,
    BCA_ERR_REG_FAIL                = -0x0033,

    BCA_ERR_REPORT_FAILED           = -0x070000,
    BCA_ERR_REPORT_FAILED_BEGIN     = BCA_ERR_REPORT_FAILED + 0x10000
} bca_errcode_e;

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_INCLUDE_BAIDU_CA_TYPES_H
