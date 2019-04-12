// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Zhang Guohua (zhangguohua02@baidu.com)
//
// Description: Status report

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_STATUS_REPORTER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_STATUS_REPORTER_H

#include "rtos.h"
#include "baidu_ca_object.h"

namespace duer {

const int REPORT_FUNCTION_MAX = 8;

typedef void (*ReportFunc)(Object&);

class StatusReporter {
public:

    static StatusReporter& obtain();

    // register the data report function
    // Note: only register one time
    //       how to handle register multi-time
    //       how to provide unregister function
    // return:
    //       0 success, -1 fail array is full -2 param report_function is null
    int register_report_function(ReportFunc report_function);

    void start();

    void stop();

    // report the basic info after connect the network success
    void device_info_report();

    // report the status info every 5min
    void device_status_report();

private:

    StatusReporter();

    StatusReporter(const StatusReporter&);

    StatusReporter& operator=(const StatusReporter&);

    // timer for report statistic info about the device periodically
    rtos::RtosTimer     _periodic_report_timer;

    rtos::Mutex _report_functions_mutex;

    ReportFunc _report_functions[REPORT_FUNCTION_MAX];

    volatile int _current_report_function_index;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_STATUS_REPORTER_H

