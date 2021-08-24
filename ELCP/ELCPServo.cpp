#include "ELCPServo.hpp"

void ELCPServo::init()
{
    _servo.attach(_portpwm);
}

void ELCPServo::move(int position)
{
    if (position >= 0 && position <= 180)
    {
        _servo.write(position);
    }
}