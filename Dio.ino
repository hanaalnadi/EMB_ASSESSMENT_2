#include <avr/io.h>
#include "Dio.h"
#include "BitMath.h"                        // [CHANGED]

void DIO_SetPinDirection(unsigned char port, unsigned char pin, unsigned char direction)
{
    switch(port)
    {
        case 'B':
        case 'b':
            if(direction == 'i') CLR_BIT(DDRB, pin);   // [CHANGED]
            else                 SET_BIT(DDRB, pin);   // [CHANGED]
            break;

        case 'C':
        case 'c':
            if(direction == 'i') CLR_BIT(DDRC, pin);   // [CHANGED]
            else                 SET_BIT(DDRC, pin);   // [CHANGED]
            break;

        case 'D':
        case 'd':
            if(direction == 'i') CLR_BIT(DDRD, pin);   // [CHANGED]
            else                 SET_BIT(DDRD, pin);   // [CHANGED]
            break;
    }
}

void DIO_SetPinState(unsigned char port, unsigned char pin, unsigned char state)
{
    switch(port)
    {
        case 'B':
        case 'b':
            if(state == 'l') CLR_BIT(PORTB, pin);      // [CHANGED]
            else             SET_BIT(PORTB, pin);      // [CHANGED]
            break;

        case 'C':
        case 'c':
            if(state == 'l') CLR_BIT(PORTC, pin);      // [CHANGED]
            else             SET_BIT(PORTC, pin);      // [CHANGED]
            break;

        case 'D':
        case 'd':
            if(state == 'l') CLR_BIT(PORTD, pin);      // [CHANGED]
            else             SET_BIT(PORTD, pin);      // [CHANGED]
            break;
    }
}

unsigned char DIO_ReadPin(unsigned char port, unsigned char pin)
{
    switch(port)
    {
        case 'B':
        case 'b':
            return READ_BIT(PINB, pin);                // [CHANGED]

        case 'C':
        case 'c':
            return READ_BIT(PINC, pin);                // [CHANGED]

        case 'D':
        case 'd':
            return READ_BIT(PIND, pin);                // [CHANGED]
    }
    return 0;
}
