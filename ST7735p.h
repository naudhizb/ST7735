/*
 * ST7735p.h
 *
 *  Created on: 2023. 1. 6.
 *      Author: mjlee2
 */

#ifndef SRC_ST7735P_H_
#define SRC_ST7735P_H_

void ST7735p_Init();
void ST7735p_Reset();
void ST7735p_Send(unsigned char type, unsigned char data);
void ST7735p_SetDC(unsigned char DC);
void ST7735p_Delay(unsigned int ms);

#endif /* SRC_ST7735P_H_ */
