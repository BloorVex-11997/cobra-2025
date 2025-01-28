#pragma once
#include "grabber-functions.hpp"

pros::Motor grabber_motor(GRABBER_MOTOR_ID);

void turn_motor() {
    grabber_motor.move(GRABBER_SPEED);
}

void retract_motor() {
    grabber_motor.move(-GRABBER_SPEED);
}

void grabber_periodic() {

}