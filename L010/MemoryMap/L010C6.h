
// Peripherals
#define ADC_REG ((ADC_Typedef *) 0x40012400)						// adc
#define ADC_CCR (uint32_t *) 0x40012708;		// sprawdzić poprawność W
#define CRC_REG 0x40023000
#define DEBUG_REG 0x40015800
#define DMA_REG 0x40020000						// dma	
#define FIREWALL_REG 0x40011C00
#define I2C_REG 0x40005400						// I2C
#define EXTENDED_INTERRUPT_REG 0x40010400		// interrupt
#define POWER_CONTROL_REG ((PWD_TypeDef *) 0x40007000)
#define RCC_REG 0x40021000
#define RTC_REG ((RTC_TypeDef *) 0x40002800)						// RTC
#define SPI_REG 0x40013000						// SPI
#define SYS_CFG_REG ((SYSCFG_TypeDef *) 0x40010000)
#define LPTIM_REG ((LPTIM_TypeDef *) 0x40007C00)					// timers
#define TIM2_REG ((TIM_TypeDef *) 0x40000000)                     	// end 0x4000 03FF
#define TIM21_REG ((TIM_TypeDef *) 0x40010800)
#define TIM22_REG ((TIM_TypeDef *) 0x40011400)
#define LPUART1_REG 0x40004800					// UART
#define USART2_REG 0x40004400
#define SYSTEM_WATCHDOG_REG ((WWDG_TypeDef *) 0x40002C00)			// watchdogs
#define INDEPENDENT_WATCHDOG_REG ((IWDG_TypeDef *) 0x40003000)

// Memory
#define EEPROM_REG 0x08080000					// EEPROM
#define AHB_FLASH_REG 0x40022000				// FLASH
#define NVM_FLASH_REG 0x08000000
#define SRAM_REG 0x20000000						// SRAM

// GPIO
#define GPIOA_ ((GPIOx_TypeDef *) 0x50000000)
#define GPIOB_ ((GPIOx_TypeDef *) 0x50000400)
#define GPIOC_ ((GPIOx_TypeDef *) 0x50000800)
#define GPIOD_ ((GPIOx_TypeDef *) 0x50000C00)
#define GPIOE_ ((GPIOx_TypeDef *) 0x50001000)
#define GPIOH_ ((GPIOx_TypeDef *) 0x48001C00)



typedef struct _ADC
{
	volatile uint32_t ADC_ISR;
	volatile uint32_t ADC_IER;
	volatile uint32_t ADC_CR;
	volatile uint32_t ADC_CFGR1;
	volatile uint32_t ADC_CFGR2;
	volatile uint32_t ADC_SMPR;
	volatile uint32_t RESERVED[2];
	volatile uint32_t ADC_TR;
	volatile uint32_t RESERVED2;
	volatile uint32_t ADC_CHSELR;
	volatile uint32_t RESERVED3[5];
	volatile uint32_t ADC_DR;
	volatile uint32_t RESERVED4[28];
	volatile uint32_t ADC_CALCFACT;
} ADC_Typedef;


typedef struct _CRC
{
	volatile
}CRC_TypeDef;


typedef struct _DMA								// do złożenia z DMA_channel
{
	volatile uint32_t ISR;
	volatile uint32_t IFCR;
	volatile uint32_t RESERVED[40];				// RESERVED[5]
	volatile uint32_t CSELR;
}DMA_TypeDef;


// DMA Channel
typedef struct _DMA_CHANNEL
{
  volatile uint32_t CCR;     /*!< DMA channel x configuration register,          Offset: 0x00 */
  volatile uint32_t CNDTR;   /*!< DMA channel x number of data to transfer,      Offset: 0x04 */
  volatile uint32_t CPAR;    /*!< DMA channel x peripheral address register,     Offset: 0x08 */
  volatile uint32_t CMAR;    /*!< DMA channel x memory address register,         Offset: 0x0C */
  uint32_t RESERVED;         /*!< Rezerwacja (padding) między kanałami,          Offset: 0x10 */
} DMA_Channel_TypeDef;


// GPIO registers
typedef struct _GPIO
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
	volatile uint32_t BRR;
}GPIOx_TypeDef;					// GPIOx;


typedef struct _PWD
{
	volatile uint32_t CR;
	volatile uint32_t CSR;
}PWD_TypeDef;


//RCC
typedef struct _RCC
{
	volatile uint32_t CR;
	volatile uint32_t ICSCR;
	volatile uint32_t RESERVED;
	volatile uint32_t CFGR;
	volatile uint32_t CIER;
	volatile uint32_t CIFR;
	volatile uint32_t CICR;
	volatile uint32_t IOPRSTR;
	volatile uint32_t AHBRSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t IOPENR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t IOPSMEN;
	volatile uint32_t AHBSMENR;
	volatile uint32_t APB2SMENR;
	volatile uint32_t APB1SMENR;
	volatile uint32_t CCIPR;
	volatile uint32_t CSR;
}RCC_TypeDef;


// RTC
typedef struct _RTC
{
	volatile uint32_t TR;
	volatile uint32_t DR;
	volatile uint32_t CR;
	volatile uint32_t ISR;
	volatile uint32_t PRER;
	volatile uint32_t WUTR;
	volatile uint32_t ALRMAR;
	volatile uint32_t ALRMBR;
	volatile uint32_t WPR;
	volatile uint32_t SRR;
	volatile uint32_t SHIFTR;
	volatile uint32_t TSTR;
	volatile uint32_t TSDR;
	volatile uint32_t TSSSR;
	volatile uint32_t CALR;
	volatile uint32_t TAMPCR;
	volatile uint32_t ALRMASSR;
	volatile uint32_t ALRMBSSR;
	volatile uint32_t OR;
	volatile uint32_t BKPOR;
	volatile uint32_t BKP4R;
}RTC_TypeDef;


// SYS_CFG_REG
typedef struct _SYSTEM_CONFIG
{
  volatile uint32_t CFGR1;     /*!< SYSCFG memory remap register,                    Offset: 0x00 */
  volatile uint32_t CFGR2;     /*!< SYSCFG peripheral mode configuration register,    Offset: 0x04 */
  volatile uint32_t EXTICR[4]; /*!< SYSCFG external interrupt configuration registers, Offset: 0x08-0x14 */
  uint32_t RESERVED[2];        /*!< Rezerwacja pamięci (2 rejestry 32-bitowe),       Offset: 0x18-0x1C */
  volatile uint32_t CFGR3;     /*!< SYSCFG reference control and status register,     Offset: 0x20 */
}SYSCFG_TypeDef;


// Timers
typedef struct _TIMx
{
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2_TIM2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RESERVED;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3_TIM2;
	volatile uint32_t CCR4_TIM2;
	volatile uint32_t RESERVED2;
	volatile uint32_t DCR_TIM2;
	volatile uint32_t DMAR_TIM2;
	volatile uint32_t OR;
}TIM_TypeDef;

// Low Power Timer
typedef struct _LPTIM
{
	volatile uint32_t ISR;
	volatile uint32_t ICR;
	volatile uint32_t IER;
	volatile uint32_t CFGR;
	volatile uint32_t CR;
	volatile uint32_t CMP;
	volatile uint32_t ARR;
	volatile uint32_t CNT;
}LPTIM_TypeDef;

typedef struct _IWDG
{
	volatile uint32_t KR;
	volatile uint32_t PR;
	volatile uint32_t RLR;
	volatile uint32_t SR;
	volatile uint32_t WINR;
}IWDG_TypeDef;

typedef struct _WWDG
{
	volatile uint32_t CR;
	volatile uint32_t CFR;
	volatile uint32_t SR;
}WWDG_TypeDef;



	GPIOG_->MODER = ((GPIOG_->MODER | 0x1 << port32_0) & ~(0x2 << port32_0));