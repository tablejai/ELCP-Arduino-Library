#include "ELCPWheelbase.hpp"
#include "ELCPMotor.hpp"

void ELCPWheelbase::wbToWheelVel(XYTheta vel)
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
    wheels_vel[0] = vel.x - vel.y - vel.theta;
    wheels_vel[1] = vel.x + vel.y + vel.theta;
    wheels_vel[2] = vel.x + vel.y - vel.theta;
    wheels_vel[3] = vel.x - vel.y + vel.theta;

    motors[0].move(wheels_vel[0] < 0 ? !wheels_forward_dir[0] : wheels_forward_dir[0], wheels_vel[0]);
    motors[1].move(wheels_vel[1] < 0 ? !wheels_forward_dir[1] : wheels_forward_dir[1], wheels_vel[1]);
    motors[2].move(wheels_vel[2] < 0 ? !wheels_forward_dir[2] : wheels_forward_dir[2], wheels_vel[2]);
    motors[3].move(wheels_vel[3] < 0 ? !wheels_forward_dir[3] : wheels_forward_dir[3], wheels_vel[3]);
}