// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: The APIs for memory management.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_MEMORY_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_MEMORY_H

#include "baidu_ca_types.h"

/*
 * malloc function
 *
 * @Param size, bca_size_t, the expected size of the memory
 * @Return the alloced memory pointer
 */
BCA_INT void* bca_malloc(bca_size_t size);

/*
 * realloc function
 *
 * @Param ptr, void *, the old alloced memory
 * @Param size, bca_size_t, the expected size of the memory
 * @Return the new alloced memory pointer
 */
BCA_INT void* bca_realloc(void* ptr, bca_size_t size);

/*
 * free function
 *
 * @Param ptr, void *, the alloced memory
 */
BCA_INT void bca_free(void* ptr);

/*
 * malloc function
 *
 * @Param size, bca_size_t, the expected size of the memory
 * @Param file, const char *, the file name when alloc the memory
 * @Param line, bca_u32_t, the line number of the file when alloc the memory
 * @Return the alloced memory pointer
 */
BCA_INT void* bca_malloc_ext(bca_size_t size, const char* file, bca_u32_t line);

/*
 * realloc function
 *
 * @Param ptr, void *, the old alloced memory
 * @Param size, bca_size_t, the expected size of the memory
 * @Param file, const char *, the file name when alloc the memory
 * @Param line, bca_u32_t, the line number of the file when alloc the memory
 * @Return the new alloced memory pointer
 */
BCA_INT void* bca_realloc_ext(void* ptr, bca_size_t size, const char* file,
                              bca_u32_t line);

/*
 * free function
 *
 * @Param ptr, void *, the alloced memory
 * @Param file, const char *, the file name when alloc the memory
 * @Param line, bca_u32_t, the line number of the file when alloc the memory
 */
BCA_INT void bca_free_ext(void* ptr, const char* file, bca_u32_t line);

#ifdef BCA_MEMORY_USAGE
BCA_INT void bca_memdbg_usage();
#define BCA_MEMDBG_USAGE(...)       bca_memdbg_usage()
#else
#define BCA_MEMDBG_USAGE(...)
#endif

#ifdef BCA_MEMORY_DEBUG
#define BCA_MALLOC(_s)          bca_malloc_ext(_s, __FILE__, __LINE__)
#define BCA_REALLOC(_p, _s)     bca_realloc_ext(_p, _s, __FILE__, __LINE__)
#define BCA_FREE(_p)            bca_free_ext(_p, __FILE__, __LINE__)
#else/*BCA_MEMORY_DEBUG*/
#define BCA_MALLOC(_s)          bca_malloc(_s)
#define BCA_REALLOC(_p, _s)     bca_realloc(_p, _s)
#define BCA_FREE(_p)            bca_free(_p)
#endif/*BCA_MEMORY_DEBUG*/

#define BCA_CALLOC(_s, _n)      BCA_MALLOC((_s) * (_n))

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SOURCE_BAIDU_CA_MEMORY_H
