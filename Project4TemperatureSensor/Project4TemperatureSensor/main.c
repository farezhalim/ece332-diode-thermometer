/*
 * Project4TemperatureSensor.c
 *
 * Created: 3/6/2017 2:10:00 PM
 * Author : Farez Halim and Tamara Oldham
 */

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include "lcd.h"
#define F_CPU 1000000UL
#include <util/delay.h>
#define SENSOR_MULTIPLIER 0.48828125

int lcd_putchar(char c, FILE *unused)
{
	(void) unused;
	lcd_putc(c);
	return 0;
}
FILE lcd_stream = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);

int main(void) {
	stdout = &lcd_stream;

	lcd_init(LCD_DISP_ON); /* initialize lcd, display on, cursor off */

	ADMUX |= (1 << REFS0); // AVCC with external capacitor at AREF pin
	ADCSRA = (1 << ADEN) | (1 << ADPS2); // initialize ADCSRA, prescaler = 16


	uint16_t adc_resultLM32 = 0;
	uint16_t adc_resultDiode = 0;
	
	uint16_t temp_LM32 = 0;
	uint16_t temp_Diode = 0;
	
	// display the labels on LCD
	lcd_clrscr();             /* clear screen of lcd */
	_delay_ms(50);            /* wait 50ms */

	while(1) {
		// read ADC values		
		ADMUX &= 0xf0;  // clears the bottom 4 bits of ADMUX before OR-ing with selected channel
		ADMUX |= 0x00000000;
		ADCSRA |= (1<<ADSC);
		while( ADCSRA & 0x40 ) {}
		adc_resultLM32 = ADC;
		
		ADMUX &= 0xf0;  // clears the bottom 4 bits of ADMUX before OR-ing with selected channel
		ADMUX |= 0x00000001;
		ADCSRA |= (1<<ADSC);
		while( ADCSRA & 0x40 ) {}
		adc_resultDiode = ADC;
		
		temp_LM32 = adc_resultLM32 * SENSOR_MULTIPLIER;
		temp_Diode = (adc_resultDiode * -3.667) + 362.22;
		
		printf("LM35 : %3d %2d C\n", adc_resultLM32, temp_LM32);
		printf("Diode: %3d %2d C\n", adc_resultDiode, temp_Diode);
		_delay_ms(50);
		

	}

}




