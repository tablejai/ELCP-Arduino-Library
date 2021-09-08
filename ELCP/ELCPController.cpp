#include "ELCPController.hpp"

#define RightJoyXValue channels[0]
#define RightJoyYValue channels[1]
#define LeftJoyYValue channels[2]
#define LeftJoyXValue channels[3]
#define SAValue channels
#define SBValue channels
#define SCValue channels
#define SDValue channels

void ELCPController::begin() { SBUS::begin(); }

bool ELCPController::read()
{
    return SBUS::read(&channels[0], &failSafe, &lostFrame);
}

void ELCPController::debug() {}

uint16_t ELCPController::getRightJoyX()
{
    return RightJoyXValue;
}

uint16_t ELCPController::getRightJoyY()
{
    return RightJoyYValue;
}

uint16_t ELCPController::getLeftJoyX()
{
    return LeftJoyXValue;
}

uint16_t ELCPController::getLeftJoyY()
{
    return LeftJoyYValue;
}

ELCPController::LeverStatus ELCPController::getSA()
{
    return SAValue == 1024 ? LEVER_UP : LEVER_DOWN;
}

ELCPController::LeverStatus ELCPController::getSB()
{
    return SBValue == 1024 ? LEVER_UP : SBValue == 1024 ? LEVER_MID
                                                        : LEVER_DOWN;
}

ELCPController::LeverStatus ELCPController::getSC()
{
    return SCValue == 1024 ? LEVER_UP : SCValue == 1024 ? LEVER_MID
                                                        : LEVER_DOWN;
}

ELCPController::LeverStatus ELCPController::getSD()
{
    return SDValue == 1024 ? LEVER_UP : LEVER_DOWN;
}

XYTheta ELCPController::getXYTheta()
{
    return (XYTheta){.x = RightJoyXValue, .y = RightJoyYValue, .theta = LeftJoyXValue};
}