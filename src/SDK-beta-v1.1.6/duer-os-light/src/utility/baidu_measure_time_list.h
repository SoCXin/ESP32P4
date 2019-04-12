// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Zhang Guohua (zhangguohua02@baidu.com)
//
// Description: Measure time list

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_MEASURE_TIME_LIST_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_MEASURE_TIME_LIST_H

#include <stdio.h>
#include <string>
#include <map>

int time_current_get(void);

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

typedef struct __ListNode {
    __ListNode* next;
    //char* Key;
    std::string Key;
    MeasureValue Value;
} ListNode;

typedef int (*TimeFuncPtr)(void);

// this class is not thread-safe
class MeasureTimeList {
public:
    static MeasureTimeList* getInstMeasureTime(TimeFuncPtr time_func);
    //void addMeasureValue(const char* key, int count, int arg_value);
    void addMeasureValue(const char* key, unsigned int count);
    //void updateMeasureValue(const char* key);
    void updateMeasureValue(const char* key, unsigned arg_value);
    void outputResult();
    void destoryMeasureValueList();

private:
    MeasureTimeList(TimeFuncPtr time_func);
    MeasureTimeList(const MeasureTimeList&);
    MeasureTimeList& operator=(const MeasureTimeList&);
    bool searchMeasureValueByKey(const char* key, ListNode* &temp);

    static MeasureTimeList* _s_instance;
    static TimeFuncPtr _s_time_func;
    ListNode* _pListHead;
    ListNode* _pListTail;
    //	map<const char *, MeasureValue> _map_value;
};

} //namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_MEASURE_TIME_LIST_H

