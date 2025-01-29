#include "drivetrain-functions.h"
#include "globals.h"
#include "main.h"

int drive_multiplier = 1;
static int NORMAL_MULTIPLIER = 1.5;
static int PRECISION_MULTIPLIER = 0.33;

pros::MotorGroup left_motors({LEFT_MOTOR_ONE_ID, LEFT_MOTOR_TWO_ID});
pros::MotorGroup right_motors({RIGHT_MOTOR_ONE_ID, RIGHT_MOTOR_TWO_ID});

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
		int analogY = controller.get_analog(ANALOG_RIGHT_Y);
		int analogX = controller.get_analog(ANALOG_LEFT_X);

		bool precision_drive = static_cast<bool>(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
		
		if(precision_drive) {
			drive_multiplier = PRECISION_MULTIPLIER;
		} else {
			drive_multiplier = NORMAL_MULTIPLIER;
		}

		if(analogY != 0){
			move(analogY * drive_multiplier);
		} else {
			turn(analogX * drive_multiplier);
		}
	}
}