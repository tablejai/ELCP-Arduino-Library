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
    ELCPMotor(int port) : ELCPPort{port} {}
    void move(ELCPMotorDir direction, int speed);

protected:
    void init() override;
};