// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: Scheduler

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_SCHEDULER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_SCHEDULER_H

#include "rtos.h"
#include "baidu_ca.h"
#include "baidu_ca_handler.h"
#include "baidu_ca_network_socket.h"
#include "baidu_util_list.h"
#include "baidu_ca_object.h"
#include "duer_play_command.h"

namespace duer
{

class Scheduler : public Handler::OnMessageListener
{
public:

    friend class PlayCommand;

    /**
     * @brief Scheduler callback interface of event
     */
    class IOnEvent
    {
    public:
        /**
         * @brief Scheduler callback when start
         */
        virtual int on_start() = 0;
        /**
         * @brief Scheduler callback when stop
         */
        virtual int on_stop() = 0;
        /**
         * @brief Scheduler callback when play url coming in
         * @param[in] url the url get from device cloud
         * @param[in] is_speech indicate the url data is speech or not
         * @param[in] is_continue_previous whether continue play previous music
         *      after this url play end
         */
        virtual int on_action(const char* url, bool is_speech, bool is_continue_previous) = 0;
        /**
         * @brief Scheduler callback when data coming in
         * @param[in] data jason style，including the data from device cloud
         */
        virtual int on_data(const char* data) = 0;
    };
    /**
     * @brief get Scheduler single instance
     */
    static Scheduler& instance();
    /**
     * @brief set the event callback interface for Scheduler
     * @param[in] listener for enent callback
     * @return 0
     */
    int set_on_event_listener(IOnEvent* listener);
    /**
     * @brief add control point
     * @param[in] list_res array of control points will be registed
     * @param[in] list_res_size the length of the array
     * @return 0
     */
    int add_controll_points(const bca_res_t list_res[], bca_size_t list_res_size);
    /**
     * @brief start Scheduler
     * @return 0
     */
    int start();
    /**
     * @brief stop Scheduler
     * @return 0
     */
    int stop();
    /**
     * @brief report data in json style
     * @param[in] data the json container
     * @return 0
     */
    int report(const Object& data);
    /**
     * @brief report data in json style
     * @param[in] data the baidu_json object
     * @return 0
     */
    int report(baidu_json *data);
    /**
     * @brief report data in json style
     * @param[in] data json data
     * @param[in] size the length of the data
     * @return 0
     */
    int report(const void* data, size_t size);
    /**
     * @brief response to the request
     * @param[in] req the request message
     * @param[in] msg_code response code
     * @param[in] payload response content
     * @return 0
     */
    int response(const bca_msg_t* req, int msg_code, const char* payload);
    /**
     * @brief report the voice data
     * @param[in] data voice data
     * @param[in] size the length of the voice data
     * @param[in] eof  whether the last voice data
     * @return 0
     */
    int send_content(const void* data, size_t size, bool eof);
    /**
     * @brief clear all the data in send buffer
     * @return 0
     */
    int clear_content();
    /**
     * @brief the callback interface of Handler
     * @param[in] message which waiting for handling
     * @return true
     */
    virtual bool on_message(Message& message);

    void report_close_multi_dialog();

private:

    Scheduler();

    virtual ~Scheduler();

    void data_available(const bca_addr_t* addr);

    int start_handle();

    int stop_handle();

    int report_handle(Message& message);

    int data_available_handle(Message& message);

    void keep_alive_handle();

    void timer_callback();

    int report_list_clear();

    int on_start(int status);

    int on_stop();

    int on_action(const char* action);

    int update_topic_id();

    int get_topic_id() const;

    static bca_status_t play_uri(bca_context ctx, bca_msg_t* msg, bca_addr_t* addr);

    static bca_status_t update_package(bca_context ctx,
                                       bca_msg_t* msg,
                                       bca_addr_t* addr);

    static bca_status_t invoke_alive(bca_context ctx,
                                     bca_msg_t* msg,
                                     bca_addr_t* addr);

    static bca_status_t output_result(bca_context ctx,
                                      bca_msg_t* msg,
                                      bca_addr_t* addr);

    void prepare_start_puzzle_timer(baidu_json* puzzle_resource);

    IOnEvent*           _on_event_listener;

    Handler             _event_handler;

    bca_handler         _handler;

    int                 _state;

    rtos::Mutex         _mutex;

    rtos::RtosTimer     _timer;

    unsigned int        _start_timeout;

    duer::SocketAdapter::Callback  _on_read_callback;

    bu_list_t           _send_list;

    mbed::Timer         _stop_timer;

    unsigned int        _stop_timeout;

    int                 _topic_id;
    bool                _enable_ota;

    static Scheduler    _s_scheduler;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_SCHEDULER_H
