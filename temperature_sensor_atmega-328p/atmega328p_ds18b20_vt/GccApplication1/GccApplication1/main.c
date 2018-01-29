/*
 * GccApplication1.c
 *
 * Created: 11/20/2017 12:03:32 PM
 * Author : HP USER
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include <ds18b20/ds18b20.h>

int main( )
{
	int temp;

	while ( 1 )
	{
		//Start conversion (without ROM matching)
		ds18b20convert( &PORTB, &DDRB, &PINB, ( 1 << 0 ), NULL );

		//Delay (sensor needs time to perform conversion)
		_delay_ms( 1000 );

		//Read temperature (without ROM matching)
		ds18b20read( &PORTB, &DDRB, &PINB, ( 1 << 0 ), NULL, &temp );

		//Somehow use data stored in `temp` variable
	}

	return 0;
}