#pragma once
#include "main.h"
#include "globals.hpp"
#include "subsystems/elevator-functions.hpp"

pros::Motor elevator_motor(ELEVATOR_MOTOR_ID);

bool active = false;

void run_elevator(int speed) {
    elevator_motor.move(speed);
}

void elevator_periodic() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
        active = !active;
        run_elevator(active ? ELEVATOR_SPEED : 0);
    }
}