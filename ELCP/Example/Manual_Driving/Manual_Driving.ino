#include "ELCP.h"

ELCPController BetaFPV;
ELCPWheelbase wb{1, 2, 3, 4, 0.1, 0.1};
ELCPServo servo_1{1};

void setup()
{
  BetaFPV.begin();
}

void loop()
{
  if (BetaFPV.read())
  {
    XYTheta ctrl = BetaFPV.getXYTheta();
    wb.wbToWheelVel(BetaFPV.getXYTheta(), 50, false);
    if (BetaFPV.getSA() == LEVER_UP)
    {
      servo_1.move(180);
    }
    else
    {
      servo_1.move(0);
    }
  }
}
