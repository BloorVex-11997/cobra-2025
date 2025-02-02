#pragma once
#include "main.h"
#include "globals.hpp"
#include "subsystems/elevator-functions.hpp"

pros::Motor elevator_motor(ELEVATOR_MOTOR_ID);
pros::Controller controller(pros::E_CONTROLLER_MASTER);

bool active = false;

void extend_elevator() {
    elevator_motor.move(ELEVATOR_SPEED);
}

void retract_elevator() {
    elevator_motor.move(-ELEVATOR_SPEED);
}

void elevator_periodic() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
        active = !active;
    }

    if(active){
        extend_elevator();
    } else {
        retract_elevator();
    }
}