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
#ifndef RDA_CCFG_API_H
#define RDA_CCFG_API_H

#ifdef __cplusplus
extern "C" {
#endif

/** Config always-on Timer
 *
 */
void rda_ccfg_aontmr(void);

/** Config pin gp6
 *
 */
void rda_ccfg_gp6(unsigned short cfg);

/** Config pin gp7
 *
 */
void rda_ccfg_gp7(unsigned short cfg);

void rda_ccfg_ckrst(void);
void rda_ccfg_adc_init(unsigned char ch);
unsigned short rda_ccfg_adc_read(unsigned char ch);
void rda_ccfg_adc_free(unsigned char ch);
int rda_ccfg_abort_flag(void);
#if RDA5991H_HW_VER >= 2
void rda_ccfg_wdt_en(void);
#endif /* RDA5991H_HW_VER */
int rda_ccfg_hwver(void);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif

