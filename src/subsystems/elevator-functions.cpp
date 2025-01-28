#pragma once
#include "globals.h"
#include "elevator-functions.h"

pros::Motor elevator_motor(ELEVATOR_MOTOR_ID);

void extend_elevator() {
    elevator_motor.move(ELEVATOR_SPEED);
}

void retract_elevator() {
    elevator_motor.move(-ELEVATOR_SPEED);
}

void elevator_periodic() {
    
}