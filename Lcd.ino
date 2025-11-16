#include <avr/io.h>
#include <util/delay.h>
#include "Lcd.h"
#include "BitMath.h"               
#if !defined(__AVR_ATmega328P__)
#include <avr/iom328p.h>
#endif

#define LCD_Dir DDRD
#define LCD_Port PORTD
#define RS_EN_Dir DDRB
#define RS_EN_Port PORTB
#define RS PB0
#define EN PB1

void LCD_Command(unsigned char cmnd)
{
    /* Send upper nibble to LCD */
    WRITE_MASK(LCD_Port, 0xF0, (cmnd & 0xF0));

    /* RS = 0 (command mode) */
    CLR_BIT(RS_EN_Port, RS);
    /* EN = 1 pulse */
    SET_BIT(RS_EN_Port, EN);
    _delay_us(1);
    /* EN = 0 */
    CLR_BIT(RS_EN_Port, EN);
    _delay_us(200);

    /* Send lower nibble to LCD */
    WRITE_MASK(LCD_Port, 0xF0, (cmnd << 4));

    /* EN = 1 pulse */
    SET_BIT(RS_EN_Port, EN);
    _delay_us(1);
    /* EN = 0 */
    CLR_BIT(RS_EN_Port, EN);
    _delay_ms(2);
}

void LCD_Char(unsigned char data)
{
    /* Send upper nibble (data mode) */
    WRITE_MASK(LCD_Port, 0xF0, (data & 0xF0));

    /* RS = 1 (data mode) */
    SET_BIT(RS_EN_Port, RS);
    /* EN = 1 pulse */
    SET_BIT(RS_EN_Port, EN);
    _delay_us(1);
    /* EN = 0 */
    CLR_BIT(RS_EN_Port, EN);
    _delay_us(200);

    /* Send lower nibble */
    WRITE_MASK(LCD_Port, 0xF0, (data << 4));

    /* EN = 1 pulse */
    SET_BIT(RS_EN_Port, EN);
    _delay_us(1);
    /* EN = 0 */
    CLR_BIT(RS_EN_Port, EN);
    _delay_ms(2);
}

void LCD_Init(void)
{
    LCD_Dir = 0xFF;                           /* LCD pins as output */
    SET_MASK(RS_EN_Dir, (1<<EN) | (1<<RS));  /* RS and EN as output */

    _delay_ms(20);
    LCD_Command(0x02);                       /* 4-bit mode */
    LCD_Command(0x28);                       /* 2 lines, 5x7 font */
    LCD_Command(0x0C);                       /* Display ON */
    LCD_Command(0x06);                       /* Auto-increment */
    LCD_Command(0x01);                       /* Clear display */
    _delay_ms(2);
}

void LCD_String(char *str)
{
    int i;
    for(i = 0; str[i] != 0; i++)
    {
        LCD_Char(str[i]);  /* Send each character */
    }
}

void LCD_String_xy(char row, char pos, char *str)
{
    if (row == 0 && pos < 16) LCD_Command((pos & 0x0F) | 0x80);      /* First row position */
    else if (row == 1 && pos < 16) LCD_Command((pos & 0x0F) | 0xC0); /* Second row position */

    LCD_String(str);  /* Print string */
}

void LCD_Clear(void)
{
    LCD_Command(0x01);  /* Clear display */
    _delay_ms(2);
    LCD_Command(0x80);  /* Return home */
}
