/*
 * ota_updater.h
 *
 *  Created on: 2017-2-28
 *      Author: duanlian01
 */

#ifndef RDA_OTA_UPDATER_H_
#define RDA_OTA_UPDATER_H_
#include "IOtaUpdater.h"
#define OTA_IMAGE_BAD_SIZE  1
#define OTA_UPDATE_CRC_FAIL 2
#ifdef __cplusplus
extern "C" {
#endif
struct rda_ota_update_context{
	    void *address;
	    struct module_info info;
};
int rda_notify_data_begin();
int rda_notify_meta_data(void *cxt, struct package_meta_data *meta);
int rda_notify_module_data(void *cxt, unsigned int offset, unsigned char *data, unsigned int size);
int rda_notify_data_end();

void rda_ota_restart();

int rda_ota_update_image_begin();
int rda_ota_update_image();
int rda_ota_update_image_end();
#ifdef __cplusplus
}
#endif
#endif /* RDA_OTA_UPDATER_H_ */
