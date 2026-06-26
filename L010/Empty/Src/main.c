#include "main.h"


int main(void)
{
	//PA5 - LED
	//RCC->IOPENR |= (1<<0);
	RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODE5_0; 				// 2-bit
	GPIOA->MODER &= ~(GPIO_MODER_MODE5_1);
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_5); 				// 1-bit
	GPIOA->OSPEEDR &= ~(GPIO_OTYPER_OT_5);				// 2-bit
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5);				// 2-BIT
	// GPIOA->IDR;										// Read only Input registers.
	//GPIOA->ODR; 										// Output registers, but not best to use.
	GPIOA->BSRR |= GPIO_BSRR_BR_5;						// Reset through BSRR register (SET/RESET reg)
	//GPIOA->LCKR;
	//GPIOA->AFR[0];									//AFR[0] dla pinów 0-7 danego portu, AFR[1] dla pinów 8-15
	GPIOA->BRR |= GPIO_BRR_BR_5;						// Reset through reset register .

    /* Loop forever */
	for(;;);
}
