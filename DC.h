/*
 * DC.h
 *
 *  Created on: ١٣‏/٠٥‏/٢٠٢٣
 *      Author: Basel Dawoud
 */

#ifndef DC_H_
#define DC_H_
#include "std_types.h"
#include "gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define IN1_PORT_ID PORTB_ID
#define IN1_PIN_ID  PIN0_ID
#define IN2_PORT_ID PORTB_ID
#define IN2_PIN_ID  PIN1_ID
#define EN1_PORT_ID PORTB_ID
#define EN1_PIN_ID  PIN3_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	CW,  A_CW, STOP
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
   Description : Function to initialize the DC motor driver

    The Function responsible for setup the direction for the two
	motor pins through the GPIO driver.

    Stop the DC-Motor at the beginning through the GPIO driver.
*/
void DcMotor_Init(void);

/*  The function responsible for rotate the DC Motor CW/ or A-CW or
	stop the motor based on the state input state value.

	Send the required duty cycle to the PWM driver based on the
	required speed value.*/

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_H_ */
