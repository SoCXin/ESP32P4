// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Su Hao (suhao@baidu.com)
//
// Description: Implement MediaBase for Rda58xx

#ifndef BAIDU_EXTERNAL_TARGETS_EXT_TARGET_UNO_91H_RDA58XX_BAIDU_RDA58XX_BASE_H
#define BAIDU_EXTERNAL_TARGETS_EXT_TARGET_UNO_91H_RDA58XX_BAIDU_RDA58XX_BASE_H

#include "baidu_media_base.h"

namespace duer {

class Rda58xxBase : public MediaBase {
public:
    Rda58xxBase(PinName tx, PinName rx, PinName hreset);

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
};

} // namespace duer

#endif // BAIDU_EXTERNAL_TARGETS_EXT_TARGET_UNO_91H_RDA58XX_BAIDU_RDA58XX_BASE_H
