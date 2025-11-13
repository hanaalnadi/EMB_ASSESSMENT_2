#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "Lcd.h"
#include "Adc.h"
#include "Dio.h"
#include "Keypad.h"

#define MAX_LIMIT 1023
#define MIN_LIMIT 0

unsigned short LL = 200;
unsigned short LH = 900;
unsigned short LDR_Value;

unsigned char editMode = 0;   // 0=normal, 1=edit LL, 2=edit LH
unsigned char modeTimer = 0;

int main(void)
{
    LCD_Init();
    Adc_Init();
    DIO_SetPinDirection('D', 2, 'o'); // PD2 as output (buzzer)

    LCD_Clear();
    LCD_String_xy(0,0,"LDR MONITOR READY");
    _delay_ms(1000);
    LCD_Clear();

    while(1)
    {
    }
}
