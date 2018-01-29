/*
 * conveyer_motor_atmega328p.c
 *
 * Created: 11/19/2017 2:41:17 PM
 * Author : HP USER
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	DDRD=0b00000011;
	/* Replace with your application code */
	while (1)
	{
		if(PIND & (1<<PIND3))
		{
			PORTD=(1<<PORTD1);
			PORTD &=~(1<<PORTD0);
			
			
		}
		
		else if(PIND & (1<<PIND4))
		
		{
			PORTD&=~(1<<PORTD1);
			PORTD =(1<<PORTD0);
			
			
			
		}
		
		//_delay_ms(100);
	}
}
