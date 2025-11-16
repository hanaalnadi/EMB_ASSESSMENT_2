#include <avr/io.h>
#include "Dio.h"
#include "BitMath.h"                        

void DIO_SetPinDirection(unsigned char port, unsigned char pin, unsigned char direction)
{
    switch(port)
    {
        case 'B':
        case 'b':
            if(direction == 'i') CLR_BIT(DDRB, pin);  /* Set pin as input  */
            else                 SET_BIT(DDRB, pin);  /* Set pin as output */
            break;

        case 'C':
        case 'c':
            if(direction == 'i') CLR_BIT(DDRC, pin);  /* Set pin as input  */
            else                 SET_BIT(DDRC, pin);  /* Set pin as output */
            break;

        case 'D':
        case 'd':
            if(direction == 'i') CLR_BIT(DDRD, pin);  /* Set pin as input  */
            else                 SET_BIT(DDRD, pin);  /* Set pin as output */
            break;
    }
}

void DIO_SetPinState(unsigned char port, unsigned char pin, unsigned char state)
{
    switch(port)
    {
        case 'B':
        case 'b':
            if(state == 'l') CLR_BIT(PORTB, pin);  /* Drive pin LOW  */
            else             SET_BIT(PORTB, pin);  /* Drive pin HIGH */
            break;

        case 'C':
        case 'c':
            if(state == 'l') CLR_BIT(PORTC, pin);  /* Drive pin LOW  */
            else             SET_BIT(PORTC, pin);  /* Drive pin HIGH */
            break;

        case 'D':
        case 'd':
            if(state == 'l') CLR_BIT(PORTD, pin);  /* Drive pin LOW  */
            else             SET_BIT(PORTD, pin);  /* Drive pin HIGH */
            break;
    }
}

unsigned char DIO_ReadPin(unsigned char port, unsigned char pin)
{
    switch(port)
    {
        case 'B':
        case 'b':
            return READ_BIT(PINB, pin);  /* Read pin value  */

        case 'C':
        case 'c':
            return READ_BIT(PINC, pin);  /* Read pin value  */

        case 'D':
        case 'd':
            return READ_BIT(PIND, pin);  /* Read pin value  */
    }
    return 0;
}
