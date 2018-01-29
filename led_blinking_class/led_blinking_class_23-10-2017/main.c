/*
 * led_blinking_class_23-10-2017.c
 *
 * Created: 10/23/2017 9:14:22 AM
 * Author : user-5
 */ 

#define F_CPU 8000000UL//
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
    DDRD = 0xff;
	
	/* Replace with your application code */
    while (1) 
    {
		for (int y=7; y>=0; y--)
		{
		PORTD = (1<<y);
		_delay_ms(500);
		//PORTD &=~ (1<<y);
		//_delay_ms(0);
		}
		
		for (int x=0; x<8; x++)
		{
		//PORTD = (1<<x);
		//_delay_ms(500);
		PORTD &=~ (1<<x);
		_delay_ms(0);	
		}

    }
}

