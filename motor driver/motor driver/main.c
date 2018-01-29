/*
 * motor driver.c
 *
 * Created: 11/16/2017 3:31:51 PM
 * Author : HP USER
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRC = 0xff;
	/* Replace with your application code */
    while (1) 
    {
		PORTC = 0b00000010;
		_delay_ms(5000);
		PORTC = 0b00000001;
		
    }
}

