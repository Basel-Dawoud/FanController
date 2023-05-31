/*
 * DC.c
 *
 *  Created on: ١٣‏/٠٥‏/٢٠٢٣
 *      Author: Basel Dawoud
 */

#include "DC.h"
#include "std_types.h"
#include "gpio.h"
#include "PWM.h"


void DcMotor_Init(void)
{
	/* set up the two pins of the motor as output pins */
	GPIO_setupPinDirection(IN1_PORT_ID,IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(IN2_PIN_ID,IN2_PIN_ID, PIN_OUTPUT);

	/* stop the motor at the start */
	GPIO_writePin(IN1_PORT_ID,IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(IN2_PORT_ID,IN2_PIN_ID, LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	Timer0_PWM_Init(speed);

	switch(state)
	{
	case CW:
		GPIO_writePin(IN1_PORT_ID,IN1_PIN_ID, LOGIC_HIGH);
		GPIO_writePin(IN2_PORT_ID,IN2_PIN_ID, LOGIC_LOW);
		break;

	case A_CW:
		GPIO_writePin(IN1_PORT_ID,IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(IN2_PORT_ID,IN2_PIN_ID, LOGIC_HIGH);
		break;

	case STOP:
		GPIO_writePin(IN1_PORT_ID,IN1_PIN_ID, LOGIC_LOW);
		GPIO_writePin(IN2_PORT_ID,IN2_PIN_ID, LOGIC_LOW);
		break;
	}
}
