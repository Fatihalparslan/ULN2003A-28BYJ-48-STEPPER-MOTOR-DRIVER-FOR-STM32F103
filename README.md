# ULN2003A-28BYJ-48-STEPPER-MOTOR-DRIVER-FOR-STM32F103
This repository contains a header file, a source file, and a main.c file, which is the stm32f103 driver for the 28byj -48 stepper motor.

![alt text](https://github.com/Fatihalparslan/ULN2003A-28BYJ-48-STEPPER-MOTOR-DRIVER-FOR-STM32F103/blob/main/uln2003a.jpg)

In order for the code to work correctly, the connections must be as above.
If you want to connect the inputs of the ULN2003A circuit to different GPIO pins than in the example. You need to change the pin and port definitions in the uln2003a_28byj48.h file.
![alt text](https://controllerstech.com/wp-content/uploads/2018/06/5-768x309.jpg)

# void half_step(uint8_t step_count): 
The table above shows the step numbers and the logic levels applied to the input of the ULN2003A according to these numbers. The half_step function takes the step number as input and outputs the logic level corresponding to the step number from the GPIO pins.
# void CCW_Drive_HalfStep_Number(uint16_t step_number):
This function causes the motor to rotate counterclockwise in half steps as the number of step_numbers.
# void CW_Drive_HalfStep_Number(uint16_t step_number):
This function causes the motor to rotate clockwise in half steps as the number of step_numbers.
# void CW_angluar_drive(uint16_t angle): 
This function allows the stepper motor to rotate clockwise as much as the angle value entered.
# void CCW_angluar_drive(uint16_t angle): 
This function allows the stepper motor to rotate counterclockwise as much as the angle value entered.
