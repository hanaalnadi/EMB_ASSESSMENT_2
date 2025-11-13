#include <avr/io.h>
#include "Dio.h"

void DIO_SetPinDirection(unsigned char port, unsigned char pin, unsigned char direction)
{
    switch(port)
    {
        case 'B':
        case 'b':
            if(direction == 'i') DDRB &= ~(1<<pin);
            else DDRB |= (1<<pin);
            break;

        case 'C':
        case 'c':
            if(direction == 'i') DDRC &= ~(1<<pin);
            else DDRC |= (1<<pin);
            break;

        case 'D':
        case 'd':
            if(direction == 'i') DDRD &= ~(1<<pin);
            else DDRD |= (1<<pin);
            break;
    }
}

void DIO_SetPinState(unsigned char port, unsigned char pin, unsigned char state)
{
    switch(port)
    {
        case 'B':
        case 'b':
            if(state == 'l') PORTB &= ~(1<<pin);
            else PORTB |= (1<<pin);
            break;

        case 'C':
        case 'c':
            if(state == 'l') PORTC &= ~(1<<pin);
            else PORTC |= (1<<pin);
            break;

        case 'D':
        case 'd':
            if(state == 'l') PORTD &= ~(1<<pin);
            else PORTD |= (1<<pin);
            break;
    }
}

unsigned char DIO_ReadPin(unsigned char port, unsigned char pin)
{
    switch(port)
    {
        case 'B':
        case 'b':
            return (PINB & (1<<pin)) >> pin;

        case 'C':
        case 'c':
            return (PINC & (1<<pin)) >> pin;

        case 'D':
        case 'd':
            return (PIND & (1<<pin)) >> pin;
    }
    return 0;
}
