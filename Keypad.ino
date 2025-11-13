#include <avr/io.h>
#include "Adc.h"
#include "Keypad.h"

// Read keypad connected to ADC0 (PC0)
// Returns: UP_KEY, DOWN_KEY, SELECT_KEY, or NO_KEY
// In LCD shield buttons are connected in paralle and each button is connected in series with a resistor 
// When no button is pressed, ADC0 sees full voltage (VCC 5 V)
// When a button is pressed, it changes the voltage at the ADC pin based on the resistor network
// This happens because V_ADC = VCC × (R_bottom / (R_top + R_bottom))
// This is the voltage divider formula
unsigned char Read_Keypad(void)
{
    unsigned short keyValue = Adc_ReadChannel(0);  // Read ADC value from PC0

    if (keyValue < 300) return UP_KEY;             // UP button pressed (return 1)
    else if (keyValue < 600) return DOWN_KEY;      // DOWN button pressed (return 2)
    else if (keyValue < 900) return SELECT_KEY;    // SELECT button pressed (return 3)
    else return NO_KEY;                            // No button pressed (return 0)
}
