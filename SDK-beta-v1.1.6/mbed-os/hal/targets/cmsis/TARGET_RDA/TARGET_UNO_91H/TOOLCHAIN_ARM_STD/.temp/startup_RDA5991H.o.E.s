# 1 "../mbed-os\\hal\\targets\\cmsis\\TARGET_RDA\\TARGET_UNO_91H\\TOOLCHAIN_ARM_STD\\startup_RDA5991H.S"
# 1 "C:\\Users\\changli\\workspace\\0807\\baidu-iot\\TinyDu\\BUILD\\mbed-os\\mbed_config.h"







# 22 "C:\\Users\\changli\\workspace\\0807\\baidu-iot\\TinyDu\\BUILD\\mbed-os\\mbed_config.h"



# 1 "../mbed-os\\hal\\targets\\cmsis\\TARGET_RDA\\TARGET_UNO_91H\\TOOLCHAIN_ARM_STD\\startup_RDA5991H.S"
;


















 

                PRESERVE8
                THUMB

; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                IMPORT  |Image$$ARM_LIB_STACK$$ZI$$Limit| [WEAK]
                EXPORT  __Vectors

__Vectors       DCD     |Image$$ARM_LIB_STACK$$ZI$$Limit| ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     MemManage_Handler         ; MPU Fault Handler
                DCD     BusFault_Handler          ; Bus Fault Handler
                DCD     UsageFault_Handler        ; Usage Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     DebugMon_Handler          ; Debug Monitor Handler
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler

                ; External Interrupts
                DCD     SPIFLASH_IRQHandler       ; 16: SPI Flash
                DCD     PTA_IRQHandler            ; 17: PTA
                DCD     SDIO_IRQHandler           ; 18: SDIO
                DCD     USBDMA_IRQHandler         ; 19: USB DMA
                DCD     USB_IRQHandler            ; 20: USB
                DCD     GPIO_IRQHandler           ; 21: GPIO
                DCD     TIMER0_IRQHandler         ; 22: Timer0
                DCD     UART0_IRQHandler          ; 23: UART0
                DCD     MACHW_IRQHandler          ; 24: MAC Hardware
                DCD     UART1_IRQHandler          ; 25: UART1
                DCD     AHBDMA_IRQHandler         ; 26: AHB DMA
                DCD     PSRAM_IRQHandler          ; 27: PSRAM
                DCD     SDMMC_IRQHandler          ; 28: SDMMC
                DCD     EXIF_IRQHandler           ; 29: EXIF
                DCD     I2C_IRQHandler            ; 30: I2C



                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  rda_ccfg_boot
                IMPORT  SystemInit
                IMPORT  __main
                LDR     R0, =|Image$$ARM_LIB_STACK$$ZI$$Limit|
                MSR     MSP, R0
                LDR     R0, =rda_ccfg_boot
                BLX     R0
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler                PROC

                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
MemManage_Handler                PROC

                EXPORT  MemManage_Handler         [WEAK]
                B       .
                ENDP
BusFault_Handler                PROC

                EXPORT  BusFault_Handler          [WEAK]
                B       .
                ENDP
UsageFault_Handler                PROC

                EXPORT  UsageFault_Handler        [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
DebugMon_Handler                PROC

                EXPORT  DebugMon_Handler          [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler           [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  SPIFLASH_IRQHandler       [WEAK]
                EXPORT  PTA_IRQHandler            [WEAK]
                EXPORT  SDIO_IRQHandler           [WEAK]
                EXPORT  USBDMA_IRQHandler         [WEAK]
                EXPORT  USB_IRQHandler            [WEAK]
                EXPORT  GPIO_IRQHandler           [WEAK]
                EXPORT  TIMER0_IRQHandler         [WEAK]
                EXPORT  UART0_IRQHandler          [WEAK]
                EXPORT  MACHW_IRQHandler          [WEAK]
                EXPORT  UART1_IRQHandler          [WEAK]
                EXPORT  AHBDMA_IRQHandler         [WEAK]
                EXPORT  PSRAM_IRQHandler          [WEAK]
                EXPORT  SDMMC_IRQHandler          [WEAK]
                EXPORT  EXIF_IRQHandler           [WEAK]
                EXPORT  I2C_IRQHandler            [WEAK]

SPIFLASH_IRQHandler
PTA_IRQHandler
SDIO_IRQHandler
USBDMA_IRQHandler
USB_IRQHandler
GPIO_IRQHandler
TIMER0_IRQHandler
UART0_IRQHandler
MACHW_IRQHandler
UART1_IRQHandler
AHBDMA_IRQHandler
PSRAM_IRQHandler
SDMMC_IRQHandler
EXIF_IRQHandler
I2C_IRQHandler

                B       .

                ENDP

                ALIGN
                END
