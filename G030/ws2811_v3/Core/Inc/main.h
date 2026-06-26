
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

void Error_Handler(void);

#define __NOPten() __ASM volatile ("nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" )



#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
