// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: Implement MediaBase for Vs10xx

#ifndef BAIDU_TINYDU_IOT_OS_SRC_VS10XX_BAIDU_VS10XX_BASE_H
#define BAIDU_TINYDU_IOT_OS_SRC_VS10XX_BAIDU_VS10XX_BASE_H

#include "vs10xx.h"
#include "baidu_media_base.h"

namespace duer {

class Vs10xxBase : public MediaBase {
public:
    Vs10xxBase(
        PinName mosi,
        PinName miso,
        PinName sclk,
        PinName xcs,
        PinName xdcs,
        PinName dreq,
        PinName xreset);

protected:
    virtual int on_start_play(MediaType type);

    virtual int on_write(const void* data, size_t size);

    virtual int on_voice(unsigned char vol);

    virtual int on_pause_play();

    virtual int on_stop_play();

    virtual int on_start_record();

    virtual size_t on_read(void* data, size_t size);

    virtual int on_stop_record();

    virtual bool is_play_stopped_internal();

private:
    vs10xx  _vs10xx;
    bool    _play_stopped;
};

} // namespace duer

#endif // BAIDU_TINYDU_IOT_OS_SRC_VS10XX_BAIDU_VS10XX_BASE_H
