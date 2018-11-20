// Copyright (2016) Baidu Inc. All rights reserved.
/**
 * File: device_controller.cpp
 * Desc: Demo for control device.
 */
#include "device_controller.h"
#include "baidu_ca_scheduler.h"
#include "baidu_media_manager.h"
#include "duer_log.h"

namespace duer {

#if defined(TEST_BOARD)

static bca_status_t media_stop(bca_context ctx, bca_msg_t* msg, bca_addr_t* addr) {
    bca_handler handler = (bca_handler)ctx;
    DUER_LOGV("media_stop");

    if (handler && msg) {
        duer::MediaManager::instance().stop();
        duer::Scheduler::instance().response(msg, BCA_MSG_RSP_CHANGED, NULL);
    }

    return BCA_NO_ERR;
}

static bca_status_t set_volume(bca_context ctx, bca_msg_t* msg, bca_addr_t* addr) {
    bca_handler handler = (bca_handler)ctx;
    static int volume = 10;
    int msg_code = BCA_MSG_RSP_CHANGED;
    const int LEN = 3;
    char str_volume[LEN] = {0};
    DUER_LOGV("set_volume");

    if (handler && msg) {
        if (msg->msg_code == BCA_MSG_REQ_GET) {
            DUER_LOGI("volume get: %d", volume);
            snprintf(str_volume, LEN, "%d", volume);
        } else if (msg->msg_code == BCA_MSG_REQ_PUT) {
            if (msg->payload && msg->payload_len > 0 && msg->payload_len < LEN) {
                snprintf(str_volume, LEN, "%s", (char*)msg->payload);
                DUER_LOGI("volume set: %s, len: %d", str_volume, msg->payload_len);
                str_volume[msg->payload_len] = 0;
                int vol = atoi(str_volume);

                if (vol > 16 || vol < 0) {
                    msg_code = BCA_MSG_RSP_FORBIDDEN;
                } else {
                    if (volume == vol) {
                        msg_code = BCA_MSG_RSP_VALID;
                    } else {
                        duer::MediaManager::instance().set_volume(vol);
                        volume = vol;
                    }
                }
            } else {
                msg_code = BCA_MSG_RSP_FORBIDDEN;
                str_volume[0] = 0;
                DUER_LOGI("volume set invalid");
            }
        }

        Scheduler::instance().response(msg, msg_code, str_volume);
    }

    return BCA_NO_ERR;
}

static bca_status_t shutdown(bca_context ctx, bca_msg_t* msg, bca_addr_t* addr) {
    bca_handler handler = (bca_handler)ctx;
    DUER_LOGV("shutdown");

    if (handler && msg) {
        duer::Scheduler::instance().response(msg, BCA_MSG_RSP_CHANGED, NULL);
        duer::Scheduler::instance().stop();
    }

    return BCA_NO_ERR;
}

static bca_status_t set_mode(bca_context ctx, bca_msg_t* msg, bca_addr_t* addr) {
    bca_handler handler = (bca_handler)ctx;
    static const int LEN = 10;
    static char mode[LEN] = {0};
    int msg_code = BCA_MSG_RSP_CHANGED;
    DUER_LOGV("set_mode");

    if (handler && msg) {
        if (msg->msg_code == BCA_MSG_REQ_GET) {
            DUER_LOGI("mode get: %s", mode);
        } else if (msg->msg_code == BCA_MSG_REQ_PUT) {
            if (msg->payload && msg->payload_len > 0) {
                snprintf(mode, LEN, "%s", (char*)msg->payload);
                DUER_LOGI("mode set: %s", mode);
            } else {
                msg_code = BCA_MSG_RSP_FORBIDDEN;
                mode[0] = 0;
                DUER_LOGI("mode set invalid");
            }
        }

        Scheduler::instance().response(msg, msg_code, mode);
    }

    return BCA_NO_ERR;
}

static bca_status_t get_power(bca_context ctx, bca_msg_t* msg, bca_addr_t* addr) {
    bca_handler handler = (bca_handler)ctx;
    static double power = 1.0;
    DUER_LOGV("get_power");

    if (handler && msg) {
        char str_power[4];
        snprintf(str_power, 4, "%lf", power);
        DUER_LOGI("power: %s", str_power);
        Scheduler::instance().response(msg, BCA_MSG_RSP_CHANGED, str_power);

        if (power > 0.5) {
            power -= 0.01;
        }
    }

    return BCA_NO_ERR;
}

#endif

void device_controller_init(void) {
#if defined(TEST_BOARD)
    bca_res_t res[] = {
        {BCA_RES_MODE_DYNAMIC, BCA_RES_OP_PUT, "stop", media_stop},
        {BCA_RES_MODE_DYNAMIC, BCA_RES_OP_PUT | BCA_RES_OP_GET, "volume", set_volume},
        {BCA_RES_MODE_DYNAMIC, BCA_RES_OP_PUT, "shutdown", shutdown},
        {BCA_RES_MODE_DYNAMIC, BCA_RES_OP_PUT | BCA_RES_OP_GET, "mode", set_mode},
        {BCA_RES_MODE_DYNAMIC, BCA_RES_OP_GET, "power", get_power},
    };
    Scheduler::instance().add_controll_points(res, sizeof(res) / sizeof(res[0]));
#endif
}

} // namespace duer
