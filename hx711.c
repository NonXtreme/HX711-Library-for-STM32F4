/*
 * hx711.c
 *
 *  Created on: 17 Dec 2018
 *      Author: Non Kositkittiwanit
 */

#include "hx711.h"

int HX711_Read(HX711* H) {
	int count = 0;
	_Bool isNegative = 0;
	HAL_GPIO_WritePin(H->PD_SCK_PinType, H->PD_SCK_PinNumber, GPIO_PIN_RESET);
	while (HAL_GPIO_ReadPin(H->DOUT_PinType, H->DOUT_PinNumber)) {

	}
	for (int i = 0; i < 24; i++) {
		HAL_GPIO_WritePin(H->PD_SCK_PinType, H->PD_SCK_PinNumber, GPIO_PIN_SET);
		count = count << 1;
		HAL_GPIO_WritePin(H->PD_SCK_PinType, H->PD_SCK_PinNumber, GPIO_PIN_RESET);
		if (HAL_GPIO_ReadPin(H->DOUT_PinType, H->DOUT_PinNumber)) {
			if (i == 0) {
				isNegative = 1;
			}
			count++;
		}
	}
	if (isNegative) {
		count = count ^ 0xFF000000;
	}
	HAL_GPIO_WritePin(H->PD_SCK_PinType, H->PD_SCK_PinNumber, GPIO_PIN_SET);
	HAL_GPIO_WritePin(H->PD_SCK_PinType, H->PD_SCK_PinNumber, GPIO_PIN_RESET);
	for (int i = 0; i < H->mode; i++) {
		HAL_GPIO_WritePin(H->PD_SCK_PinType, H->PD_SCK_PinNumber, GPIO_PIN_SET);
		HAL_GPIO_WritePin(H->PD_SCK_PinType, H->PD_SCK_PinNumber, GPIO_PIN_RESET);
	}
	return count;
}
