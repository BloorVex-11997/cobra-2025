#include "drivetrain-functions.h"
#include "globals.h"
#include "main.h"

pros::MotorGroup left_motors({LEFT_MOTOR_ONE_ID, LEFT_MOTOR_TWO_ID});
pros::MotorGroup right_motors({RIGHT_MOTOR_ONE_ID, RIGHT_MOTOR_TWO_ID});

void move(int speed) {
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
		if(analogY != 0){
			move(analogY);
		}
		else{
			turn(analogX);
		}
	}
}