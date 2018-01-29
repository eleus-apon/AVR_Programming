/*
 * seven_segment_23-10-2017.c
 *
 * Created: 10/23/2017 2:06:30 PM
 * Author : user-5
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

//#define PORT_7_SEGMENT PORTD
//#define DDR_7_SEGMENT DDRD


int main(void)
{
    char seg_code[]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0xff,0x6f};
	DDRD = 0xff;
	DDRC =0xff;

    while (1) 
    {
		for (int i=0; i<=9; i++)
		{
			for (int j=0; j<=9; j++)
			{
				PORTC = seg_code[i];				
				PORTD = seg_code[j];
				_delay_ms(500);

			}
		}
		/*PORTD |= (1<<PD1);
		PORTD |= (1<<PD2);
		_delay_ms(500);
		PORTD=0x00;

		
		PORTD |= (1<<PD0);
		PORTD |= (1<<PD1);	
		PORTD |= (1<<PD6);
		PORTD |= (1<<PD4);
		PORTD |= (1<<PD3);
		_delay_ms(500);
		PORTD=0x00;

		
		PORTD |= (1<<PD0);
		PORTD |= (1<<PD1);
		PORTD |= (1<<PD6);
		PORTD |= (1<<PD2);
		PORTD |= (1<<PD3);
		_delay_ms(500);
		PORTD=0x00;

		
		PORTD |= (1<<PD5);
		PORTD |= (1<<PD1);
		PORTD |= (1<<PD6);
		PORTD |= (1<<PD2);
		_delay_ms(500);
		PORTD=0x00;

		
		PORTD |= (1<<PD0);
		PORTD |= (1<<PD5);
		PORTD |= (1<<PD6);
		PORTD |= (1<<PD2);
		PORTD |= (1<<PD3);
		_delay_ms(500);
		PORTD=0x00;

		
		PORTD |= (1<<PD0);
		PORTD |= (1<<PD5);
		PORTD |= (1<<PD6);
		PORTD |= (1<<PD4);
		PORTD |= (1<<PD3);
		PORTD |= (1<<PD2);
		_delay_ms(500);
		PORTD=0x00;
		


		PORTD |= (1<<PD0);
		PORTD |= (1<<PD1);
		PORTD |= (1<<PD2);
		_delay_ms(500);	
		PORTD=0x00;	
		
		
		PORTD |= (1<<PD0);
		PORTD |= (1<<PD1);
		PORTD |= (1<<PD2);
		PORTD |= (1<<PD3);
		PORTD |= (1<<PD4);
		PORTD |= (1<<PD5);
		PORTD |= (1<<PD6);		
		_delay_ms(500);	
		PORTD=0x00;	
		
		
		
		PORTD |= (1<<PD0);
		PORTD |= (1<<PD1);
		PORTD |= (1<<PD2);
		PORTD |= (1<<PD3);
		PORTD |= (1<<PD5);
		PORTD |= (1<<PD6);		
		_delay_ms(500);
		PORTD=0x00;
		
		
		PORTD |= (1<<PD0);
		PORTD |= (1<<PD1);
		PORTD |= (1<<PD2);
		PORTD |= (1<<PD3);
		PORTD |= (1<<PD5);
		PORTD |= (1<<PD4);
		_delay_ms(500);
		PORTD=0x00;*/
    }
}

