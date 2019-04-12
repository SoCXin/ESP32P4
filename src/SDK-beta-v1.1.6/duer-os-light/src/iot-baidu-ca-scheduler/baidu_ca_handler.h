// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: Handler

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_HANDLER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_HANDLER_H

#include "rtos.h"
#include "baidu_ca_message.h"

namespace duer {

class Handler {
public:
    class OnMessageListener {
    public:

        virtual bool on_message(Message& message) = 0;

        virtual ~OnMessageListener() {}

    };

    Handler();

    virtual ~Handler();

    void send_message(int what, void* object);

    void send_message(const Message& message);

    void set_on_message_listener(OnMessageListener* listener);

protected:

    virtual void handle_message(Message& message);

private:

    void loop();

    rtos::Thread                _thread;
    rtos::Queue<Message, 20>    _queue;
    OnMessageListener*          _listener;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_HANDLER_H
