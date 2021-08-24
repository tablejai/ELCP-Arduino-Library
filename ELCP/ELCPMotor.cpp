#include "ELCPMotor.hpp"

void ELCPMotor::move(ELCPMotorDir direction, int speed)
{
    if (direction == MOTOR_FORWARD)
    {
        analogWrite(_portgpio, 0);
    }
    else
    {
        analogWrite(_portgpio, 255);
    }
    if (speed >= 0 && speed <= 255)
    {
        analogWrite(_portpwm, speed);
    }
}

void ELCPMotor::init()
{
    pinMode(_portgpio, OUTPUT);
    pinMode(_portpwm, OUTPUT);
    pinMode(_portadc, INPUT);
}