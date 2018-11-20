# 1 "../mbed-os\\rtos\\rtx\\TARGET_CORTEX_M\\TARGET_RTOS_M4_M7\\TOOLCHAIN_ARM\\SVC_Table.S"
# 1 "C:\\Users\\changli\\workspace\\0807\\baidu-iot\\TinyDu\\BUILD\\mbed-os\\mbed_config.h"







# 22 "C:\\Users\\changli\\workspace\\0807\\baidu-iot\\TinyDu\\BUILD\\mbed-os\\mbed_config.h"



# 1 "../mbed-os\\rtos\\rtx\\TARGET_CORTEX_M\\TARGET_RTOS_M4_M7\\TOOLCHAIN_ARM\\SVC_Table.S"
;































 


                AREA    SVC_TABLE, CODE, READONLY

                EXPORT  SVC_Count

SVC_Cnt         EQU    (SVC_End-SVC_Table)/4
SVC_Count       DCD     SVC_Cnt

; Import user SVC functions here.
;               IMPORT  __SVC_1

                EXPORT  SVC_Table
SVC_Table
; Insert user SVC functions here. SVC 0 used by RTL Kernel.
;               DCD     __SVC_1                 ; user SVC function

SVC_End

                END



 
