#include "main.h"
#include "drivetrain-functions.hpp"
#include "globals.hpp"

pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::MotorGroup left_motors({LEFT_FRONT_MOTOR_ID, LEFT_BACK_MOTOR_ID});
pros::MotorGroup right_motors({RIGHT_FRONT_MOTOR_ID, RIGHT_BACK_MOTOR_ID});

double drive_multiplier = 1;
bool precision_drive = false;
bool turbo_drive = false;

int analogY = 0;
int analogX = 0;

void move(int speed) {
	// WARNING: DON'T CHANGE SIGNS BECAUSE THE MOTORS ARE INVERTED!
    right_motors.move(-speed);
    left_motors.move(speed);
}

void turn(int speed) {
    right_motors.move(speed);
    left_motors.move(speed);
    
}

void handle_input() {
    analogY = controller.get_analog(ANALOG_LEFT_Y);  // Forward/backward
    analogX = controller.get_analog(ANALOG_RIGHT_X); // Turning

    precision_drive = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    turbo_drive = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);

    if (precision_drive) {
            drive_multiplier = PRECISION_MULTIPLIER;
    } else if (turbo_drive) {
            drive_multiplier = TURBO_MULTIPLIER;
    } else {
        drive_multiplier = NORMAL_MULTIPLIER;
    }
}

void drivetrain_periodic() {
    
	while(true){
		handle_input();

        // Allow moving and turning simultaneously
        int left_speed = static_cast<int>((analogY + analogX) * drive_multiplier);
        int right_speed = static_cast<int>((analogY - analogX) * drive_multiplier);

        left_motors.move(left_speed);
        right_motors.move(-right_speed); // Inverted due to motor orientation (DO NOT CHANGE!)
	}
}