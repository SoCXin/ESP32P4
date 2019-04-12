// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: Message

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_MESSAGE_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_MESSAGE_H

#include <cstddef>

namespace duer {

class Message {
public:
    Message(int what, void* object);

    Message(const Message& message);

    int get_what() const;

    void* get_object() const;
private:
    int     _what;
    void*   _object;
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_BAIDU_CA_MESSAGE_H
