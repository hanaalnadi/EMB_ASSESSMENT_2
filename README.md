## Embedded Systems Project Report:

## 1. Introduction
This project reads an analog sensor value (LDR) and compares it with two user-defined limits: LL (Low Limit) and LH (High Limit). These values, along with the live sensor reading, are shown on a 16x2 LCD. The user can change LL and LH through the keypad: pressing SELECT enters edit mode, where the UP and DOWN buttons adjust the selected limit. If no button is pressed for a few seconds, the system automatically returns to the main screen. The sensor value is read continuously in a loop, and the system checks whether it falls between LL and LH. If it does, the Buzzer turns on; otherwise, it turns off. This allows the user to control both limits directly from the hardware buttons without needing to edit the code.

## 2. Project Code

**GitHub Repository:**  
[submission_repo](https://github.com/hanaalnadi/EMB_ASSESSMENT_2)

**Local Root Directory**  
[link_to_local_root_directory](https://github.com/hanaalnadi/EMB_ASSESSMENT_2/tree/main)

## 3. Test Cases

Test Cases are developed in **[Robot Framework](https://robotframework.org/)**  
Test steps:  
[robot_tests](https://github.com/hanaalnadi/EMB_ASSESSMENT_2/blob/main/Test/Test_Cases.robot)

## 4. Bill of Materials (BOM)

**BOM**  
[bom_file](https://github.com/hanaalnadi/EMB_ASSESSMENT_2/blob/main/Bom/Bom.csv)

**Optimized BOM**  
[optimized_bom_file](https://github.com/hanaalnadi/EMB_ASSESSMENT_2/blob/main/Bom/Optimized_Bom.csv)

## 5. Video Demonstration

[recorded_video](https://github.com/hanaalnadi/EMB_ASSESSMENT_2/blob/main/Video/d5fd4ca6-5986-4211-84c2-4b2840be2519%20(1).mp4)

## 6. Design

[design_document](https://github.com/hanaalnadi/EMB_ASSESSMENT_2/blob/main/Design/project_design_tpl.md)