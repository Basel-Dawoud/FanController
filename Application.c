/*
 * Application.c
 * Fan_Controller
 *  Created on: ١٣‏/٠٥‏/٢٠٢٣
 *      Author: Basel Dawoud
 */

#include "adc.h"
#include "DC.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "std_types.h"

int main(){

	uint8 temp=0;

	ADC_ConfigType ADC_ConfigType = {Internal_2_56v, DF_8};

	/*Initialization for the modules*/
	ADC_init(&ADC_ConfigType);
	DcMotor_Init();
	LCD_init();
	LCD_displayStringRowColumn(0,3,"FAN IS OFF");
	LCD_displayStringRowColumn(1,3,"Temp=    C");

	for (;;){

		/*Get the sensor value*/
		temp= LM35_getTemperature();

		/*Printing on the LCD*/
		if (temp>=100)
			{
				LCD_moveCursor(1,9);
				LCD_intgerToString(temp);
			}
		else
			{
				LCD_moveCursor(1,9);
				LCD_intgerToString(temp);
				LCD_displayStringRowColumn(1,11," ");
			}

		/* If the temperature is greater than or equal 90C turn on the fan with 75% of its maximum speed */
		if (temp>=90)
		{
			DcMotor_Rotate(A_CW,75);
			LCD_displayStringRowColumn(0,10,"ON ");
		}
		/* If the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed */
		else if(temp>=60)
		{
			DcMotor_Rotate(A_CW,50);
			LCD_displayStringRowColumn(0,10,"ON ");
		}
		/* If the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed */
		else if(temp>=30)
		{
			DcMotor_Rotate(A_CW,25);
			LCD_displayStringRowColumn(0,10,"ON ");
		}
		/* If the temperature is less than 30C turn off the fan */
		else
		{
			DcMotor_Rotate(STOP,0);
			LCD_displayStringRowColumn(0,10,"OFF");
		}
	}
	return 0;
}
