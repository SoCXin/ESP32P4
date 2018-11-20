// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: Report the Play Events.

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_DUER_PLAY_COMMAND_MANAGER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_DUER_PLAY_COMMAND_MANAGER_H

#include "baidu_json.h"
#include "baidu_util_list.h"

namespace duer
{

class PlayCommandManager
{

public:

    enum Status {
        OK,
        ERR_MEMORY_OVERFLOW = -1,
        ERR_UNKOWN_ACTION = -2,
    };

    static PlayCommandManager &instance(void);

    int add_command(baidu_json *action);

    int start();

    int stop();

    int end();

    int next();

    int previous();

    int repeat();

private:

    PlayCommandManager();

    virtual ~PlayCommandManager();

    PlayCommandManager(const PlayCommandManager& other);

    void clear_command(void);

    PlayCommandManager &operator =(const PlayCommandManager& other);

    bu_list_t _events;

    static PlayCommandManager s_instance;

};

}

#endif/*BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_CA_SCHEDULER_DUER_PLAY_COMMAND_MANAGER_H*/
