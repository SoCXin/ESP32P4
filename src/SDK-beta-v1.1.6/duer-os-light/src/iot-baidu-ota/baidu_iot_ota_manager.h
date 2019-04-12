// Copyright 2017 Baidu Inc. All Rights Reserved.
// Author: Duan Lian (duanlian01@baidu.com)
//
// Description: OTA Manager

#ifndef BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_MANAGER_H
#define BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_MANAGER_H

#include "rtos.h"
#ifdef TARGET_UNO_91H
#include "package_scanner.h"     // RDA
#endif
#include "baidu_iot_ota_reporter.h"
#include "baidu_iot_ota_shared_buffer.h"

namespace duer {

struct OTAServerUpdateCommand {
    char transaction[65];
    char version[16];
    char old_version[16];
    char url[129];
    char signature[129];
    unsigned int size;
};

class OTAManager {
public:
    /*
     * Description: Get OTAManager instance
     *
     * Parameter: None
     *
     * Returned value: OTAManager instance
     */
    static OTAManager* instance();

    ~OTAManager();

    /*
     * Description: Checkup
     *
     * Parameter: Update commmand
     *
     * Returned value:
     *     0: check
     *     1: do not check
     */
    int check_updates(const char* command);

    /*
     * Description: Report Package information
     *
     * Parameter: None
     *
     * Returned value:
     *     0: Success
     *     Other: Failed
     */
    int sync_package_info();

    /*
     * Description: Get package information
     *
     * Parameter: struct Os_info&
     *
     * Returned value:
     *     0: Success
     *     Other: Failed
     */
    int get_os_info(struct os_info& info);

private:
    enum ShareBufferSize {
        SHARED_BUFFER_SIZE = 2048
    };

    OTAManager();

    // Check if updates are available and perform downloading
    void run_downloader();

    int contact_ota_server();

    int parse_update_command(const char* str_command, OTAServerUpdateCommand& command);

    // Decrypt package and write data to storage
    void run_installer();

    int apply_updates(const OTAServerUpdateCommand& command);

    static int data_available(unsigned char* data, unsigned int len, void* ctx);

    static void ota_resart();

    SharedBuffer _m_shared_buffer;

    static OTAManager _s_manager;

    bool           _m_b_idle;

    char*          _m_p_update_command;

    OTAReporter*   _m_p_reporter;

    rtos::Thread*  _m_p_thread;

    rtos::Thread*  _m_p_restart_thread;

    rtos::Mutex    _m_lock;

    rtos::Semaphore* _m_p_install_complete;

#ifdef TARGET_UNO_91H
    PackageScanner _m_scanner;
#endif
};

} // namespace duer

#endif // BAIDU_IOT_TINYDU_IOT_OS_SRC_IOT_BAIDU_OTA_BAIDU_IOT_OTA_MANAGER_H
