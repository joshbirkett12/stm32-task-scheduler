/*
 * tasks.h
 *
 *  Created on: Feb 8, 2026
 *      Author: joshb
 */

#ifndef INC_TASKS_H_
#define INC_TASKS_H_

#include "main.h"

extern volatile uint8_t ten_ms_elapsed;
extern volatile uint8_t hundred_ms_elapsed;
extern volatile uint8_t thousand_ms_elapsed;

void task_10_ms();
void task_100_ms();
void task_1000_ms();


#endif /* INC_TASKS_H_ */
