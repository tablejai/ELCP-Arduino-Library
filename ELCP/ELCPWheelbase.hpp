#include "ELCPMotor.hpp"
#include "coord_sys.hpp"

class ELCPWheelbase
{
    /*  Wheel Index
     *
     *  Wheel 0    Wheel 1
     *      I-------I 
     *      |       \
     *      |       \
     *      |       \
     *      I-------I
     *   Wheel 2   Wheel 3
     */
public:
    ELCPWheelbase(int front_left_wheel, int front_right_wheel, int back_left_wheel, int back_right_wheel, float wheel_to_x_centre, float wheel_to_y_centre) : motors{front_left_wheel, front_right_wheel, back_left_wheel, back_right_wheel}
    {
        wheels_forward_dir[0] = 1;
        wheels_forward_dir[1] = 1;
        wheels_forward_dir[2] = 1;
        wheels_forward_dir[3] = 1;
    }

    void wbToWheelVel(XYTheta);

private:
    ELCPMotor motors[4];
    float wheels_vel[4];
    uint8_t wheels_forward_dir[4];
    float wheel_radius;
};