/*
 * Blinking_led_class_2_23-10-2017.c
 *
 * Created: 10/23/2017 11:52:39 AM
 * Author : user-5
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD = 0xff;
	/* Replace with your application code */
    while (1) 
    {
		for (int i=0; i<8; i++)
		{
				PORTD |= (1<<i);
				_delay_ms(500);
		}
		
		for (int k=7; k>=0; k--)
		{
			PORTD &=~ (1<<k);
			_delay_ms(500);
		}
	
    }
	
	return 0;
}

