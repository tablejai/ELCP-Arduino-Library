#include "SBUS.h"
#include "coord_sys.hpp"

class ELCPController : SBUS
{
public:
    ELCPController() : SBUS(Serial1) {}

    typedef enum
    {
        LEVER_UP,
        LEVER_MID,
        LEVER_DOWN
    } LeverStatus;

    void begin();
    bool read();
    void debug();
    uint16_t getRightJoyX();
    uint16_t getRightJoyY();
    uint16_t getLeftJoyX();
    uint16_t getLeftJoyY();
    LeverStatus getSA();
    LeverStatus getSB();
    LeverStatus getSC();
    LeverStatus getSD();
    XYTheta getXYTheta();
    uint16_t getChannel(int channel);

private:
    uint16_t channels[16];
    bool failSafe;
    bool lostFrame;
};