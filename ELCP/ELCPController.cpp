#include "ELCPController.hpp"

#define RightJoyXValue channels[0]
#define RightJoyYValue channels[1]
#define LeftJoyYValue channels[2]
#define LeftJoyXValue channels[3]
#define SAValue channels[4]
#define SBValue channels[5]
#define SCValue channels[6]
#define SDValue channels[7]

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
    return SAValue < 1000 ? LEVER_UP : LEVER_DOWN;
}

ELCPController::LeverStatus ELCPController::getSB()
{
    return SBValue < 1000 ? LEVER_UP : SBValue < 1500 ? LEVER_MID
                                                      : LEVER_DOWN;
}

ELCPController::LeverStatus ELCPController::getSC()
{
    return SCValue < 1000 ? LEVER_UP : SCValue < 1500 ? LEVER_MID
                                                      : LEVER_DOWN;
}

ELCPController::LeverStatus ELCPController::getSD()
{
    return SDValue < 1000 ? LEVER_UP : LEVER_DOWN;
}

XYTheta ELCPController::getXYTheta()
{
    return (XYTheta){.x = (float)RightJoyXValue - 1024, .y = (float)RightJoyYValue, .theta = (float)LeftJoyXValue};
}

uint16_t ELCPController::getChannel(int channel)
{
    return channels[channel];
}