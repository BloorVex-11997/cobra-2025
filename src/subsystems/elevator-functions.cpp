#pragma once
#include "main.h"
#include "globals.hpp"
#include "subsystems/elevator-functions.hpp"

pros::Motor elevator_motor_one(ELEVATOR_MOTOR_ONE_ID);
pros::Motor elevator_motor_two(ELEVATOR_MOTOR_TWO_ID);

void extend_elevator() {
    elevator_motor_one.move(ELEVATOR_SPEED);
}

void retract_elevator() {
    elevator_motor_one.move(-ELEVATOR_SPEED);
}

void elevator_periodic() {
    
}