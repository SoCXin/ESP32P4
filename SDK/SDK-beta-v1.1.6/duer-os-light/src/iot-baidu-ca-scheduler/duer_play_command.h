// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: Report the Play Events.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_DUER_PLAY_EVENTS_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_DUER_PLAY_EVENTS_H

#include "baidu_json.h"

namespace duer
{

class PlayCommand
{

public:

    enum Location {
        LOCAL,
        URL
    };

    enum Status {
        OK,
        ERR_MEMORY_OVERFLOW = -1,
        ERR_UNKOWN_ACTION = -2,
    };

    PlayCommand();

    virtual ~PlayCommand();

    int set_action(baidu_json *action);

    int set_location(Location location);

    int start();

    int stop();

    int end();

    int next();

    int previous();

    int repeat();

private:

    PlayCommand(const PlayCommand& other);

    PlayCommand &operator =(const PlayCommand& other);

    int report(const char *action);

    baidu_json *    _data;

};

}

#endif/*BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_DUER_PLAY_EVENTS_H*/
