#include "main.h"
#include "globals.hpp"
#include "grabber-functions.hpp"

pros::Motor grabber_motor(GRABBER_MOTOR_ID);

bool grabber_active = false;
uint32_t grabber_finish_time = 0;

void grabber_periodic() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
        grabber_active = true;
        grabber_finish_time = pros::millis() + GRABBER_DURATION;
    } else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
        grabber_active = false;
        grabber_finish_time = pros::millis() + GRABBER_DURATION;
    }

    if (pros::millis() <= grabber_finish_time) {
        grabber_motor.move(grabber_active ? GRABBER_SPEED : -GRABBER_SPEED);
    } else {
        grabber_motor.move(0);
        grabber_motor.brake();
    }
}