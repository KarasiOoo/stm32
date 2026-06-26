#include "stm32l476xx.h"

void delay_ms(uint32_t ms) {
    // Przy domyślnym zegarze MSI 4 MHz: ~4000 cykli/ms
    for (uint32_t i = 0; i < ms * 4000; i++) {
        __NOP();
    }
}

int main(void) {
    // 1. Włącz taktowanie portu C (bit 2 w RCC_AHB2ENR)
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

    // 2. Skonfiguruj PC11 jako wyjście (MODER[23:22] = 01)
    GPIOC->MODER &= ~(GPIO_MODER_MODE11_Msk);   // wyczyść bity
    GPIOC->MODER |=  (0x1UL << GPIO_MODER_MODE11_Pos); // output

    // 3. Output push-pull (domyślnie, OTYPER bit 11 = 0)
    GPIOC->OTYPER &= ~GPIO_OTYPER_OT11;

    // 4. Prędkość Low Speed (domyślnie)
    GPIOC->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED11_Msk;

    // 5. Brak pull-up/pull-down (domyślnie)
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPD11_Msk;

    while (1) {
        GPIOC->BSRR = GPIO_BSRR_BS11;   // ustaw PC11 (LED ON)
        delay_ms(500);
        GPIOC->BSRR = GPIO_BSRR_BR11;   // resetuj PC11 (LED OFF)
        delay_ms(500);
    }
}
