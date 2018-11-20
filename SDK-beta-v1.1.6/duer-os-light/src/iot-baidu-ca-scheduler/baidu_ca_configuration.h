// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description:　Configuration

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_CONFIGURATION_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_CONFIGURATION_H

#include "baidu_ca_types.h"

namespace duer {

class Configuration {
public:

    Configuration();

    virtual ~Configuration();

    virtual const void* get_data() const;

    virtual bca_size_t get_size() const;

private:

    const void*     _data;
    bca_size_t      _size;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_CONFIGURATION_H
