/*
 * 001_LED_Toggle.c
 *
 *  Created on: 15 ott 2026
 *      Author: drbg
 */

//#include <stdint.h>
#include "stm32f303xx.h"

void delay(void)
{
	for(uint32_t i = 0; i < 150000; i++)
	{

	}
}

//#define USE_PUSH_PULL
#define USE_OPEN_DRAIN

#ifdef USE_PUSH_PULL
/* Push Pull Configuration */
int main(void)
{
    /* Loop forever */
	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5; // PA5
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeripheralClockControl(GpioLed.pGPIOx, ENABLE);

	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_ToggleOutputPin(GpioLed.pGPIOx, GpioLed.GPIO_PinConfig.GPIO_PinNumber);
		delay();
	}
	return 0;
}
#endif

#ifdef USE_OPEN_DRAIN
/* Push Pull Configuration */
int main(void)
{
    /* Loop forever */
	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOA;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5; // PA5
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	/*Per pilotare il led con una luminosità accettabile dobbiamo
	 * utilizzare una resistenza di Pull Up Esterna (470 Ohm)*/
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;

	GPIO_PeripheralClockControl(GpioLed.pGPIOx, ENABLE);

	GPIO_Init(&GpioLed);

	while(1)
	{
		GPIO_ToggleOutputPin(GpioLed.pGPIOx, GpioLed.GPIO_PinConfig.GPIO_PinNumber);
		delay();
	}
	return 0;
}
#endif
