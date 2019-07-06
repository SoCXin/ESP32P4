/*
 * IOtaUpdater.h
 *
 *  Created on: 2016-7-15
 *      Author: duanlian01
 */

#ifndef IOTAUPDATER_H_
#define IOTAUPDATER_H_

#define PACKAGE_NAME_LENGTH_MAX (15)
#define PACKAGE_TYPE_OS      1
#define PACKAGE_TYPE_APP     2
#define PACKAGE_NO_UPDATE    0
#define PACKAGE_UPDATE       1

struct meta_data_basic_info{
	char package_name[PACKAGE_NAME_LENGTH_MAX + 1];
	unsigned char package_type;
	unsigned char package_update;
};


#define MODULE_NAME_LENGTH_MAX (PACKAGE_NAME_LENGTH_MAX)
#define MODULE_VERSION_LENGTH_MAX 15
#define HARDWARE_VERSION_LENGTH_MAX 15
#define MODULE_SIGNATURE_LENGTH     16
#define MODULE_TYPE_BIN 1
#define MODULE_NO_UPDATE 0
#define MODULE_UPDATE 1

struct module_info{
	char module_name[MODULE_NAME_LENGTH_MAX + 1];
	char module_version[MODULE_VERSION_LENGTH_MAX + 1];
	char module_support_hw_version[HARDWARE_VERSION_LENGTH_MAX + 1];
	unsigned char module_signature[MODULE_SIGNATURE_LENGTH];
	unsigned int module_size;
	unsigned char module_type;
	unsigned char module_update;
};

#define PACKAGE_INSTALL_PATH_MAX  255
struct meta_data_install_info{
	char package_install_path[PACKAGE_INSTALL_PATH_MAX + 1];
	unsigned int module_count;
	struct module_info *module_list;
};

#define PACKAGE_VERSION_LENGTH MODULE_VERSION_LENGTH_MAX
struct meta_data_update_info{
	char package_version[PACKAGE_VERSION_LENGTH];
};

struct meta_data_extension{
	unsigned int pair_count;
	char **keys;
	char **values;
};

struct package_meta_data{
	struct meta_data_basic_info basic_info;
    struct meta_data_install_info install_info;
    struct meta_data_update_info update_info;
    struct meta_data_extension extension_info;
};

struct IOtaUpdater
{
    int (*notify_data_begin)();
	int (*notify_meta_data)(void *cxt, struct package_meta_data *meta);
	int (*notify_module_data)(void *cxt, unsigned int offset, unsigned char *data, unsigned int size);
	int (*notify_data_end)();
	int (*update_img_begin)();
	int (*update_img)();
	int (*update_img_end)();
};

#endif /* IOTAUPDATER_H_ */
