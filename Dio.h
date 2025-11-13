#ifndef __DIO__
#define __DIO__

void DIO_SetPinDirection(unsigned char port, unsigned char pin, unsigned char direction);
void DIO_SetPinState(unsigned char port, unsigned char pin, unsigned char state);
unsigned char DIO_ReadPin(unsigned char port, unsigned char pin);

#endif
