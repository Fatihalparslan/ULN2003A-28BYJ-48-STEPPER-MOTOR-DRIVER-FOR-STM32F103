/*
 * uln2003a_28byj48.c
 *
 *  Created on: Jan 30, 2022
 *      Author: Fatih Alparslan
 */
#include"uln2003a_28byj48.h"

void half_step(uint8_t step_count){

	if(step_count<9 && step_count>0){
		switch(step_count){
		case 1:
			/*
			IN1->1
			IN2->0
			IN3->0
			IN4->0
			*/
			ULN_IN1_GPORT->BSRR|= ULN_IN1_GPIN;
			ULN_IN2_GPORT->BRR |= ULN_IN2_GPIN;
			ULN_IN3_GPORT->BRR |= ULN_IN3_GPIN;
			ULN_IN4_GPORT->BRR |= ULN_IN4_GPIN;
			HAL_Delay(1);
			ULN_IN1_GPORT->BRR |= ULN_IN1_GPIN;
			break;
		case 2:
			/*
			IN1->1
			IN2->1
			IN3->0
			IN4->0
			*/
			ULN_IN1_GPORT->BSRR|= ULN_IN1_GPIN;
			ULN_IN2_GPORT->BSRR|= ULN_IN2_GPIN;
			ULN_IN3_GPORT->BRR |= ULN_IN3_GPIN;
			ULN_IN4_GPORT->BRR |= ULN_IN4_GPIN;
			HAL_Delay(1);
			ULN_IN1_GPORT->BRR |= ULN_IN1_GPIN;
			ULN_IN2_GPORT->BRR |= ULN_IN2_GPIN;
			break;
		case 3:
			/*
			IN1->0
			IN2->1
			IN3->0
			IN4->0
			*/
			ULN_IN1_GPORT->BRR |= ULN_IN1_GPIN;
			ULN_IN2_GPORT->BSRR|= ULN_IN2_GPIN;
			ULN_IN3_GPORT->BRR |= ULN_IN3_GPIN;
			ULN_IN4_GPORT->BRR |= ULN_IN4_GPIN;
			HAL_Delay(1);
			ULN_IN2_GPORT->BRR |= ULN_IN2_GPIN;
			break;
		case 4:
			/*
			IN1->0
			IN2->1
			IN3->1
			IN4->0
			*/
			ULN_IN1_GPORT->BRR |= ULN_IN1_GPIN;
			ULN_IN2_GPORT->BSRR|= ULN_IN2_GPIN;
			ULN_IN3_GPORT->BSRR|= ULN_IN3_GPIN;
			ULN_IN4_GPORT->BRR |= ULN_IN4_GPIN;
			HAL_Delay(1);
			ULN_IN2_GPORT->BRR |= ULN_IN2_GPIN;
			ULN_IN3_GPORT->BRR |= ULN_IN3_GPIN;
			break;
		case 5:
			/*
			IN1->0
			IN2->0
			IN3->1
			IN4->0
			*/
			ULN_IN1_GPORT->BRR |= ULN_IN1_GPIN;
			ULN_IN2_GPORT->BRR |= ULN_IN2_GPIN;
			ULN_IN3_GPORT->BSRR|= ULN_IN3_GPIN;
			ULN_IN4_GPORT->BRR |= ULN_IN4_GPIN;
			HAL_Delay(1);
			ULN_IN3_GPORT->BRR |= ULN_IN3_GPIN;
			break;
		case 6:
			/*
			IN1->0
			IN2->0
			IN3->1
			IN4->1
			*/
			ULN_IN1_GPORT->BRR |= ULN_IN1_GPIN;
			ULN_IN2_GPORT->BRR |= ULN_IN2_GPIN;
			ULN_IN3_GPORT->BSRR|= ULN_IN3_GPIN;
			ULN_IN4_GPORT->BSRR|= ULN_IN4_GPIN;
			HAL_Delay(1);
			ULN_IN3_GPORT->BRR |= ULN_IN3_GPIN;
			ULN_IN4_GPORT->BRR |= ULN_IN4_GPIN;
			break;

		case 7:
			/*
			IN1->0
			IN2->0
			IN3->0
			IN4->1
			*/
			ULN_IN1_GPORT->BRR |= ULN_IN1_GPIN;
			ULN_IN2_GPORT->BRR |= ULN_IN2_GPIN;
			ULN_IN3_GPORT->BRR |= ULN_IN3_GPIN;
			ULN_IN4_GPORT->BSRR|= ULN_IN4_GPIN;
			HAL_Delay(1);
			ULN_IN4_GPORT->BRR|= ULN_IN4_GPIN;
			break;

		case 8:
			/*
			IN1->1
			IN2->0
			IN3->0
			IN4->1
			*/
			ULN_IN1_GPORT->BSRR|= ULN_IN1_GPIN;
			ULN_IN2_GPORT->BRR |= ULN_IN2_GPIN;
			ULN_IN3_GPORT->BRR |= ULN_IN3_GPIN;
			ULN_IN4_GPORT->BSRR|= ULN_IN4_GPIN;
			HAL_Delay(1);
			ULN_IN1_GPORT->BRR|= ULN_IN1_GPIN;
			ULN_IN4_GPORT->BRR|= ULN_IN4_GPIN;
			break;

		}
	}


}

void CCW_Drive_HalfStep_Number(uint16_t step_number){
	if(step_number<=4096){
	uint16_t second_loop_vounter=step_number/8;
	uint8_t last_count=step_number%8;
for(uint16_t j=0;j<second_loop_vounter;j++)
  {
	for(int i=1;i<=8;i++){
		half_step(i);

	}
   }

if(last_count){


	for(int i=1;i<last_count;i++){
		half_step(i);

	}
   }
  }
}
void CW_Drive_HalfStep_Number(uint16_t step_number){
	if(step_number<=4096){
	uint16_t second_loop_vounter=step_number/8;
	uint8_t last_count=step_number%8;
for(uint16_t j=0;j<second_loop_vounter;j++)
  {
	for(int i=8;i>0;i--){
		half_step(i);

	}
   }

if(last_count){
	for(int i=8;i>8-last_count;i--){
		half_step(i);

	}
   }
  }
}
void CCW_angluar_drive(uint16_t angle){
	uint16_t mangle=angle%360;
    uint16_t step_angle=(mangle*4096)/360;
    CCW_Drive_HalfStep_Number(step_angle);
}

void CW_angluar_drive(uint16_t angle){
	uint16_t mangle=angle%360;
    uint16_t step_angle=(mangle*4096)/360;
    CW_Drive_HalfStep_Number(step_angle);
}
