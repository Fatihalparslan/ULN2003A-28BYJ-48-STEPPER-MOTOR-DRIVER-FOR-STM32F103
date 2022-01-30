/*
 * uln2003a_28byj48.h
 *
 *  Created on: Jan 30, 2022
 *      Author: Fatih
 */

#ifndef INC_ULN2003A_28BYJ48_H_
#define INC_ULN2003A_28BYJ48_H_

#include "stm32f1xx_hal.h"



#define ULN_IN1_GPORT GPIOA
#define ULN_IN1_GPIN GPIO_PIN_0

#define ULN_IN2_GPORT GPIOA
#define ULN_IN2_GPIN GPIO_PIN_1

#define ULN_IN3_GPORT GPIOA
#define ULN_IN3_GPIN GPIO_PIN_2

#define ULN_IN4_GPORT GPIOA
#define ULN_IN4_GPIN GPIO_PIN_3



void half_step(uint8_t step_count);
void CCW_Drive_HalfStep_Number(uint16_t step_number);
void CW_Drive_HalfStep_Number(uint16_t step_number);
void CW_angluar_drive(uint16_t angle);
void CCW_angluar_drive(uint16_t angle);
#endif /* INC_ULN2003A_28BYJ48_H_ */
