#include "ELCPController.hpp"

#define RightJoyXValue channels[0]
#define RightJoyYValue channels[1]
#define LeftJoyYValue channels[2]
#define LeftJoyXValue channels[3]
#define SAValue channels[4]
#define SBValue channels[5]
#define SCValue channels[6]
#define SDValue channels[7]
#define JOYDENOM 820.0f
#define JOYTHRESHOLD 0.05f

void ELCPController::begin() { SBUS::begin(); }

bool ELCPController::read()
{
    return SBUS::read(&channels[0], &failSafe, &lostFrame);
}

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

LeverStatus ELCPController::getSA()
{
    return SAValue < 1000 ? LEVER_UP : LEVER_DOWN;
}

LeverStatus ELCPController::getSB()
{
    return SBValue < 1000 ? LEVER_UP : SBValue < 1500 ? LEVER_MID
                                                      : LEVER_DOWN;
}

LeverStatus ELCPController::getSC()
{
    return SCValue < 1000 ? LEVER_UP : SCValue < 1500 ? LEVER_MID
                                                      : LEVER_DOWN;
}

LeverStatus ELCPController::getSD()
{
    return SDValue < 1000 ? LEVER_UP : LEVER_DOWN;
}

XYTheta ELCPController::getXYTheta()
{
    XYTheta joy_output = (XYTheta){.x = ((float)RightJoyXValue - 1024) / JOYDENOM, .y = ((float)RightJoyYValue - 1024) / JOYDENOM, .theta = ((float)LeftJoyXValue - 1000) / JOYDENOM};
    joy_output.x = fabs(joy_output.x) < JOYTHRESHOLD? 0 : joy_output.x;
    joy_output.y = fabs(joy_output.y) < JOYTHRESHOLD? 0 : joy_output.y;
    joy_output.theta = fabs(joy_output.theta) < JOYTHRESHOLD? 0 : joy_output.theta;
    return joy_output;
}

uint16_t ELCPController::getChannel(int channel)
{
    return channels[channel];
}

void ELCPController::debug()
{
    Serial.print("X: ");
    Serial.println(getXYTheta().x);
    Serial.print("Y: ");
    Serial.println(getXYTheta().y);
    Serial.print("Theta: ");
    Serial.println(getXYTheta().theta);
}