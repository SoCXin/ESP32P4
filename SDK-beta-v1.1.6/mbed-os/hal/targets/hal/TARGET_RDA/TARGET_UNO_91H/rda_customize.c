#include "RDA5991H.h"

#ifdef RDA_CUSTOM_CODE_BASE

#if defined(RDA_ICACHE_DISABLE)
void* const RDA_CODE_BASE = (void*)(RDA_FLASH_BASE + RDA_PADDR_OFST);
#else  /* RDA_ICACHE_DISABLE */
void* const RDA_CODE_BASE = (void*)(RDA_ICACHE_BASE + RDA_PADDR_OFST);
#endif /* RDA_ICACHE_DISABLE */

#if defined(BD_FEATURE_ENABLE_OTA)
    int rda_ota_enable = 1;
#else
    int rda_ota_enable = 0;
#endif

#endif
