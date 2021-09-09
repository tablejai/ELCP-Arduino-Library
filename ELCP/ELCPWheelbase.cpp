#include "ELCPWheelbase.hpp"
#include "ELCPMotor.hpp"
#include "math.h"

#define cos45 0.70710678118
#define sin45 0.70710678118

void ELCPWheelbase::wbToWheelVel(XYTheta vel, float mult)
{
    /**
     * 
     * Normally the forward kinematics should be something like for this kind of Mecanum wheels
     * w1 = 1/r(vx - vy - (lx + ly)(theta));
     * w2 = 1/r(vx + vy + (lx + ly)(theta));
     * w3 = 1/r(vx + vy - (lx + ly)(theta));
     * w4 = 1/r(vx - vy + (lx + ly)(theta));
     * 
     * Since there is no control on the wheels, I'll just remove all the variables of the wheelbase
     * Will modify if Eric decided to use the controlled version
     * 
     */
    wheels_vel[0] = vel.x + vel.y + vel.theta;
    wheels_vel[1] = -vel.x + vel.y - vel.theta;
    wheels_vel[2] = -vel.x + vel.y + vel.theta;
    wheels_vel[3] = vel.x + vel.y - vel.theta;

    motors[0].move(wheels_vel[0] < 0 ? !wheels_forward_dir[0] : wheels_forward_dir[0], fabs(wheels_vel[0] * mult));
    motors[1].move(wheels_vel[1] < 0 ? !wheels_forward_dir[1] : wheels_forward_dir[1], fabs(wheels_vel[1] * mult));
    motors[2].move(wheels_vel[2] < 0 ? !wheels_forward_dir[2] : wheels_forward_dir[2], fabs(wheels_vel[2] * mult));
    motors[3].move(wheels_vel[3] < 0 ? !wheels_forward_dir[3] : wheels_forward_dir[3], fabs(wheels_vel[3] * mult));
}

void ELCPWheelbase::moveWheelOnly(uint8_t wheel, uint8_t dir, float vel)
{
    for (uint8_t i = 0; i < 4; ++i)
    {
        if (i == wheel)
            motors[i].move(dir, vel);
        else
            motors[i].move(0, 0);
    }
}