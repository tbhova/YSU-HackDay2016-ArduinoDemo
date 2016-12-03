#include <Arduino.h>
#include "mk20dx128.h"
#include "core_pins.h"

#include "pins.h"
#include "motors.h"

Motors motors;

int readIRSensor() {
    return analogRead(IR_Sensor);
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(Left_Motor_Forward, OUTPUT);
    pinMode(Left_Motor_Reverse, OUTPUT);
    pinMode(Right_Motor_Forward, OUTPUT);
    pinMode(Right_Motor_Reverse, OUTPUT);
    pinMode(Right_Motor_Speed, OUTPUT);
    pinMode(Left_Motor_Speed, OUTPUT);
    pinMode(IR_Sensor, INPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);

    Serial.begin(9600);
    delay(6000);
}

void loop() {
    digitalWriteFast(LED2, LOW);
    digitalWriteFast(LED1, HIGH);
    motors.driveForward();

    const int wallDistance = 500;
//    Serial.print((int)readIRSensor() > wallDistance);
//    Serial.print(" ");
//    Serial.println(readIRSensor());
    if ((int)readIRSensor() > wallDistance) {
//        Serial.println(readIRSensor());
        motors.turn();
        delay(3000);
        digitalWriteFast(LED1, LOW);
        digitalWriteFast(LED2, HIGH);
    }

}
