#pragma once
#include "ELCPPort.hpp"
#include "Servo.h"
class ELCPServo : public ELCPPort
{
public:
    ELCPServo(int port) : ELCPPort(port) {}
    void init() override;
    void move(int position);

private:
    Servo _servo;
    bool inited = 0;
};