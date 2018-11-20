// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Zhang Guohua (zhangguohua02@baidu.com)
//
// Description: Measure time utility

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_MEASURE_TIME_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_MEASURE_TIME_H

#include "us_ticker_api.h"
#include "baidu_time_calculate.h"

#define ArraySize PERFORM_STATISTIC_WATCH_POINT_NUM

namespace duer {

struct MeasureValue {
    unsigned int total_cnt;
    unsigned int cur_cnt;
    unsigned int time_begin;
    unsigned int time_sum;
    unsigned int time_min;
    unsigned int time_max;
    unsigned int arg_value;
};

typedef unsigned int (*TimeFuncPtr)(void);

// this class is not thread-safe
class MeasureTime {
public:
    static MeasureTime* getInstMeasureTime(TimeFuncPtr time_func);
    void addMeasureValue(int key, int count);
    void updateMeasureValue(int key, int arg_value, int continuous_measure_flag);
    void outputResult();

private:
    MeasureTime(TimeFuncPtr time_func);
    MeasureTime(const MeasureTime&);
    MeasureTime& operator=(const MeasureTime&);

    static MeasureTime* _s_instance;
    static TimeFuncPtr _s_time_func;
    MeasureValue _MeasureArray[ArraySize];
};

} //namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_MEASURE_TIME_H

