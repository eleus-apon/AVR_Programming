/*
 * GccApplication1.c
 *
 * Created: 12/6/2017 12:50:38 PM
 * Author : HP USER
 */ 

#include <avr/io.h>


#define LED_PORT PB3

int main(void) {

	DDRB |= (1 << LED_PORT);

	while (1) {
		
		if (PCINT0==0){
		PORTB |= (1 << LED_PORT);	
		}				
		else
		
		PORTB &= ~(1 << LED_PORT);
	}

	return (0);
}
