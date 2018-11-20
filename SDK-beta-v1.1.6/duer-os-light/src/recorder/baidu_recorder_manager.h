// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: tai xiurong (taixiurong@baidu.com)
//
// Description:

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_RECORDER_BAIDU_OS_RECORDER_MANAGER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_RECORDER_BAIDU_OS_RECORDER_MANAGER_H

#include "baidu_recorder.h"

namespace duer {

class RecorderManager {
public:
    RecorderManager();

    ~RecorderManager();
    /*
     *  start recoder.
     *  @return
     *  - -1  fail
     *  - >=0  sucess
     */
    int start();
    /*
     *  resume recoder.
     *  @return
     *  - -1  fail
     *  - >=0  sucess
     */
    int resume();
    /*
     *  pause recoder.
     *  @return
     *  - -1  fail
     *  - >=0  sucess
     */
    int pause();
    /*
     *  stop recoder.
     *  @return
     *  - -1  fail
     *  - >=0  sucess
     */
    int stop();
    /*
     *  set recoder listener.
     *  @return
     *  - -1  fail
     *  - >=0  sucess
     */
    int set_listener(Recorder::IListener* listener);

private:

    Recorder                _recorder;
    Recorder::MiddleWare*   _midware;
};
}//duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_RECORDER_BAIDU_OS_RECORDER_MANAGER_H
