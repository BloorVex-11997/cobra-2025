#include "main.h"
#include "drivetrain-functions.hpp"
#include "globals.hpp"


double drive_multiplier = 1;
bool precision_drive = false;
bool turbo_drive = false;


pros::MotorGroup left_motors({LEFT_FRONT_MOTOR_ID, LEFT_BACK_MOTOR_ID});
pros::MotorGroup right_motors({RIGHT_FRONT_MOTOR_ID, RIGHT_BACK_MOTOR_ID});

void move(int speed) {
	// WARNING: DON'T CHANGE SIGNS BECAUSE THE MOTORS ARE INVERTED!
    right_motors.move(-speed);
    left_motors.move(speed);
}

void turn(int speed) {
    right_motors.move(speed);
    left_motors.move(speed);
    
}

void drivetrain_periodic() {
    pros::Controller controller(pros::E_CONTROLLER_MASTER);
    
	while(true){
		int analogY = controller.get_analog(ANALOG_LEFT_Y);
		int analogX = controller.get_analog(ANALOG_RIGHT_X);

		precision_drive = static_cast<bool>(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
		turbo_drive = static_cast<bool>(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1));


		if(precision_drive) {
			drive_multiplier = PRECISION_MULTIPLIER;
		} else if(turbo_drive) {
			drive_multiplier = TURBO_MULTIPLIER;
		} else {
			drive_multiplier = NORMAL_MULTIPLIER;
		}

		if(analogY != 0){
			move(static_cast<int>(analogY * drive_multiplier));
		} else {
			turn(static_cast<int>(analogX * drive_multiplier));
		}
	}
}