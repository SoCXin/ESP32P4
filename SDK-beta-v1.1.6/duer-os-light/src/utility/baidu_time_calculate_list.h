// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Zhang Guohua (zhangguohua02@baidu.com)
//
// Description: Time calculate list

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_TIME_CALCULATE_LIST_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_TIME_CALCULATE_LIST_H

#include "baidu_measure_time_list.h"

#define TIME_BEGIN(key) do{\
	duer::MeasureTimeList::getInstMeasureTime(time_current_get)->addMeasureValue(key);\
}while(0)

#define TIME_END(key, argument) do{\
	duer::MeasureTimeList::getInstMeasureTime(time_current_get)->updateMeasureValue(key, argument);\
}while(0)

#define TIME_RESULT() do{\
	duer::MeasureTimeList::getInstMeasureTime(time_current_get)->outputResult();\
}while(0)

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_TIME_CALCULATE_LIST_H

