#pragma once
#include "ELCPPort.hpp"

typedef enum
{
    MOTOR_FORWARD,
    MOTOR_BACKWARD,
} ELCPMotorDir;

class ELCPMotor : public ELCPPort
{
public:
    void move(ELCPMotorDir direction, int speed);
    ELCPMotor(int port) : ELCPPort{port} {}

protected:
    void init() override;
};