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

#include <stdint.h>
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
#define FMC_CTRL_BASEADDR     0xA0000000U

/*
 * ============================================================
 * ARM Cortex Mx Processor NVIC ISERx / NVIC ICERx register Addresses
 * ============================================================
 *
 */
#pragma region CPU_SPECIFIC_DETAILS

#define NVIC_ISER0 				((volatile uint32_t*) 0xE000E100)
#define NVIC_ISER1 				((volatile uint32_t*) 0xE000E104)
#define NVIC_ISER2 				((volatile uint32_t*) 0xE000E108)
#define NVIC_ISER3 				((volatile uint32_t*) 0xE000E10C)

#define NVIC_ICER0 				((volatile uint32_t*) 0xE000E180)
#define NVIC_ICER1 				((volatile uint32_t*) 0xE000E184)
#define NVIC_ICER2 				((volatile uint32_t*) 0xE000E188)
#define NVIC_ICER3 				((volatile uint32_t*) 0xE000E18C)

#define NVIC_PR_BASE_ADDR   	((volatile uint32_t*) 0xE000E400)

# define NO_PR_BITS_IMPLEMENTED 4

#pragma endregion

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
	volatile uint32_t CR; 				// offset : 0x00
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

/*
 * ============================================================
 * peripheral register definition structure for EXTI
 * ============================================================
 */
typedef struct
{
	volatile uint32_t IMR1; 		/* Interrupt Mask Register 1 */
	volatile uint32_t EMR1; 		/* Event Mask Register 1 */
	volatile uint32_t RTSR1; 		/* Rising Trigger Selection Register 1 */
	volatile uint32_t FTSR1;	 	/* Falling Trigger Selection Register 1 */
	volatile uint32_t SWIER1; 		/* Software Interrupt Event Register 1 */
	volatile uint32_t PR1; 			/* Pending Register 1 */
	volatile uint32_t IMR2; 		/* Interrupt Mask Register 2 */
	volatile uint32_t EMR2; 		/* Event Mask Register 2 */
	volatile uint32_t RTSR2; 		/* Rising Trigger Selection Register 2 */
	volatile uint32_t FTSR2;	 	/* Falling Trigger Selection Register 2 */
	volatile uint32_t SWIER2; 		/* Software Interrupt Event Register 2 */
	volatile uint32_t PR2; 			/* Pending Register 2 */
}EXTI_Reg_Def_t;

#define EXTI		((EXTI_Reg_Def_t*) EXTI_BASEADDR)

/*
 * ============================================================
 * peripheral register definition structure for SYSCFG
 * ============================================================
 */
typedef struct
{
    volatile uint32_t CFGR1;       /* Offset: 0x00 */
    volatile uint32_t RCR;         /* Offset: 0x04 */
    volatile uint32_t EXTICR[4];   /* Offset: 0x08 - 0x14 */
    volatile uint32_t CFGR2;       /* Offset: 0x18 */
    uint32_t RESERVED0[11];        /* Offset: 0x1C - 0x44 */
    volatile uint32_t CFGR4;       /* Offset: 0x48 */
    uint32_t RESERVED1;            /* Offset: 0x4C */
    volatile uint32_t CFGR3;       /* Offset: 0x50 */
} SYSCFG_RegDef_t;

#define SYSCFG 		((SYSCFG_RegDef_t*) SYSCFG_BASEADDR)

/* Individual ADC and common-register bases. Existing group aliases retained. */
#define ADC1_BASEADDR          (AHB3PERIPH_BASE + 0x0000U)
#define ADC2_BASEADDR          (AHB3PERIPH_BASE + 0x0100U)
#define ADC12_COMMON_BASEADDR  (AHB3PERIPH_BASE + 0x0300U)
#define ADC3_BASEADDR          (AHB3PERIPH_BASE + 0x0400U)
#define ADC4_BASEADDR          (AHB3PERIPH_BASE + 0x0500U)
#define ADC34_COMMON_BASEADDR  (AHB3PERIPH_BASE + 0x0700U)

/* CLOCK ENABLE / DISABLE MACROS -- STM32F303RE (RM0316).
 * Enable readback supplies the delay before accessing a newly clocked peripheral.
 * These read/modify/write operations are not atomic: serialize concurrent writers.
 * Do not disable SRAM/Flash interface clocks while code or data needs those buses.
 * GPIO definitions describe register blocks; available pins depend on the package.
 */
#define RCC_CLOCK_ENABLE(reg, bit) do {       \
    RCC->reg |= (1U << (bit));               \
    (void)(RCC->reg & (1U << (bit)));         \
} while (0)

#define RCC_CLOCK_DISABLE(reg, bit) do {      \
    RCC->reg &= ~(1U << (bit));              \
} while (0)

/* RCC_AHBENR */
#define DMA1_PCLK_EN()          RCC_CLOCK_ENABLE(AHBENR, 0U)
#define DMA1_PCLK_DI()          RCC_CLOCK_DISABLE(AHBENR, 0U)
#define DMA2_PCLK_EN()          RCC_CLOCK_ENABLE(AHBENR, 1U)
#define DMA2_PCLK_DI()          RCC_CLOCK_DISABLE(AHBENR, 1U)
#define SRAM_PCLK_EN()          RCC_CLOCK_ENABLE(AHBENR, 2U)
#define SRAM_PCLK_DI()          RCC_CLOCK_DISABLE(AHBENR, 2U)
#define FLITF_PCLK_EN()         RCC_CLOCK_ENABLE(AHBENR, 4U)
#define FLITF_PCLK_DI()         RCC_CLOCK_DISABLE(AHBENR, 4U)
#define FMC_PCLK_EN()           RCC_CLOCK_ENABLE(AHBENR, 5U)
#define FMC_PCLK_DI()           RCC_CLOCK_DISABLE(AHBENR, 5U)
#define CRC_PCLK_EN()           RCC_CLOCK_ENABLE(AHBENR, 6U)
#define CRC_PCLK_DI()           RCC_CLOCK_DISABLE(AHBENR, 6U)
#define GPIOH_PCLK_EN()         RCC_CLOCK_ENABLE(AHBENR, 16U)
#define GPIOH_PCLK_DI()         RCC_CLOCK_DISABLE(AHBENR, 16U)
#define GPIOA_PCLK_EN()         RCC_CLOCK_ENABLE(AHBENR, 17U)
#define GPIOA_PCLK_DI()         RCC_CLOCK_DISABLE(AHBENR, 17U)
#define GPIOB_PCLK_EN()         RCC_CLOCK_ENABLE(AHBENR, 18U)
#define GPIOB_PCLK_DI()         RCC_CLOCK_DISABLE(AHBENR, 18U)
#define GPIOC_PCLK_EN()         RCC_CLOCK_ENABLE(AHBENR, 19U)
#define GPIOC_PCLK_DI()         RCC_CLOCK_DISABLE(AHBENR, 19U)
#define GPIOD_PCLK_EN()         RCC_CLOCK_ENABLE(AHBENR, 20U)
#define GPIOD_PCLK_DI()         RCC_CLOCK_DISABLE(AHBENR, 20U)
#define GPIOE_PCLK_EN()         RCC_CLOCK_ENABLE(AHBENR, 21U)
#define GPIOE_PCLK_DI()         RCC_CLOCK_DISABLE(AHBENR, 21U)
#define GPIOF_PCLK_EN()         RCC_CLOCK_ENABLE(AHBENR, 22U)
#define GPIOF_PCLK_DI()         RCC_CLOCK_DISABLE(AHBENR, 22U)
#define GPIOG_PCLK_EN()         RCC_CLOCK_ENABLE(AHBENR, 23U)
#define GPIOG_PCLK_DI()         RCC_CLOCK_DISABLE(AHBENR, 23U)
#define TSC_PCLK_EN()           RCC_CLOCK_ENABLE(AHBENR, 24U)
#define TSC_PCLK_DI()           RCC_CLOCK_DISABLE(AHBENR, 24U)
#define ADC_1_2_PCLK_EN()       RCC_CLOCK_ENABLE(AHBENR, 28U)
#define ADC_1_2_PCLK_DI()       RCC_CLOCK_DISABLE(AHBENR, 28U)
#define ADC_3_4_PCLK_EN()       RCC_CLOCK_ENABLE(AHBENR, 29U)
#define ADC_3_4_PCLK_DI()       RCC_CLOCK_DISABLE(AHBENR, 29U)

/* RCC_APB1ENR */
#define TIM2_PCLK_EN()          RCC_CLOCK_ENABLE(APB1ENR, 0U)
#define TIM2_PCLK_DI()          RCC_CLOCK_DISABLE(APB1ENR, 0U)
#define TIM3_PCLK_EN()          RCC_CLOCK_ENABLE(APB1ENR, 1U)
#define TIM3_PCLK_DI()          RCC_CLOCK_DISABLE(APB1ENR, 1U)
#define TIM4_PCLK_EN()          RCC_CLOCK_ENABLE(APB1ENR, 2U)
#define TIM4_PCLK_DI()          RCC_CLOCK_DISABLE(APB1ENR, 2U)
#define TIM6_PCLK_EN()          RCC_CLOCK_ENABLE(APB1ENR, 4U)
#define TIM6_PCLK_DI()          RCC_CLOCK_DISABLE(APB1ENR, 4U)
#define TIM7_PCLK_EN()          RCC_CLOCK_ENABLE(APB1ENR, 5U)
#define TIM7_PCLK_DI()          RCC_CLOCK_DISABLE(APB1ENR, 5U)
#define WWDG_PCLK_EN()          RCC_CLOCK_ENABLE(APB1ENR, 11U)
#define WWDG_PCLK_DI()          RCC_CLOCK_DISABLE(APB1ENR, 11U)
#define SPI2_PCLK_EN()          RCC_CLOCK_ENABLE(APB1ENR, 14U)
#define SPI2_PCLK_DI()          RCC_CLOCK_DISABLE(APB1ENR, 14U)
#define SPI3_PCLK_EN()          RCC_CLOCK_ENABLE(APB1ENR, 15U)
#define SPI3_PCLK_DI()          RCC_CLOCK_DISABLE(APB1ENR, 15U)
#define USART2_PCLK_EN()        RCC_CLOCK_ENABLE(APB1ENR, 17U)
#define USART2_PCLK_DI()        RCC_CLOCK_DISABLE(APB1ENR, 17U)
#define USART3_PCLK_EN()        RCC_CLOCK_ENABLE(APB1ENR, 18U)
#define USART3_PCLK_DI()        RCC_CLOCK_DISABLE(APB1ENR, 18U)
#define UART4_PCLK_EN()         RCC_CLOCK_ENABLE(APB1ENR, 19U)
#define UART4_PCLK_DI()         RCC_CLOCK_DISABLE(APB1ENR, 19U)
#define UART5_PCLK_EN()         RCC_CLOCK_ENABLE(APB1ENR, 20U)
#define UART5_PCLK_DI()         RCC_CLOCK_DISABLE(APB1ENR, 20U)
#define I2C1_PCLK_EN()          RCC_CLOCK_ENABLE(APB1ENR, 21U)
#define I2C1_PCLK_DI()          RCC_CLOCK_DISABLE(APB1ENR, 21U)
#define I2C2_PCLK_EN()          RCC_CLOCK_ENABLE(APB1ENR, 22U)
#define I2C2_PCLK_DI()          RCC_CLOCK_DISABLE(APB1ENR, 22U)
#define USB_PCLK_EN()           RCC_CLOCK_ENABLE(APB1ENR, 23U)
#define USB_PCLK_DI()           RCC_CLOCK_DISABLE(APB1ENR, 23U)
#define CAN_PCLK_EN()           RCC_CLOCK_ENABLE(APB1ENR, 25U)
#define CAN_PCLK_DI()           RCC_CLOCK_DISABLE(APB1ENR, 25U)
#define PWR_PCLK_EN()           RCC_CLOCK_ENABLE(APB1ENR, 28U)
#define PWR_PCLK_DI()           RCC_CLOCK_DISABLE(APB1ENR, 28U)

#define DAC1_PCLK_EN()          RCC_CLOCK_ENABLE(APB1ENR, 29U)
#define DAC1_PCLK_DI()          RCC_CLOCK_DISABLE(APB1ENR, 29U)
//#define DAC2_PCLK_EN()          RCC_CLOCK_ENABLE(APB1ENR, 26U)
//#define DAC2_PCLK_DI()          RCC_CLOCK_DISABLE(APB1ENR, 26U)

#define I2C3_PCLK_EN()          RCC_CLOCK_ENABLE(APB1ENR, 30U)
#define I2C3_PCLK_DI()          RCC_CLOCK_DISABLE(APB1ENR, 30U)

/* RCC_APB2ENR */
#define SYSCFG_PCLK_EN()        RCC_CLOCK_ENABLE(APB2ENR, 0U)
#define SYSCFG_PCLK_DI()        RCC_CLOCK_DISABLE(APB2ENR, 0U)
#define TIM1_PCLK_EN()          RCC_CLOCK_ENABLE(APB2ENR, 11U)
#define TIM1_PCLK_DI()          RCC_CLOCK_DISABLE(APB2ENR, 11U)
#define SPI1_PCLK_EN()          RCC_CLOCK_ENABLE(APB2ENR, 12U)
#define SPI1_PCLK_DI()          RCC_CLOCK_DISABLE(APB2ENR, 12U)
#define TIM8_PCLK_EN()          RCC_CLOCK_ENABLE(APB2ENR, 13U)
#define TIM8_PCLK_DI()          RCC_CLOCK_DISABLE(APB2ENR, 13U)
#define USART1_PCLK_EN()        RCC_CLOCK_ENABLE(APB2ENR, 14U)
#define USART1_PCLK_DI()        RCC_CLOCK_DISABLE(APB2ENR, 14U)
#define SPI4_PCLK_EN()          RCC_CLOCK_ENABLE(APB2ENR, 15U)
#define SPI4_PCLK_DI()          RCC_CLOCK_DISABLE(APB2ENR, 15U)
#define TIM15_PCLK_EN()         RCC_CLOCK_ENABLE(APB2ENR, 16U)
#define TIM15_PCLK_DI()         RCC_CLOCK_DISABLE(APB2ENR, 16U)
#define TIM16_PCLK_EN()         RCC_CLOCK_ENABLE(APB2ENR, 17U)
#define TIM16_PCLK_DI()         RCC_CLOCK_DISABLE(APB2ENR, 17U)
#define TIM17_PCLK_EN()         RCC_CLOCK_ENABLE(APB2ENR, 18U)
#define TIM17_PCLK_DI()         RCC_CLOCK_DISABLE(APB2ENR, 18U)
#define TIM20_PCLK_EN()         RCC_CLOCK_ENABLE(APB2ENR, 20U)
#define TIM20_PCLK_DI()         RCC_CLOCK_DISABLE(APB2ENR, 20U)

/* I2S and its full-duplex extension share the corresponding SPI clock gate. */
#define I2S2_PCLK_EN()     SPI2_PCLK_EN()
#define I2S2_PCLK_DI()     SPI2_PCLK_DI()
#define I2S2EXT_PCLK_EN()  SPI2_PCLK_EN()
#define I2S2EXT_PCLK_DI()  SPI2_PCLK_DI()
#define I2S3_PCLK_EN()     SPI3_PCLK_EN()
#define I2S3_PCLK_DI()     SPI3_PCLK_DI()
#define I2S3EXT_PCLK_EN()  SPI3_PCLK_EN()
#define I2S3EXT_PCLK_DI()  SPI3_PCLK_DI()

/* DAC1 includes both DAC channels. DAC2EN (APB1 bit 26) is reserved on F303RE.
 * RTC uses BDCR.RTCEN, a selected clock source and backup-domain write access.
 * IWDG uses LSI; EXTI has no separate RCC peripheral clock gate.
 * ADC gates alone do not configure the ADC conversion clock.
 */

/* GPIOx PERIPHERALS RESET MACROS */
#define GPIOA_REG_RESET()			do{(RCC->AHBRSTR |= (1 << 17));  (RCC->AHBRSTR &= ~(1 << 17));} while(0)
#define GPIOB_REG_RESET()			do{(RCC->AHBRSTR |= (1 << 18));  (RCC->AHBRSTR &= ~(1 << 18));} while(0)
#define GPIOC_REG_RESET()			do{(RCC->AHBRSTR |= (1 << 19));  (RCC->AHBRSTR &= ~(1 << 19));} while(0)
#define GPIOD_REG_RESET()			do{(RCC->AHBRSTR |= (1 << 20));  (RCC->AHBRSTR &= ~(1 << 20));} while(0)
#define GPIOE_REG_RESET()			do{(RCC->AHBRSTR |= (1 << 21));  (RCC->AHBRSTR &= ~(1 << 21));} while(0)
#define GPIOF_REG_RESET()			do{(RCC->AHBRSTR |= (1 << 22));  (RCC->AHBRSTR &= ~(1 << 22));} while(0)
#define GPIOG_REG_RESET()			do{(RCC->AHBRSTR |= (1 << 23));  (RCC->AHBRSTR &= ~(1 << 23));} while(0)
#define GPIOH_REG_RESET()			do{(RCC->AHBRSTR |= (1 << 16));  (RCC->AHBRSTR &= ~(1 << 16));} while(0)

// Utility Macros
#define ENABLE      1
#define DISABLE     0
#define SET         ENABLE
#define RESET       DISABLE
#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET
#define HIGH ENABLE
#define LOW DISABLE
#define BUTTON_PRESSED LOW
#define BUTTON_NOT_PRESSED HIGH

#include "stm32f303xx_gpio_driver.h"

#endif /* INC_STM32F303XX_H_ */
