#include <drivetrain-functions.h>
#include <globals.h>
#include <main.h>

pros::Motor right_motor_one(RIGHT_MOTOR_ONE_ID);
pros::Motor right_motor_two(RIGHT_MOTOR_TWO_ID);

pros::Motor left_motor_one(LEFT_MOTOR_ONE_ID);
pros::Motor left_motor_two(LEFT_MOTOR_TWO_ID);

pros::MotorGroup right_motors({&right_motor_one, &right_motor_two});
pros::MotorGroup left_motors({&left_motor_one, &left_motor_two});
pros::MotorGroup all_motors({&right_motors, &left_motors});

void stop_drivetrain()
{
    all_motors.move(0);
}

void move_forward(double speed, double time) {
    all_motors.move(speed);
    pros::delay(time);
}

void move_backward(double speed, double time) {
    all_motors.move(-speed);
    pros::delay(time);
}

void rotation_cw(double speed, double time) {
    right_motors.move(-speed);
    left_motors.move(speed);
    pros::delay(time);
}

void rotation_ccw(double speed, double time) {
    right_motors.move(speed);
    left_motors.move(-speed);
    pros::delay(time);
}
