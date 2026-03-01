/*
 * tasks.c
 *
 *  Created on: Feb 8, 2026
 *      Author: joshb
 */

/*******************************************************************************
 * DESCRIPTION: Uses a 10ms timer interrupt to schedule LED blinking tasks at
 * 10ms, 100ms, and 1000ms intervals. If an ms_elapsed flag is still set when
 * the ISR fires again, a task_overrun flag is asserted, indicating the main
 * loop did not complete and clear the flag before the next interrupt occurred.
 ******************************************************************************/

#include "tasks.h"

volatile uint8_t ten_ms_elapsed = 0;
volatile uint8_t hundred_ms_elapsed = 0;
volatile uint8_t thousand_ms_elapsed = 0;
volatile uint8_t task_overrun = 0;
static volatile uint8_t count = 0;

void task_10_ms(void)
{
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin); //green LED
}

void task_100_ms(void)
{
	HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin); //blue LED
}

void task_1000_ms(void)
{
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin); //red LED
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	if(htim->Instance == TIM16)
	{

		count++; //increments every 10ms
		//ms_elapsed flags should be set 0 by main once the task is completed,
	    //otherwise overrun has occured
        if(ten_ms_elapsed)
        {
        	task_overrun = 1;
        }
	    else
	    {
	        ten_ms_elapsed = 1;
	    }

        if(hundred_ms_elapsed)
        {
        	task_overrun = 1;
        }
        else if(count % 10 == 0)
		{
			hundred_ms_elapsed = 1;
		}

        if(thousand_ms_elapsed)
        {
        	task_overrun = 1;
        }
        else if(count % 100 == 0)
		{
			thousand_ms_elapsed = 1;
			count = 0;
		}


	}
}
