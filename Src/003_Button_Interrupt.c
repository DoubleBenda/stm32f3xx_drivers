/*
 * 003_Button_Interrupt.c
 *
 *  Created on: 23 ott 2026
 *      Author: drbg
 */

#include "stm32f303xx.h"

// Creiamo variabili Handle per le porte GPIO che ci interessano, una per il LED e l'altra per il Bottone
GPIO_Handle_t GPIO_Led = {0};
GPIO_Handle_t GPIO_Btn = {0};

int main (void)
{
	// Configurazione LED ****************************************
	GPIO_Led.pGPIOx = GPIOA;
	GPIO_Led.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GPIO_Led.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_Led.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GPIO_Led.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_Led.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	// Configurazione User Button ****************************************
	GPIO_Btn.pGPIOx = GPIOC;
	GPIO_Btn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;	// il bottone è connesso al pin 11 della porta GPIO I
	GPIO_Btn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_RT;		// La modalita è "Input"
	GPIO_Btn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GPIO_Btn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;	// non abbiamo bisogno delle resistenze di Pull Up o Pull Down

	// Abilitazione dei clock delle periferiche
	GPIO_PeripheralClockControl(GPIO_Led.pGPIOx, ENABLE);
	GPIO_PeripheralClockControl(GPIO_Btn.pGPIOx, ENABLE);

	// Inizializzazione delle Periferiche utilizzate
	GPIO_Init(&GPIO_Led);
	GPIO_Init(&GPIO_Btn);

	//IRQ configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10, NVIC_IRQ_PRIORITY_0);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10, ENABLE);

	while(1)
	{

	}

	return 0;
}

void EXTI15_10_IRQHandler(void)
{
	GPIO_IRQHandling(GPIO_Led.GPIO_PinConfig.GPIO_PinNumber);

	GPIO_ToggleOutputPin(	GPIO_Led.pGPIOx,
							GPIO_Led.GPIO_PinConfig.GPIO_PinNumber
							);
}






