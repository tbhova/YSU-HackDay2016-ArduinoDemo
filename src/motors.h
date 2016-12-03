#ifndef MOTORS_H
#define MOTORS_H

#include "pins.h"

class Motors
{
public:
    Motors();
    void stop();
    void driveForward();
    void do180();


private:
    void rightForward();
    void rightStop();
    void rightReverse();
    void leftForward();
    void leftStop();
    void leftReverse();
    const int power = 127, off = 0;

};

#endif // MOTORS_H
