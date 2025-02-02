#pragma once

const int RIGHT_FRONT_MOTOR_ID = 15;
const int LEFT_FRONT_MOTOR_ID = 16;
const int RIGHT_BACK_MOTOR_ID = 5;
const int LEFT_BACK_MOTOR_ID = 6;

const int ELEVATOR_MOTOR_ID = 11;
const int INTAKE_MOTOR_ID = = 4;
const int ELEVATOR_SPEED = -127;

const int GRABBER_MOTOR_ID = 20;
const int GRABBER_SPEED = 100;
const int GRABBER_DURATION = 1000;

const int NORMAL_MULTIPLIER= 1;
const double PRECISION_MULTIPLIER = 0.25;
const double TURBO_MULTIPLIER = 2;

inline pros::Controller controller(pros::E_CONTROLLER_MASTER);