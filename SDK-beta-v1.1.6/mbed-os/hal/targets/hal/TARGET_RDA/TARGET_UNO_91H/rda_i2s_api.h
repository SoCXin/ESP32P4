/* mbed Microcontroller Library
 * Copyright (c) 2006-2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef RDA_I2S_API_H
#define RDA_I2S_API_H

#include <stdint.h>
#include "device.h"

/** I2S HAL enumeration
 */
typedef enum {
    I2S_64FS  = 0x00,
    I2S_32FS  = 0x01
} I2S_FS_T;

typedef enum {
    I2S_WS_NEG  = 0x00,
    I2S_WS_POS  = 0x01
} I2S_WS_POLAR_T;

typedef enum {
    I2S_OTHER_M = 0x00,
    I2S_STD_M   = 0x01
} I2S_STD_MODE_T;

typedef enum {
    I2S_RIGHT_JM = 0x00,
    I2S_LEFT_JM  = 0x01
} I2S_JUSTIFIED_MODE_T;

typedef enum {
    I2S_DL_16b  = 0x00,
    I2S_DL_20b  = 0x01,
    I2S_DL_24b  = 0x02
} I2S_DATA_LEN_T;

typedef enum {
    I2S_LSB     = 0x00,
    I2S_MSB     = 0x01
} I2S_MSB_LSB_T;

typedef enum {
    I2S_WF_CNTLFT_1W    = 0x00,
    I2S_WF_CNTLFT_2W    = 0x01,
    I2S_WF_CNTLFT_4W    = 0x02,
    I2S_WF_CNTLFT_8W    = 0x03
} I2S_WRFIFO_CNTLEFT_T;

typedef enum {
    I2S_MD_MASTER_RX = 0x00,
    I2S_MD_MASTER_TX = 0x01,
    I2S_MD_SLAVE_RX  = 0x02,
    I2S_MD_M_TX_S_RX = 0x03
} RDA_I2S_MODE_T;

typedef enum {
    I2S_ST_RESET = 0,
    I2S_ST_READY,
    I2S_ST_BUSY
} RDA_I2S_SW_STATE_T;

/** I2S HAL structure
 */
typedef struct {
    volatile RDA_I2S_SW_STATE_T state;
    uint32_t *buffer;
    uint16_t bufferCntr;
    uint16_t bufferSize;
    uint8_t  regBitOfst;
    uint8_t  fifoThreshold;
} RDA_I2S_SW_PARAM_T;

typedef struct {
    uint8_t fs;
    uint8_t ws_polarity;
    uint8_t std_mode;
    uint8_t justified_mode;
    uint8_t data_len;
    uint8_t msb_lsb;
    uint8_t wrfifo_cntleft;
} RDA_I2S_HW_PARAM_T;

typedef struct {
    RDA_I2S_MODE_T     mode;
    RDA_I2S_HW_PARAM_T tx;
    RDA_I2S_HW_PARAM_T rx;
} i2s_cfg_t;

typedef struct {
    struct i2s_s hw;
    RDA_I2S_SW_PARAM_T sw_tx;
    RDA_I2S_SW_PARAM_T sw_rx;
} i2s_t;

#ifdef __cplusplus
extern "C" {
#endif

/** Initialize the i2s module
 *
 */
void rda_i2s_init(i2s_t *obj, PinName tx_bclk, PinName tx_ws, PinName tx_sd,
                              PinName rx_bclk, PinName rx_ws, PinName rx_sd);

/** De-Initialize the i2s module
 *
 */
void rda_i2s_deinit(i2s_t *obj);

/** Format the i2s signal
 *
 */
void rda_i2s_format(i2s_t *obj, i2s_cfg_t *cfg);

/** Send data in blocking mode
 *
 */
uint8_t rda_i2s_blk_send(i2s_t *obj, uint32_t *buf, uint16_t size);

/** Receive data in blocking mode
 *
 */
uint8_t rda_i2s_blk_recv(i2s_t *obj, uint32_t *buf, uint16_t size);

/** Send data in interrupt mode
 *
 */
uint8_t rda_i2s_int_send(i2s_t *obj, uint32_t *buf, uint16_t size);

/** Receive data in interrupt mode
 *
 */
uint8_t rda_i2s_int_recv(i2s_t *obj, uint32_t *buf, uint16_t size);

/** The wrapper for i2s_irq_handler
 *
 */
void rda_i2s_irq_handler(uint32_t int_status);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
