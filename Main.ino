#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "Lcd.h"
#include "Adc.h"
#include "Dio.h"
#include "Keypad.h"

/* Code Flow: Initialize LCD, ADC, and Buzzer → continuously read LDR value → check buttons
   → change edit modes (LL, LH, Normal) → adjust limits if in edit mode → control buzzer
   → update LCD display → repeat loop every 200 ms */

/* ----- Define constants ----- */
#define MAX_LIMIT 1023  /* 10-bit ADC → 2^10 = 1024 values (0 → 1023) */
#define MIN_LIMIT 0

/* ----- Declare variables ----- */
unsigned short LL = 200;      /* Lower light limit */
unsigned short LH = 900;      /* Higher light limit */
unsigned short LDR_Value;     /* Stores the current LDR ADC reading */

unsigned char editMode = 0;   /* 0 = normal, 1 = editing LL, 2 = editing LH */
unsigned char modeTimer = 0;  /* Tracks how long the user has been inactive while in edit mode (after pressing select) */

int main(void)
{
    /* --- Initialization section --- */
    LCD_Init();                        /* Initialize the LCD display */
    Adc_Init();                        /* Initialize ADC for reading LDR */
    DIO_SetPinDirection('D', 2, 'o');  /* Set PD2 as output (buzzer pin) */

    /* Display startup message on LCD */
    LCD_Clear();
    LCD_String_xy(0,0,"LDR MONITOR READY");
    _delay_ms(1000);
    LCD_Clear();

    /* --- Main program loop --- */
    while(1)
    {
        /* Read LDR analog value from channel 1 */
        LDR_Value = Adc_ReadChannel(1);

        /* Read any button press from LCD Keypad Shield */
        unsigned char KeyPressed = Read_Keypad();

        /* ===== SELECT button cycles between modes =====
           Each press changes between: Normal → Edit LL → Edit LH → Normal */
        if (KeyPressed == SELECT_KEY)
        {
            editMode++;
            if (editMode > 2) editMode = 0;   /* On 3rd press → return to normal mode (exit edit state) */
            modeTimer = 0;                    /* Reset inactivity timer */
            _delay_ms(300);                   /* Debounce delay */
        }

        /* ===== LL adjustment mode ===== */
        if (editMode == 1)
        {
            if (KeyPressed == UP_KEY && LL < MAX_LIMIT - 10) { LL += 10; modeTimer = 0; }    /* Increase LL by 10 only if it won't exceed the max limit */
            if (KeyPressed == DOWN_KEY && LL > MIN_LIMIT + 10) { LL -= 10; modeTimer = 0; }  /* Decrease LL by 10 only if it won't go below the min limit */
        }
        /* ===== LH adjustment mode ===== */
        else if (editMode == 2)
        {
            if (KeyPressed == UP_KEY && LH < MAX_LIMIT - 10) { LH += 10; modeTimer = 0; }    /* Increase LH by 10 only if it won't exceed the max limit */
            if (KeyPressed == DOWN_KEY && LH > MIN_LIMIT + 10) { LH -= 10; modeTimer = 0; }  /* Decrease LH by 10 only if it won't go below the min limit */
        }

        /* ===== Auto exit after ~3 seconds (15×200ms) =====  
           ModeTimer counts 200ms loops while user is inactive (no button press)
           After ~15 loops (15 × 200ms ≈ 3 sec) with no button press, editMode resets to 0
           Pressing UP, DOWN, or SELECT resets modeTimer to 0 (user active) */

        if (editMode != 0)       /* If currently in edit mode (editing LL or LH) */
        {
            modeTimer++;
            if (modeTimer > 15)  /* 15 × 200ms ≈ 3 seconds */
            {
                editMode = 0;    /* Reset editMode */
                modeTimer = 0;   /* Reset modeTimer */
            }
        }

        /* ===== Buzzer control logic =====
           If LDR is outside the range, buzzer ON; otherwise OFF */
        unsigned char buzState = 0;
        if (LDR_Value < LL || LDR_Value > LH)
        {
            DIO_SetPinState('D', 2, 'h');  /* Buzzer ON */
            buzState = 1;
        }
        else
        {
            DIO_SetPinState('D', 2, 'l');  /* Buzzer OFF */
            buzState = 0;
        }

        /* ===== Display readings and status on LCD ===== */
        LCD_Clear();

        char buffer[16];
        sprintf(buffer, "LDR:%4d BUZ:%s", LDR_Value, buzState ? "ON " : "OFF");
        LCD_String_xy(0,0,buffer);

        sprintf(buffer, "LL:%4d LH:%4d", LL, LH);
        LCD_String_xy(1,0,buffer);

        /* Show which value is currently being edited (LL or LH) with arrow (>) */
        if (editMode == 1) LCD_String_xy(1,0,">");       /* Arrow points to LL */
        else if (editMode == 2) LCD_String_xy(1,8,">");  /* Arrow points to LH */

        _delay_ms(200);  /* Refresh delay */
    }
}
