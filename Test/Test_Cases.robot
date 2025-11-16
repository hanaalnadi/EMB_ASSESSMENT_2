*** Settings ***
Documentation    Embedded Systems Assessment 2 – Functional Test Cases for LDR Threshold System.
Library    BuiltIn

*** Keywords ***
KW_Ensure_Arduino_Connected
    [Documentation]    Ensure Arduino is connected and powered via USB. LCD and keypad shield should be attached properly.
    No Operation

KW_Press_RESET_or_power
    [Documentation]    Press RESET or power the circuit.
    No Operation

KW_Verify_LDR_MONITOR_STARTUP
    [Documentation]    Verify LCD shows startup message (“LDR MONITOR READ”) for a few seconds.
    No Operation

KW_Verify_default_mode_display
    [Documentation]    Verify LCD then switches to default mode displaying live LDR value, stored LL/LH values, and Buzzer state.
    No Operation

KW_Confirm_no_keypad_inputs_required
    [Documentation]    Confirm no keypad inputs are required to start.
    No Operation

KW_Set_LL_LH_thresholds
    [Documentation]    Set LL and LH thresholds appropriately using Test Cases (use Test Case 3 to 10 if needed).
    No Operation

KW_Adjust_light_on_sensor
    [Documentation]    Adjust light on sensor so the ADC value lies between LL and LH.
    No Operation

KW_Verify_LDR_within_limits
    [Documentation]    Verify LCD shows LDR value within limits.
    No Operation

KW_Confirm_buzzer_off
    [Documentation]    Confirm buzzer is off.
    No Operation

KW_Ensure_buzzer_state_off_on_LCD
    [Documentation]    Ensure buzzer state on LCD is off.
    No Operation

KW_Maintain_same_thresholds
    [Documentation]    Maintain same thresholds from previous test.
    No Operation

KW_Cover_or_shine_strong_light
    [Documentation]    Cover or shine strong light on LDR to push ADC reading below LL or above LH.
    No Operation

KW_Verify_LDR_outside_limits
    [Documentation]    Verify LCD displays updated LDR value outside limits.
    No Operation

KW_Confirm_buzzer_on
    [Documentation]    Confirm buzzer is on.
    No Operation

KW_Ensure_buzzer_state_on_on_LCD
    [Documentation]    Ensure buzzer state on LCD is on.
    No Operation

KW_Ensure_device_default_mode
    [Documentation]    Ensure device is in default mode showing live LDR and limits.
    No Operation

KW_Press_SELECT_once
    [Documentation]    Press SELECT button once.
    No Operation

KW_Verify_mode_label_L
    [Documentation]    Verify LCD updates the mode label to “>L”.
    No Operation

KW_Verify_ADC_updates_background
    [Documentation]    Verify ADC reading continues to update in the background.
    No Operation

KW_Start_from_LL_mode
    [Documentation]    Start from LL mode (use Test Case 2 if needed).
    No Operation

KW_Press_SELECT_again
    [Documentation]    Press SELECT button again.
    No Operation

KW_Verify_mode_label_H
    [Documentation]    Verify LCD updates the mode label to “>H”.
    No Operation

KW_Start_from_LH_mode
    [Documentation]    Start from LH mode (use Test Case 3 if needed).
    No Operation

KW_Press_SELECT_once_more
    [Documentation]    Press SELECT once more.
    No Operation

KW_Verify_LCD_normal_screen
    [Documentation]    Verify LCD returns to normal screen.
    No Operation

KW_Ensure_buzzer_behaviour_depends_on_LDR
    [Documentation]    Ensure buzzer behaviour depends solely on LDR level again.
    No Operation

KW_Enter_LL_or_LH_mode
    [Documentation]    Enter LL or LH mode (use Test Case 2 or 3 if needed).
    No Operation

KW_Wait_3_seconds
    [Documentation]    Wait without pressing any button for 3 seconds.
    No Operation

KW_Verify_auto_exit_edit_mode
    [Documentation]    Verify LCD automatically switches back to normal display mode.
    No Operation

KW_Confirm_new_thresholds_stored
    [Documentation]    Confirm new threshold values (if changed) remain stored.
    No Operation

KW_Enter_LL_mode_via_SELECT
    [Documentation]    Enter LL mode via SELECT (use Test Case 2 if needed).
    No Operation

KW_Press_UP_key
    [Documentation]    Press UP key once or multiple times.
    No Operation

KW_Verify_LL_increases_by_10
    [Documentation]    Verify LL numeric value increases by 10 with each press on LCD.
    No Operation

KW_Confirm_LH_unchanged
    [Documentation]    Confirm LH remains unchanged.
    No Operation

KW_Press_DOWN_key
    [Documentation]    Press DOWN key once or multiple times.
    No Operation

KW_Verify_LL_decreases_by_10
    [Documentation]    Verify LL numeric value decreases by 10 with each press on LCD.
    No Operation

KW_Enter_LH_mode_via_SELECT
    [Documentation]    Enter LH mode via SELECT (use Test Case 3 if needed).
    No Operation

KW_Verify_LH_increases_by_10
    [Documentation]    Verify LH numeric value increases by 10 with each press on LCD.
    No Operation

KW_Verify_LH_decreases_by_10
    [Documentation]    Verify LH numeric value decreases by 10 with each press on LCD.
    No Operation

KW_Ensure_system_default_mode
    [Documentation]    Ensure system is in default mode (use Test Case 4 or 5 if needed).
    No Operation

KW_Press_UP_or_DOWN_buttons
    [Documentation]    Press UP or DOWN buttons.
    No Operation

KW_Verify_LCD_values_do_not_change
    [Documentation]    Verify LCD values do not change (LL and LH remain constant).
    No Operation

KW_Confirm_buzzer_display_continue
    [Documentation]    Confirm buzzer and display continue normal operation.
    No Operation


*** Test Cases ***
Test Case 1: Initialization
    KW_Ensure_Arduino_Connected
    KW_Press_RESET_or_power
    KW_Verify_LDR_MONITOR_STARTUP
    KW_Verify_default_mode_display
    KW_Confirm_no_keypad_inputs_required

Test Case 2: LDR value in range
    KW_Set_LL_LH_thresholds
    KW_Adjust_light_on_sensor
    KW_Verify_LDR_within_limits
    KW_Confirm_buzzer_off
    KW_Ensure_buzzer_state_off_on_LCD

Test Case 3: LDR value out of range
    KW_Maintain_same_thresholds
    KW_Cover_or_shine_strong_light
    KW_Verify_LDR_outside_limits
    KW_Confirm_buzzer_on
    KW_Ensure_buzzer_state_on_on_LCD

Test Case 4: Select LL
    KW_Ensure_device_default_mode
    KW_Press_SELECT_once
    KW_Verify_mode_label_L
    KW_Verify_ADC_updates_background

Test Case 5: Select LH
    KW_Start_from_LL_mode
    KW_Press_SELECT_again
    KW_Verify_mode_label_H
    KW_Verify_ADC_updates_background

Test Case 6: Removing selection by force
    KW_Start_from_LH_mode
    KW_Press_SELECT_once_more
    KW_Verify_LCD_normal_screen
    KW_Ensure_buzzer_behaviour_depends_on_LDR

Test Case 7: Removing selection by default time
    KW_Enter_LL_or_LH_mode
    KW_Wait_3_seconds
    KW_Verify_auto_exit_edit_mode
    KW_Confirm_new_thresholds_stored

Test Case 8: Increasing LL
    KW_Enter_LL_mode_via_SELECT
    KW_Press_UP_key
    KW_Verify_LL_increases_by_10
    KW_Confirm_LH_unchanged

Test Case 9: Decreasing LL
    KW_Enter_LL_mode_via_SELECT
    KW_Press_DOWN_key
    KW_Verify_LL_decreases_by_10
    KW_Confirm_LH_unchanged

Test Case 10: Increasing LH
    KW_Enter_LH_mode_via_SELECT
    KW_Press_UP_key
    KW_Verify_LH_increases_by_10
    KW_Confirm_LH_unchanged

Test Case 11: Decreasing LH
    KW_Enter_LH_mode_via_SELECT
    KW_Press_DOWN_key
    KW_Verify_LH_decreases_by_10
    KW_Confirm_LH_unchanged

Test Case 12: Using UP, DOWN buttons out of select mode
    KW_Ensure_system_default_mode
    KW_Press_UP_or_DOWN_buttons
    KW_Verify_LCD_values_do_not_change
    KW_Confirm_buzzer_display_continue
