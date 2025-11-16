#ifndef __KEYPAD__
#define __KEYPAD__

/*To make main code more readable, define key codes instead of using numbers directly*/
#define NO_KEY     0  /*NO button pressed*/
#define UP_KEY     1  /*UP button*/
#define DOWN_KEY   2  /*DOWN button*/
#define SELECT_KEY 3  /*SELECT button*/


unsigned char Read_Keypad(void);

#endif
