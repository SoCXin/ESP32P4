#ifndef _RDA5991H_WLAND_H_
#define _RDA5991H_WLAND_H_

#include "sys_arch.h"

/* Mbed interface mac address
 * if MBED_MAC_ADD_x are zero, interface uid sets mac address,
 * otherwise MAC_ADD_x are used.
 */

extern unsigned char gssid[32+1];
extern unsigned char gpass[64+1];

extern unsigned char gssid_ap[20];
extern unsigned char gpass_ap[20];
extern unsigned char gchannel_ap;
extern void *wland_msgQ;
typedef enum {
    WLAND_CONNECT,
    WLAND_RECONNECT,
    WLAND_DISCONNECT,
    WLAND_DISCONNECT_ERROR,
    WLAND_STARTAP,
    WLAND_STOPAP,
    WLAND_ADD_AP_GTK,
    WLAND_ADD_AP_PTK,
    WLAND_STAJOINED,
    WLAND_STAEXITED,
    WLAND_MAC_CONNECTED,
    WLAND_MAC_AP_CONNECTED,
    WLAND_ADD_GTK,
    WLAND_ADD_PTK,
    WLAND_CON_FINISH,
    WLAND_AUTO_RATE,
    WLAND_ARP_OFFLOAD,
    WLAND_SM_START,
    WLAND_SM_STOP,
}WLAND_MSG;

typedef enum {
    MAIN_RECONNECT,
    MAIN_STOP_AP,
}MAIN_MSG;

enum {
    D_NONE_LEVEL = 0,
    D_ERROR_LEVEL = 1,
    D_INFO_LEVEL = 2,
    D_DEBUG_LEVEL = 3,
};

#define WLAND_DBG_DUMP    0
#define WPA_DBG_DUMP      0
#define WLAND_DBG_LEVEL D_NONE_LEVEL
#define WPA_DBG_LEBEL   D_NONE_LEVEL
#define WLANDLIB_DBG_LEVEL D_NONE_LEVEL

/** This struct contains tx power parameter. */
typedef struct
{
    unsigned char b[14];
    unsigned char g[14];
    unsigned char n[14];
    unsigned char sum;
    unsigned char padding1;//alignment
} wland_tx_power_t;

#define RDA5991H_USER_DATA_FLAG_TX_POWER (1UL << 5)
#define RDA5991H_USER_DATA_FLAG_RF_CAL   (1UL << 6)

#define ETH_ALEN 6

/* r91h driver data structure */
typedef struct {
    struct netif *netif_sta;
    struct netif *netif_ap;
    sys_thread_t wland_thread;
    sys_thread_t maclib_thread;
    sys_mbox_t maclib_mbox;
    sys_mbox_t wland_mbox;
} rda_enetdata_t;

__INLINE int mac_is_valid(char* mac)
{
    return (mac[0] | mac[1] | mac[2] | mac[3] | mac[4] | mac[5]);
}


#ifdef __cplusplus
extern "C" {
#endif

extern void wland_txip_data(void *data, unsigned int len, int mode);
extern void *wland_get_databuf(void);
extern void wland_sta_init(void);
extern void wland_reg_func(void);
extern void r91h_phy_task(void *data);
extern void wland_task(void *arg);
extern void rda_get_macaddr(u8_t *macaddr, int mode);

typedef struct {
    char BSSID[ETH_ALEN];
    char SSID[32+1];
    signed char RSSI;
    unsigned char SSID_len;
    unsigned char channel;
    unsigned char secure_type;
    unsigned char wmm;
    unsigned char *ie;//user program couldn't free(ie);
    unsigned short capability;
    unsigned int ie_length;
}rda5981_scan_result;
int rda5981_scan(const char *SSID, const unsigned char SSID_len, const unsigned char channel);
int rda5981_get_scan_result(rda5981_scan_result *buf, const unsigned char len);
int rda5981_get_scan_result_index(rda5981_scan_result *buf, const unsigned char index);
int rda5981_get_scan_result_name(rda5981_scan_result *buf, const unsigned char *name);
int rda5981_del_scan_all_result(void);
void rda5981_set_main_queue(void* queue);

/*
 * return 0:ok, else:error.
 */
int rda5981_flash_read_mac_addr(unsigned char *mac_addr);
int rda5981_flash_write_mac_addr(unsigned char *mac_addr);

/*
 * return 0:ok, else:error.
 */
int rda5981_flash_read_ip_addr(unsigned char *ip_addr, unsigned char *server_addr);
int rda5981_flash_write_ip_addr(unsigned char *ip_add, unsigned char *server_addr);

/*
 * read 3rd parter data length from flash
 * return user data length
 */
int rda5981_flash_read_3rdparter_data_length(void);

/*
 * read 3rd parter data from flash
 * @buf, buf to store user data
 * @buf_len, length of buf
 * return user data length
 */
int rda5981_flash_read_3rdparter_data(unsigned char *buf, unsigned int buf_len);

/*
 * write 3rd parter data from flash
 * @buf, data to write
 * @buf_len, length of buf.
 * return 0:ok, else:fail
 */
int rda5981_flash_write_3rdparter_data(const unsigned char *buf, unsigned int buf_len);

/*
 * erase 3rd parter data from flash
 * return 0:ok, else:fail
 */
int rda5981_flash_erase_3rdparter_data(void);

/*
 * set flash size
 * @size, 1MB:0x100000, 2MB:0x200000, 4MB:0x400000. default size: 1MB
 * return 0:ok, else:fail
 */
int rda5981_set_flash_size(const unsigned int size);

/*
 * set userdata location on flash
 * @sys_data_addr, data to save system parameter, user can not operate this area directly.
 *         size:4KB. default location:0x180fb000
 * @user_data_addr, data to save user data. user can save own data in this area
 *         by @rda5981_flash_read_3rdparter_data
 *         and @rda5981_flash_write_3rdparter_data
 *         default location:0x180fc000
 * @user_data_len, user data length, default:4KB
 * return 0:ok, else:fail
 */
int rda5981_set_user_data_addr(const unsigned int sys_data_addr,
    const unsigned int user_data_addr, const unsigned int user_data_len);

/*
 * function: erase flash
 * @addr: mast be 4k alignment
 * @len:  must be 4k alignment. (package 64KB erase and 4KB erase for different condition automatically)
 * return: 0:success, else:fail
 */
int rda5981_erase_flash(unsigned int addr, unsigned int len);

/*
 * function: write flash
 * @addr: mast be 256 alignment
 * @buf: data to be written, best be 4 alignment
 * @len: buffer len, mast be 4 alignment
 * return: 0:success, else:fail
 */
int rda5981_write_flash(unsigned int addr, char *buf, unsigned int len);

/*
 * function: read flash to @buf
 * @addr: best be 4 alignment
 * @buf: best be 4 alignment
 * @len: buffer len
 * return: 0:success, else:fail
 */
int rda5981_read_flash(unsigned int addr, char *buf, unsigned int len);

/*
 * return 0:ok, else:error.
 */
int rda5981_read_user_data(unsigned char *data, unsigned char len, unsigned int flag);

/*
 * return 0:ok, else:error.
 */
int rda5981_write_user_data(unsigned char *data, unsigned char len, unsigned int flag);

/*
 * return 0:ok, else:error.
 */
int rda5981_erase_user_data(unsigned int flag);


#ifdef __cplusplus
}
#endif

#endif

