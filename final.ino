 // this is the header file that tells the compiler what pins and ports, etc.
 // are available on this chip.
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

//#include <stdlib.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>



#ifndef BAUD
#define BAUD 9600
#endif
#include <util/setbaud.h>

/* http://www.cs.mun.ca/~rod/Winter2007/4723/notes/serial/serial.html */



int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);

void uart_init(void);

void uart_init(void) {
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */ 
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);   /* Enable RX and TX */    
}

int uart_putchar(char c, FILE *stream) {
    if (c == '\n') {
        uart_putchar('\r', stream);
    }
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
    return 0;
}

int uart_getchar(FILE *stream) {
    loop_until_bit_is_set(UCSR0A, RXC0);
    return UDR0;
}

/* http://www.ermicro.com/blog/?p=325 */








 
 // define what pins the LEDs are connected to.
 // in reality, PD6 is really just '6'
 #define LED PB5   
 
 // Some macros that make the code more readable
 #define output_low(port,pin) port &= ~(1<<pin)
 #define output_high(port,pin) port |= (1<<pin)
 #define set_input(portdir,pin) portdir &= ~(1<<pin)
 #define set_output(portdir,pin) portdir |= (1<<pin)
 
 // this is just a program that 'kills time' in a calibrated method
 void delay_ms(uint8_t ms) {
   uint16_t delay_count = F_CPU / 17500;
   volatile uint16_t i;
 
   while (ms != 0) {
     for (i=0; i != delay_count; i++);
     ms--;
   }
 }
 int main(void) {
   // initialize the direction of PORTD #6 to be an output
   set_output(DDRB, LED);  
 int i = 0 ;
    uart_init();
   while (1) {
     // turn on the LED for 200ms
   
     // now start over
    
  output_high(PORTB, LED);
     delay_ms(200);
     // now turn off the LED for another 200ms
     output_low(PORTB, LED);
     delay_ms(200);
     
        uart_putchar('F',stdout);
        delay_ms(1000);
        i++;
   }
}

