#pragma once
#include "baidu_iot_ota_package_info.h"

using namespace duer;

class PackageScanner
{
public:
    PackageScanner();
    ~PackageScanner();
    int scan();
    int get_os_info(struct os_info& info);
    int getAppInfo(struct app_info*& info);
private:
    struct os_info _os_info;
    struct app_info* apps; //app info kept in an array which ends with null pointer
};
