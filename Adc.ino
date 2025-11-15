#if !defined(__AVR_ATmega328P__)
#include <avr/iom328p.h>
#endif
#include <avr/io.h>
#include "Adc.h"
#include "BitMath.h"                        // [CHANGED]

void Adc_Init(void)
{
    // ADMUX = (1<<REFS0);  // AVcc ref
    ADMUX = 0x00;                                  // [CHANGED]
    SET_BIT(ADMUX, REFS0);                         // [CHANGED]

    // ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
    ADCSRA = 0x00;                                  // [CHANGED]
    SET_BIT(ADCSRA, ADEN);                          // [CHANGED]
    SET_BIT(ADCSRA, ADPS2);                         // [CHANGED]
    SET_BIT(ADCSRA, ADPS1);                         // [CHANGED]
    SET_BIT(ADCSRA, ADPS0);                         // [CHANGED]
}

unsigned short Adc_ReadChannel(unsigned char ch)
{
    ch &= 0b00000111;
    // ADMUX = (ADMUX & 0xF8) | ch;
    WRITE_MASK(ADMUX, 0x07, ch);                    // [CHANGED]

    // ADCSRA |= (1<<ADSC);
    SET_BIT(ADCSRA, ADSC);                          // [CHANGED]

    // while(ADCSRA & (1<<ADSC));
    while (READ_BIT(ADCSRA, ADSC)) { }              // [CHANGED]

    return ADC;
}
