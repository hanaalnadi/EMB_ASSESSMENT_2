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
unsigned char editMode = 0;   
unsigned char modeTimer = 0;  

int main(void)
{
    LCD_Init();                        
    Adc_Init();                        
    DIO_SetPinDirection('D', 2, 'o');  

    LCD_Clear();
    LCD_String_xy(0,0,"LDR MONITOR READY");
    _delay_ms(1000);
    LCD_Clear();

    while(1)
    {
        LDR_Value = Adc_ReadChannel(1);
        unsigned char KeyPressed = Read_Keypad();

        if (KeyPressed == SELECT_KEY)
        {
            editMode++;
            if (editMode > 2) editMode = 0;  
            modeTimer = 0;                    
            _delay_ms(300);                   
        }

        // LL
        if (editMode == 1)
        {
            if (KeyPressed == UP_KEY && LL < MAX_LIMIT - 10) { LL += 10; modeTimer = 0; }    
            if (KeyPressed == DOWN_KEY && LL > MIN_LIMIT + 10) { LL -= 10; modeTimer = 0; }  
        }
        // LH 
        else if (editMode == 2)
        {
            if (KeyPressed == UP_KEY && LH < MAX_LIMIT - 10) { LH += 10; modeTimer = 0; }    
            if (KeyPressed == DOWN_KEY && LH > MIN_LIMIT + 10) { LH -= 10; modeTimer = 0; }  
        }

        // exit after ~3 seconds (15×200ms) 

        if (editMode != 0)       
        {
            modeTimer++;
            if (modeTimer > 15)  
            {
                editMode = 0;    
                modeTimer = 0;   
            }
        }

        // If outside range, buzzer ON; otherwise OFF
        unsigned char buzState = 0;
        if (LDR_Value < LL || LDR_Value > LH)
        {
            DIO_SetPinState('D', 2, 'h');  
            buzState = 1;
        }
        else
        {
            DIO_SetPinState('D', 2, 'l');  
            buzState = 0;
        }

        // ===== LCD update =====
        LCD_Clear();

        char buffer[16];
        sprintf(buffer, "LDR:%4d BUZ:%s", LDR_Value, buzState ? "ON " : "OFF");
        LCD_String_xy(0,0,buffer);

        sprintf(buffer, "LL:%4d LH:%4d", LL, LH);
        LCD_String_xy(1,0,buffer);

        if (editMode == 1) LCD_String_xy(1,0,">");
        else if (editMode == 2) LCD_String_xy(1,8,">");

        _delay_ms(200);
    }
}
