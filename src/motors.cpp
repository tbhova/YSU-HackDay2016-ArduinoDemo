#include "motors.h"
#include "Arduino.h"
#include "mk20dx128.h"

Motors::Motors()
{
    this->stop();
}

void Motors::driveForward() {
    leftForward();
    rightForward();
}

void Motors::turn() {
    rightForward();
    leftReverse();
}

void Motors::stop() {
    rightStop();
    leftStop();
}

void Motors::reverse() {
    leftReverse();
    rightReverse();
}

void Motors::leftForward() {
    digitalWrite(LEFT_MOTOR_REVERSE, LOW);
    digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
    analogWrite(LEFT_MOTOR_SPEED, power);
}

void Motors::leftStop() {
    digitalWrite(LEFT_MOTOR_FORWARD, LOW);
    digitalWrite(LEFT_MOTOR_REVERSE, LOW);
    analogWrite(LEFT_MOTOR_SPEED, off);
}

void Motors::leftReverse() {
    digitalWrite(LEFT_MOTOR_FORWARD, LOW);
    digitalWrite(LEFT_MOTOR_REVERSE, HIGH);
    analogWrite(LEFT_MOTOR_SPEED, power);
}

void Motors::rightForward() {
    digitalWrite(RIGHT_MOTOR_REVERSE, LOW);
    digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
    analogWrite(RIGHT_MOTOR_SPEED, power);
}

void Motors::rightReverse() {
    digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
    digitalWrite(RIGHT_MOTOR_REVERSE, HIGH);
    analogWrite(RIGHT_MOTOR_SPEED, power);
}

void Motors::rightStop() {
    digitalWrite(RIGHT_MOTOR_REVERSE, LOW);
    digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
    analogWrite(RIGHT_MOTOR_SPEED, off);
}
