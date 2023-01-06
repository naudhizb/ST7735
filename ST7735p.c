/*
 * ST7735p.c
 *
 *  Created on: 2023. 1. 6.
 *      Author: mjlee2
 */

#include "main.h"
#include "ST7735p.h"

extern SPI_HandleTypeDef hspi1;



void ST7735p_Delay(unsigned int ms)
{
	HAL_Delay(ms);
}

void ST7735p_Init()
{
	/* Initialize GPIO, SPI and RESET */
	HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(BL_GPIO_Port, BL_Pin, GPIO_PIN_SET);
	ST7735p_Reset();
}

void ST7735p_Reset()
{
	HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_SET);
	ST7735p_Delay(500);
	HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_RESET);
	ST7735p_Delay(500);
	HAL_GPIO_WritePin(RST_GPIO_Port, RST_Pin, GPIO_PIN_SET);

}

void ST7735p_Send(unsigned char type, unsigned char data)
{
	/* Change Data/Command, Send Data */
	HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, !!type);
	HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, &data, 1, 100);
	HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_SET);
}

void ST7735p_SetDC(unsigned char DC)
{
	// 1- Data, 0- Command
}
