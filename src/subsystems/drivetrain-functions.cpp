#include "main.h"
#include "drivetrain-functions.hpp"
#include "globals.hpp"


pros::MotorGroup left_motors({LEFT_FRONT_MOTOR_ID, LEFT_BACK_MOTOR_ID});
pros::MotorGroup right_motors({RIGHT_FRONT_MOTOR_ID, RIGHT_BACK_MOTOR_ID});

bool arcade_drive = true;
double drive_multiplier = 1;
bool precision_drive = false;
bool turbo_drive = false;

// Tank drive
int analogRightY = 0;

// Arcade drive
int analogLeftY = 0;
int analogRightX = 0;

void move(int left_speed, int right_speed) {
	// WARNING: DON'T CHANGE SIGNS BECAUSE THE MOTORS ARE INVERTED!
    right_motors.move(-right_speed); // Inverted due to motor orientation (DO NOT CHANGE!)
    left_motors.move(left_speed);
}

void handle_input() {
    analogRightY = controller.get_analog(ANALOG_RIGHT_Y);
    analogLeftY = controller.get_analog(ANALOG_LEFT_Y);  // Forward/backward
    analogRightX = controller.get_analog(ANALOG_RIGHT_X); // Turning

    precision_drive = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    turbo_drive = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    bool pressed = controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A);

    if(pressed){
        if(arcade_drive){
            arcade_drive = false;
        } else {
            arcade_drive = true;
        }
    }

    if (precision_drive) {
            drive_multiplier = PRECISION_MULTIPLIER;
    } else if (turbo_drive) {
            drive_multiplier = TURBO_MULTIPLIER;
    } else {
        drive_multiplier = NORMAL_MULTIPLIER;
    }
}

void drivetrain_periodic() {
	handle_input();

        if(arcade_drive){
            // Arcade drive
            int left_speed = static_cast<int>((analogLeftY + analogRightX) * drive_multiplier);
            int right_speed = static_cast<int>((analogLeftY - analogRightX) * drive_multiplier);

            move(left_speed, right_speed);

        } else {
            // Tank drive
            int left_speed = static_cast<int>(analogLeftY * drive_multiplier);
            int right_speed = static_cast<int>(analogRightY * drive_multiplier);

            move(left_speed, right_speed);
        }
}