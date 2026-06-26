#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

#define __NOPten() __ASM volatile ("nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" "nop\t\n" )

void Error_Handler(void);

void ws2811(uint8_t state);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
