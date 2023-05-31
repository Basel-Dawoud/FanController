 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Basel Dawoud
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	AREF /*Internal Vref turned off*/,AVCC /*with external capacitor at AREF pin*/,Reserved,Internal_2_56v /*Internal 2.56V Voltage Reference with external capacitor at AREF pin*/
}ADC_ReferenceVolatge;

typedef enum
{
	DF_2 , DF_2_, DF_8, DF_16, DF_32, DF_64, DF_128
}ADC_Prescaler;


typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/



/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */void ADC_init(const ADC_ConfigType * Config_Ptr);


/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
