#pragma once
#include "main.h"
#include "globals.hpp"
#include "subsystems/elevator-functions.hpp"

pros::Motor elevator_motor(11);


bool active = false;

void extend_elevator() {
    elevator_motor.move(100);
}

void retract_elevator() {
    elevator_motor.move(-100);
}

void elevator_periodic() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
        active = !active;
    }

    if(active){
        extend_elevator();
    } else {
        retract_elevator();
    }
}