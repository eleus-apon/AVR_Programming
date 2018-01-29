/*
 * Input.c
 *
 * Created: 11/27/2016 4:50:50 AM
 * Author : Krishna Ray
 */ 
#define F_CPU 8000000UL//Define clock frequency
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRC &= (0<<PC0);
	DDRD |= (1<<PD0);
	uint8_t inputTemp = 0;

    while (1) 
    {
		inputTemp = PINC & 0x01;//High Check
								//pin is pulled up
		if(inputTemp == 0x00){
			PORTD |= (1<<PD0);
		}
		else
		{
			PORTD &=~ (1<<PD0);
		}
    }
}



