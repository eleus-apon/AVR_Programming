/*
 * GccApplication1.c
 *
 * Created: 10/24/2017 1:47:24 PM
 * Author : user-5
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0xFF;
	DDRB = 0xFF;
	char seven_seg[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x6f};
		
    while (1) 
    {
		for (int i=0;i<=9;i++)
		{
		
			for (int j=0; j<=9;j++)
			{
				
				PORTB = 1;
				PORTD = seven_seg[i];
				//_delay_ms(250);
				
				PORTB = 2;
				PORTD = seven_seg[j];
				_delay_ms(250);
			}
			 
		}
    }
	
	return 0;
}

