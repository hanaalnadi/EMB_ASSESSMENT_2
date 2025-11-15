#include <avr/io.h>
#include <util/delay.h>
#include "Lcd.h"
#include "BitMath.h"               // [CHANGED]
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
    // Upper nibble
    // LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);
    WRITE_MASK(LCD_Port, 0xF0, (cmnd & 0xF0));   // [CHANGED]

    // RS_EN_Port &= ~(1<<RS);
    CLR_BIT(RS_EN_Port, RS);                     // [CHANGED]
    // RS_EN_Port |= (1<<EN);
    SET_BIT(RS_EN_Port, EN);                     // [CHANGED]
    _delay_us(1);
    // RS_EN_Port &= ~(1<<EN);
    CLR_BIT(RS_EN_Port, EN);                     // [CHANGED]
    _delay_us(200);

    // Lower nibble
    // LCD_Port = (LCD_Port & 0x0F) | (cmnd<<4);
    WRITE_MASK(LCD_Port, 0xF0, (cmnd << 4));     // [CHANGED]

    // RS_EN_Port |= (1<<EN);
    SET_BIT(RS_EN_Port, EN);                     // [CHANGED]
    _delay_us(1);
    // RS_EN_Port &= ~(1<<EN);
    CLR_BIT(RS_EN_Port, EN);                     // [CHANGED]
    _delay_ms(2);
}

void LCD_Char(unsigned char data)
{
    // Upper nibble
    // LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);
    WRITE_MASK(LCD_Port, 0xF0, (data & 0xF0));   // [CHANGED]

    // RS_EN_Port |= (1<<RS);
    SET_BIT(RS_EN_Port, RS);                     // [CHANGED]
    // RS_EN_Port |= (1<<EN);
    SET_BIT(RS_EN_Port, EN);                     // [CHANGED]
    _delay_us(1);
    // RS_EN_Port &= ~(1<<EN);
    CLR_BIT(RS_EN_Port, EN);                     // [CHANGED]
    _delay_us(200);

    // Lower nibble
    // LCD_Port = (LCD_Port & 0x0F) | (data<<4);
    WRITE_MASK(LCD_Port, 0xF0, (data << 4));     // [CHANGED]

    // RS_EN_Port |= (1<<EN);
    SET_BIT(RS_EN_Port, EN);                     // [CHANGED]
    _delay_us(1);
    // RS_EN_Port &= ~(1<<EN);
    CLR_BIT(RS_EN_Port, EN);                     // [CHANGED]
    _delay_ms(2);
}

void LCD_Init(void)
{
    LCD_Dir = 0xFF;
    // RS_EN_Dir |= (1<<EN)|(1<<RS);
    SET_MASK(RS_EN_Dir, (1<<EN) | (1<<RS));      // [CHANGED]

    _delay_ms(20);
    LCD_Command(0x02);
    LCD_Command(0x28);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    LCD_Command(0x01);
    _delay_ms(2);
}

void LCD_String(char *str)
{
    int i;
    for(i=0; str[i]!=0; i++)
    {
        LCD_Char(str[i]);
    }
}

void LCD_String_xy(char row, char pos, char *str)
{
    if (row==0 && pos<16) LCD_Command((pos & 0x0F) | 0x80);
    else if (row==1 && pos<16) LCD_Command((pos & 0x0F) | 0xC0);
    LCD_String(str);
}

void LCD_Clear(void)
{
    LCD_Command(0x01);
    _delay_ms(2);
    LCD_Command(0x80);
}
