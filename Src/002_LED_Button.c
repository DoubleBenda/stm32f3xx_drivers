/*
 * 002_LED_Button.c
 *
 *  Created on: 16 ott 2026
 *      Author: drbg
 */

#include "stm32f303xx.h"

void delay(void)
{
	for(uint32_t i = 0; i < 150000; i++)
	{

	}
}

int main(void)
{
	// Creiamo variabili Handle per le porte GPIO che ci interessano, una per il LED e l'altra per il Bottone
	GPIO_Handle_t GPIO_Led = {0}, GPIO_Btn = {0};

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
	GPIO_Btn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;		// La modalita è "Input"
	GPIO_Btn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
	GPIO_Btn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;	// non abbiamo bisogno delle resistenze di Pull Up o Pull Down

	// Abilitazione dei clock delle periferiche
	GPIO_PeripheralClockControl(GPIO_Led.pGPIOx, ENABLE);
	GPIO_PeripheralClockControl(GPIO_Btn.pGPIOx, ENABLE);

	// Inizializzazione delle Periferiche utilizzate
	GPIO_Init(&GPIO_Led);
	GPIO_Init(&GPIO_Btn);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIO_Btn.pGPIOx, GPIO_Btn.GPIO_PinConfig.GPIO_PinNumber) == BUTTON_PRESSED)
		{
			GPIO_WriteToOutputPin(GPIO_Led.pGPIOx,GPIO_Led.GPIO_PinConfig.GPIO_PinNumber,HIGH);
		}
		else
		{
			GPIO_WriteToOutputPin(GPIO_Led.pGPIOx,GPIO_Led.GPIO_PinConfig.GPIO_PinNumber,LOW);
		}
	}
	return 0;
}
