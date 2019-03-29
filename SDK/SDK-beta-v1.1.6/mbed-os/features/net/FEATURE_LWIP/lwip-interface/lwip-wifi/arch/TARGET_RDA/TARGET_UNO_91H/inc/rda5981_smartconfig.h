#ifndef _RDA5981_SMARTCONFIG_H_
#define _RDA5981_SMARTCONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif


int rda5981_flash_erase_smartconfig_data(void);
int rda5981_flash_read_smartconfig_data(char *ssid, char *passwd);
int rda5981_flash_write_smartconfig_data(const char *ssid, const char *passwd);
typedef int (*smartconfig_handler)(unsigned short data_len, void *data);

/*
 * you can use RDA smartconfig by rda5981_getssid_from_smartconfig api
 * you can set your self smartconfig handler by use the other three api
 */

#define SMARTLING_REPORT_PORT 18266
#define SMARTLING_REPORT_MSG_OFFSET 9

#define CONFIG_RDA_SMARTCONFIG
//close this marco, will disable rda smartconfig(3rdparter smartconfig is still ok).
//close it could save about 5KB flash space

#ifdef CONFIG_RDA_SMARTCONFIG
int rda5981_getssid_from_smartconfig(char *ssid, char *passwd,
    unsigned char *ip4_addr);
#else /*CONFIG_RDA_SMARTCONFIG*/
static int rda5981_getssid_from_smartconfig(char *ssid, char *passwd,
    unsigned char *ip4_addr)
{
    return -1;
}
#endif /*CONFIG_RDA_SMARTCONFIG*/

int rda5981_start_smartconfig(smartconfig_handler handler);
int rda5981_set_smartconfig(unsigned char channel,
    unsigned char to_ds, unsigned char from_ds, unsigned char mgm_frame, unsigned short time);
//int rda5981_set_smartconfig(unsigned char channel,
//    unsigned char to_ds, unsigned short time);
int rda5981_stop_smartconfig(void);

#ifdef __cplusplus
}
#endif

#endif /*_RDA5981_SMARTCONFIG_H_*/
