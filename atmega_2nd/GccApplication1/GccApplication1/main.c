/*
 * USART_atmega_328p_terminal.c
 *
 * Created: 11/6/2017 2:20:39 PM
 * Author : user-5
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

void USART_init(void);
unsigned char USART_receive(void);
void USART_send( unsigned char data);

int main(void){
	USART_init();
	DDRC = 0xFF;         
	
	while(1){   
		for(int i=1;i<=63;i++){
			UDR0 = i;
			unsigned char x =USART_receive();
			PORTC = x;
			_delay_ms(250);			
		}
	}
	
	return 0;
}

void USART_init(void){
	
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (3<<UCSZ00);
}

unsigned char USART_receive(void){
	
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
	
}

void USART_send( unsigned char data){
	
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
	
}

