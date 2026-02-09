/*
 * tasks.c
 *
 *  Created on: Feb 8, 2026
 *      Author: joshb
 */

#include "tasks.h"

volatile uint8_t ten_ms_elapsed = 0;
volatile uint8_t hundred_ms_elapsed = 0;
volatile uint8_t thousand_ms_elapsed = 0;

void task_10_ms()
{
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_7); //green LED
}

void task_100_ms()
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7); //blue LED
}

void task_1000_ms()
{
	HAL_GPIO_TogglePin(GPIOG, GPIO_PIN_2); //red LED
}

