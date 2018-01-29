/*
 * GccApplication1.c
 *
 * Created: 11/21/2017 3:01:06 PM
 * Author : Md Eleus Ali
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL//
#include <util/delay.h>
#include <stdlib.h>
#define BAUDRATE 19200
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

uint16_t adc_value;  
void adc_init(void); 
uint16_t read_adc(uint8_t channel);    
void USART_init(void);          
void USART_send( unsigned char data);   
void USART_putstring(char* StringPtr);  

int main(void){
	adc_init();     
	USART_init();     
	DDRC = 0xff;
	DDRB = 0xff;
	
	while(1){
		uint16_t x= read_adc(0);
		uint16_t result = x/2.0533; //as refernece voltage 5V=5000
		
		char buffer[5];
		utoa(result,buffer,10);
		USART_putstring("Temperature[^C] :");
		USART_putstring(buffer);
		USART_send(13);
		_delay_ms(100);
		
		if(result>50)
		{
			USART_putstring("Alert! High ");
			PORTB|=(1<<PORTB0);
			PORTB|=(1<<PORTB1);
			//PORTB|=(1<<PORTB2);	
		}
		
		else 		
		{
			PORTB&=~(1<<PORTB0);
			PORTB&=~(1<<PORTB1);
			PORTB&=~(1<<PORTB2);		
		}
		
	}
	
	return 0;
}

void adc_init(void){
	ADCSRA = ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)); 
	ADMUX = (1<<REFS0);         
	ADCSRA |= (1<<ADEN);       
	ADCSRA |= (1<<ADSC);              
}

uint16_t read_adc(uint8_t channel){
	ADMUX &= 0xF0;                
	ADMUX |= channel;              
	ADCSRA |= (1<<ADSC);              
	while(ADCSRA & (1<<ADSC));           
	return ADC;                 
}

void USART_init(void){
	
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (3<<UCSZ00);
}

void USART_send( unsigned char data){
	
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
		
}

void USART_putstring(char* StringPtr){
	
	while(*StringPtr != 0x00){
		
		USART_send(*StringPtr);
		StringPtr++;
	}
	
}
