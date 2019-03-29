// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Pan Haijun, Gang Chen(chengang12@baidu.com)
//
// This header file define the HttpClient class, it's used to establish http connection.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_HTTP_CLIENT_BAIDU_HTTP_CLIENT_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_HTTP_CLIENT_BAIDU_HTTP_CLIENT_H

#include "baidu_http_client_c.h"

namespace duer {

class HttpClient {
public:
    HttpClient();
    ~HttpClient();
    /**
     *  register data output handler callback to handle data block
     *  @param[in] data output handler callback to be registered
     *  @param[in] p_usr_ctx for data output handler callback to be registered
     *  @return   none
     */
    void register_data_handler(data_out_handler_cb data_hdlr_cb, void* p_usr_ctx);
    /**
     *  register callback to check stop flag
     *  @param[in] chk_stp_cb: to notify httpclient to stop
     *  @return   none
     */
    void register_notify_call_back(check_stop_notify_cb_t chk_stp_cb);
    /**
     *  create http connection and get data by the url
     *  @param[in] url: to get http client_c's url
     *  @param[in] pos: the position to receive the http data,
     *                  sometimes user only want to get part of the data
     *  @return   e_http_result
     */
    int get(const char* url, const size_t pos);
    /**
     *  register callback to get url which is used by http to get data
     *  @param[in] the callback to be registered
     *  @return   none
     */
    void register_call_back_to_get_url(get_url_cb_t cb);
    /**
     * get http download progress
     *
     * PARAM:
     * @param[out] total_size: to receive the total size to be download
     *                         if chunked Transfer-Encoding is used, we cannot know the total size
     *                         untile download finished, in this case the total size will be 0
     * @param[out] recv_size:  to receive the data size have been download
     *
     * @return     none
     */
    void get_download_progress(size_t* total_size, size_t* recv_size);
private:
    http_client_c* _p_client_inst;
};

}//duer
#endif//BAIDU_IOT_TINYDU_IOT_OS_SRC_HTTP_CLIENT_BAIDU_HTTP_CLIENT_H

