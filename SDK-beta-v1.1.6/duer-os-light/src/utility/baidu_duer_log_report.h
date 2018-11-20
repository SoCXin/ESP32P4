// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: tai xiurong (taixiurong@baidu.com)
//
// Description: duer log report to server

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_DUER_LOG_REPORT_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_DUER_LOG_REPORT_H

#include <stddef.h>
#include "rtos.h"
#include "baidu_ca_object.h"

//#define DUROG_REPORT_QUEUE_ENABLE

extern "C" void duer_log_report(const char* tag, const char* format, ...);

namespace duer {
class DuerLogReport {
public:
    /**
     *  @brief  enum for report level
     */
    enum LogReportLevel {
        LOG_E = 1,
        LOG_W,
        LOG_I,
        LOG_D,
        LOG_V,
        LOG_MAX = 20
    };

    
    /**
     *  @brief  DuerLogReport instance
     *  @return DuerLogReport*
     */
    static DuerLogReport* instance();

    /**
     *  @brief  report log use format
     *  @param[in] tag  log's tag
     *  @param[in] tag  log's format
     *  @param[in] ...  log's args
     *  @return[int] if return value >= 0 ,is sucess or else fail
     */
    int report_log_format(const char* tag, const char* format, ...);

    /**
     *  @brief  report log use info
     *  @param[in] tag  log's tag
     *  @param[in] info  log's info
     *  @return[int] if return value >= 0 ,is sucess or else fail
     */
    int report_log_info(const char* tag, const char* info);

    /**
     *  @brief  set report level
     *  @param[in] level  report log's level
     */
    void set_report_level(LogReportLevel level);

    /**
     *  @brief  set report level
     *  @param[in] tag  report log's tag
     *  @return true is can report else can not
     */
    bool is_report_log(const char* tag);

private:
    ~DuerLogReport();

    DuerLogReport();

    DuerLogReport(const DuerLogReport&);

    const DuerLogReport& operator=(const DuerLogReport&);

    int  to_json_and_send(const char* tag, const char* info);

    int send(const Object* obj);
    int send(const void* data, size_t size);

    int get_level_by_tag(const char* tag);
    LogReportLevel _report_level;
#ifdef DUROG_REPORT_QUEUE_ENABLE
    struct ReportData{
        char* info;
        int len;
    };

    const int _max_log_arr_max;

    int _current_log_obj_index;

    rtos::Mutex _report_obj_mutex;
    ReportData* _log_json_string_arr;
#endif

};//DuerLogReport

}//namespace duer

#endif//BAIDU_IOT_TINYDU_IOT_OS_SRC_UTILITY_BAIDU_DUER_LOG_REPORT_H
