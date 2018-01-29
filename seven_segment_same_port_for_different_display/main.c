/*
 * seven_segment_7447_24-10-2017.c
 *
 * Created: 10/24/2017 8:54:41 AM
 * Author : Eleus
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0xFF;
	int a = 0;
	//char seven_seg[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x6f};
	//_delay_ms(300);
	/* Replace with your application code */
    while (1) 
    {
		
			for (int i=0;i<=9;i++)
			{   
				//_delay_ms(300);
				
				for (int j=0;j<=9;j++)
				{   
					PORTD = j|a;
					_delay_ms(300);
				}
				
				a = a+0b00010000;
				PORTD = a|0;
			}
			a = 0;
			PORTD = 0;
    }	
}

