/*
 ================================================================================================
 Name        : temp_sensor_example.c
 Author      : Mohamed Tarek
 Description : Test the ADC driver designed with polling technique using LM35 Temperature Sensor
 Date        : 5/9/2015
 ================================================================================================
 */

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"

int main(void)
{
	uint8 temp;
	LCD_init(); /* initialize LCD driver */
	ADC_init(); /* initialize ADC driver */

	/* Display this string "Temp =   C" only once on LCD at the first row */
	LCD_displayString("Temp =    C");

    while(1)
    {

    	temp = LM35_getTemperature();

		/* Display the temperature value every time at same position */
		LCD_moveCursor(0,7);
		if(temp >= 100)
		{
			LCD_integerToString(temp);
		}
		else
		{
			LCD_integerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
    }
}
