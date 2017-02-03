#include <Arduino.h>
#include "mk20dx128.h"
#include "core_pins.h"

#include "pins.h"
#include "motors.h"

Motors motors;

int readIRSensor() {
    return analogRead(IR_SENSOR_CENTER);
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
    pinMode(LEFT_MOTOR_REVERSE, OUTPUT);
    pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
    pinMode(RIGHT_MOTOR_REVERSE, OUTPUT);
    pinMode(RIGHT_MOTOR_SPEED, OUTPUT);
    pinMode(LEFT_MOTOR_SPEED, OUTPUT);
    pinMode(MOTOR_STANDBY, OUTPUT);
    pinMode(IR_SENSOR_CENTER, INPUT);

    Serial.begin(9600);
    delay(6000);

    digitalWriteFast(MOTOR_STANDBY, HIGH);
}

void loop() {

    const int wallDistance = 500;
    if ((int)readIRSensor() > wallDistance) {
        motors.reverse();
        delay(900);
        motors.turn();
        delay(400);
    } else {
        motors.driveForward();
        delay(300);
    }

}
