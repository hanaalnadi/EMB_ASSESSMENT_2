*** Settings ***
Documentation    Embedded Systems Assessment 2 – Functional Test Cases for LDR Threshold System.
*** Test Cases ***
Test Case 1: Initialization
    [Documentation]    System boots up showing startup layout, then switches to default display showing current LDR value and LL/LH limits.
    # Arrange
    Ensure Arduino is connected and powered via USB. LCD and keypad shield should be attached properly.
    # Act
    Press RESET or power the circuit.
    # Assert
    Verify LCD shows startup message (“LDR MONITOR READ”) for a few seconds.
    Verify LCD then switches to default mode displaying live LDR value, stored LL/LH values, and Buzzer state.
    Confirm no keypad inputs are required to start.

Test Case 2: LDR value in range
    [Documentation]    When LDR reading is between LL and LH thresholds, buzzer remains OFF.
    # Arrange
    Set LL and LH thresholds appropriately using Test Cases (use Test Case 3 to 10 if needed).
    # Act
    Adjust light on sensor so the ADC value lies between LL and LH.
    # Assert
    Verify LCD shows LDR value within limits.
    Confirm buzzer is off.
    Ensure buzzer state on LCD is off.

Test Case 3: LDR value out of range
    [Documentation]    When LDR reading falls outside LL or LH, buzzer activates.
    # Arrange
    Maintain same thresholds from previous test.
    # Act
    Cover or shine strong light on LDR to push ADC reading below LL or above LH.
    # Assert
    Verify LCD displays updated LDR value outside limits.
    Confirm buzzer is on.
    Ensure buzzer state on LCD is on.

Test Case 4: Select LL
    [Documentation]    Pressing SELECT once enters “LL” edit mode allowing threshold adjustment for Low Limit.
    # Arrange
    Ensure device is in default mode showing live LDR and limits.
    # Act
    Press SELECT button once.
    # Assert
    Verify LCD updates the mode label to “>L”.
    Verify ADC reading continues to update in the background.

Test Case 5: Select LH
    [Documentation]    Pressing SELECT again after LL mode switches to “LH” edit mode.
    # Arrange
    Start from LL mode (use Test Case 2 if needed).
    # Act
    Press SELECT button again.
    # Assert
    Verify LCD updates the mode label to “>H”.
    Verify ADC reading continues to update in the background.

Test Case 8: Increasing LL
    [Documentation]    In LL edit mode, pressing UP key increases the low limit value by 10 and updates LCD.
    # Arrange
    Enter LL mode via SELECT (use Test Case 2 if needed).
    # Act
    Press UP key once or multiple times.
    # Assert
    Verify LL numeric value increases by 10 with each press on LCD.
    Confirm LH remains unchanged.

Test Case 6: Decreasing LL
    [Documentation]    In LL edit mode, pressing DOWN key decreases the low limit value by 10 and updates LCD.
    # Arrange
    Enter LL mode via SELECT (use Test Case 2 if needed).
    # Act
    Press DOWN key once or multiple times.
    # Assert
    Verify LL numeric value decreases by 10 with each press on LCD.
    Confirm LH remains unchanged.

Test Case 7: Increasing LH
    [Documentation]    In LH edit mode, pressing UP key increases the low limit value by 10 and updates LCD.
    # Arrange
    Enter LL mode via SELECT (use Test Case 3 if needed).
    # Act
    Press UP key once or multiple times.
    # Assert
    Verify LL numeric value increases by 10 with each press on LCD.
    Confirm LH remains unchanged.

Test Case 8: Decreasing LH
    [Documentation]    In LH edit mode, pressing DOWN key decreases the low limit value by 10 and updates LCD.
    # Arrange
    Enter LL mode via SELECT (use Test Case 3 if needed).
    # Act
    Press DOWN key once or multiple times.
    # Assert
    Verify LL numeric value decreases by 10 with each press on LCD.
    Confirm LH remains unchanged.