#if !defined(__AVR_ATmega328P__)
#include <avr/iom328p.h>
#endif
#include <avr/io.h>
#include "Adc.h"
#include "BitMath.h"

void Adc_Init(void)
{
    ADMUX = 0x00;                        /* Clear ADMUX */
    SET_BIT(ADMUX, REFS0);               /* Select AVcc as reference */

    ADCSRA = 0x00;                       /* Clear ADCSRA */
    SET_BIT(ADCSRA, ADEN);               /* Enable ADC */
    SET_BIT(ADCSRA, ADPS2);              /* Prescaler bit */
    SET_BIT(ADCSRA, ADPS1);              /* Prescaler bit */
    SET_BIT(ADCSRA, ADPS0);              /* Prescaler bit (128 total) */
}

unsigned short Adc_ReadChannel(unsigned char ch)
{
    ch &= 0b00000111;                    /* Mask channel number (0–7 only) */

    WRITE_MASK(ADMUX, 0x07, ch);         /* Select ADC channel */

    SET_BIT(ADCSRA, ADSC);               /* Start conversion */

    while (READ_BIT(ADCSRA, ADSC)) { }   /* Wait for conversion to finish */

    return ADC;                          /* Return ADC result */
}
