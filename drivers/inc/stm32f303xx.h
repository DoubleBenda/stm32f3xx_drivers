
/*
 * stm32f303xx.h
 *
 * Created on: 8 ott 2026
 * Author: drbg
 *
 * Definizioni degli indirizzi base di memoria,
 * bus e periferiche per STM32F303RE.
 *
 * Reference Manual: RM0316
 */

#ifndef INC_STM32F303XX_H_
#define INC_STM32F303XX_H_

/*
 * ============================================================
 * INDIRIZZI BASE DELLE PORZIONI DI MEMORIA
 * ============================================================
 */

#define FLASH_BASEADDR        0x08000000U  /* Flash - 512 KB */
#define SRAM_BASEADDR         0x20000000U  /* SRAM - 64 KB */
#define CCM_SRAM_BASEADDR     0x10000000U  /* CCM SRAM - 16 KB */
#define ROM_BASEADDR          0x1FFFD800U  /* System Memory - 8 KB */

/* Alias */
#define SRAM                  SRAM_BASEADDR
#define CCM_SRAM              CCM_SRAM_BASEADDR


/*
 * ============================================================
 * INDIRIZZI BASE DEI BUS
 * ============================================================
 */

#define PERIPH_BASE           0x40000000U

/* Advanced Peripheral Bus */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       0x40010000U

/* Advanced High-performance Bus */
#define AHB1PERIPH_BASE       0x40020000U
#define AHB2PERIPH_BASE       0x48000000U
#define AHB3PERIPH_BASE       0x50000000U


/*
 * ============================================================
 * FMC - MEMORIA ESTERNA (AHB4)
 * ============================================================
 */

#define FMC_BANK1_BASEADDR    0x60000000U
#define FMC_BANK2_BASEADDR    0x70000000U
#define FMC_BANK3_BASEADDR    0x80000000U
#define FMC_BANK4_BASEADDR    0x90000000U

/* Registri di controllo FMC */
#define FMC_CTRL_BASEADDR     0xA0000400U


/*
 * ============================================================
 * PERIFERICHE CONNESSE AL BUS AHB1
 * ============================================================
 */

/* Direct Memory Access */
#define DMA1_BASEADDR         (AHB1PERIPH_BASE + 0x0000U)
#define DMA2_BASEADDR         (AHB1PERIPH_BASE + 0x0400U)

/* Reset and Clock Control */
#define RCC_BASEADDR          (AHB1PERIPH_BASE + 0x1000U)

/* Flash Memory Interface */
#define FLASHINTERFACE_BASEADDR (AHB1PERIPH_BASE + 0x2000U)

/* Cyclic Redundancy Check */
#define CRC_BASEADDR          (AHB1PERIPH_BASE + 0x3000U)

/* Touch Sensing Controller */
#define TSC_BASEADDR          (AHB1PERIPH_BASE + 0x4000U)


/*
 * ============================================================
 * PERIFERICHE CONNESSE AL BUS AHB2
 * ============================================================
 */

/* General Purpose Input/Output */
#define GPIOA_BASEADDR        (AHB2PERIPH_BASE + 0x0000U)
#define GPIOB_BASEADDR        (AHB2PERIPH_BASE + 0x0400U)
#define GPIOC_BASEADDR        (AHB2PERIPH_BASE + 0x0800U)
#define GPIOD_BASEADDR        (AHB2PERIPH_BASE + 0x0C00U)
#define GPIOE_BASEADDR        (AHB2PERIPH_BASE + 0x1000U)
#define GPIOF_BASEADDR        (AHB2PERIPH_BASE + 0x1400U)
#define GPIOG_BASEADDR        (AHB2PERIPH_BASE + 0x1800U)
#define GPIOH_BASEADDR        (AHB2PERIPH_BASE + 0x1C00U)


/*
 * ============================================================
 * PERIFERICHE CONNESSE AL BUS AHB3
 * ============================================================
 */

/* Analog to Digital Converters */
#define ADC_1_2_BASEADDR      (AHB3PERIPH_BASE + 0x0000U)
#define ADC_3_4_BASEADDR      (AHB3PERIPH_BASE + 0x0400U)


/*
 * ============================================================
 * PERIFERICHE CONNESSE AL BUS APB1
 * ============================================================
 */

/* General Purpose / Basic Timers */
#define TIM2_BASEADDR         (APB1PERIPH_BASE + 0x0000U)
#define TIM3_BASEADDR         (APB1PERIPH_BASE + 0x0400U)
#define TIM4_BASEADDR         (APB1PERIPH_BASE + 0x0800U)
#define TIM6_BASEADDR         (APB1PERIPH_BASE + 0x1000U)
#define TIM7_BASEADDR         (APB1PERIPH_BASE + 0x1400U)

/* Real-Time Clock */
#define RTC_BASEADDR          (APB1PERIPH_BASE + 0x2800U)

/* Watchdog Timers */
#define WWDG_BASEADDR         (APB1PERIPH_BASE + 0x2C00U)
#define IWDG_BASEADDR         (APB1PERIPH_BASE + 0x3000U)

/* SPI / I2S */
#define I2S2EXT_BASEADDR      (APB1PERIPH_BASE + 0x3400U)
#define SPI2_BASEADDR         (APB1PERIPH_BASE + 0x3800U)
#define SPI3_BASEADDR         (APB1PERIPH_BASE + 0x3C00U)
#define I2S3EXT_BASEADDR      (APB1PERIPH_BASE + 0x4000U)

/* Alias per periferiche condivise SPI/I2S */
#define I2S2_BASEADDR         SPI2_BASEADDR
#define I2S3_BASEADDR         SPI3_BASEADDR

/* USART / UART */
#define USART2_BASEADDR       (APB1PERIPH_BASE + 0x4400U)
#define USART3_BASEADDR       (APB1PERIPH_BASE + 0x4800U)
#define UART4_BASEADDR        (APB1PERIPH_BASE + 0x4C00U)
#define UART5_BASEADDR        (APB1PERIPH_BASE + 0x5000U)

/* Inter-Integrated Circuit */
#define I2C1_BASEADDR         (APB1PERIPH_BASE + 0x5400U)
#define I2C2_BASEADDR         (APB1PERIPH_BASE + 0x5800U)

/* USB / CAN */
#define USB_BASEADDR          (APB1PERIPH_BASE + 0x5C00U)
#define USB_CAN_SRAM_BASEADDR (APB1PERIPH_BASE + 0x6000U)
#define CAN_BASEADDR          (APB1PERIPH_BASE + 0x6400U)

/* Power Control */
#define PWR_BASEADDR          (APB1PERIPH_BASE + 0x7000U)

/* Digital to Analog Converter */
#define DAC1_BASEADDR         (APB1PERIPH_BASE + 0x7400U)

/* Inter-Integrated Circuit 3 */
#define I2C3_BASEADDR         (APB1PERIPH_BASE + 0x7800U)


/*
 * ============================================================
 * PERIFERICHE CONNESSE AL BUS APB2
 * ============================================================
 */

/* System Configuration Controller */
#define SYSCFG_BASEADDR       (APB2PERIPH_BASE + 0x0000U)

/* External Interrupt Controller */
#define EXTI_BASEADDR         (APB2PERIPH_BASE + 0x0400U)

/* Advanced Control Timers */
#define TIM1_BASEADDR         (APB2PERIPH_BASE + 0x2C00U)
#define TIM8_BASEADDR         (APB2PERIPH_BASE + 0x3400U)
#define TIM20_BASEADDR        (APB2PERIPH_BASE + 0x5000U)

/* Serial Peripheral Interface */
#define SPI1_BASEADDR         (APB2PERIPH_BASE + 0x3000U)
#define SPI4_BASEADDR         (APB2PERIPH_BASE + 0x3C00U)

/* Universal Synchronous/Asynchronous Receiver */
#define USART1_BASEADDR       (APB2PERIPH_BASE + 0x3800U)

/* General Purpose Timers */
#define TIM15_BASEADDR        (APB2PERIPH_BASE + 0x4000U)
#define TIM16_BASEADDR        (APB2PERIPH_BASE + 0x4400U)
#define TIM17_BASEADDR        (APB2PERIPH_BASE + 0x4800U)



/*
 * ============================================================
 * peripheral register definition structure for GPIO
 * ============================================================
 */
typedef struct
{
	volatile uint32_t MODER;     // offset : 0x00
	volatile uint32_t OTYPER;    // offset : 0x04
	volatile uint32_t OSPEEDR;   // offset : 0x08
	volatile uint32_t PUPDR;     // offset : 0x0C
	volatile uint32_t IDR;       // offset : 0x10
	volatile uint32_t ODR;       // offset : 0x14
	volatile uint32_t BSRR;      // offset : 0x18
	volatile uint32_t LCKR;      // offset : 0x1C
	volatile uint32_t AFR[2];    // offset : 0x20 - 0x24
	volatile uint32_t BRR;       // offset : 0x28
}GPIO_RegDef_t;

// Peripheral Definition Macros
#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH ((GPIO_RegDef_t*)GPIOH_BASEADDR)

/*
 * ============================================================
 * peripheral register definition structure for RCC
 * ============================================================
 */
typedef struct
{
	volatile uint32_t CR; 				// offest : 0x00
	volatile uint32_t CFGR;				// offset : 0x04
	volatile uint32_t CIR;				// offset : 0x08
	volatile uint32_t APB2RSTR;			// offset : 0X0C
	volatile uint32_t APB1RSTR;			// offset : 0X10
	volatile uint32_t AHBENR;			// offset : 0X14
	volatile uint32_t APB2ENR;			// offset : 0x18
	volatile uint32_t APB1ENR;			// offset : 0x1C
	volatile uint32_t BDCR;				// offset : 0x20
	volatile uint32_t CSR;				// offset : 0x24
	volatile uint32_t AHBRSTR;			// offset : 0X28
	volatile uint32_t CFGR2;			// offset : 0x2C
	volatile uint32_t CFGR3;			// offset : 0x30
}RCC_RegDef_t;

#define RCC 		((RCC_RegDef_t*) RCC_BASEADDR)
#endif /* INC_STM32F303XX_H_ */
