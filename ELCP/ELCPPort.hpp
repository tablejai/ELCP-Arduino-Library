/*
  bocbot.h - Library for BOC-ELCP.
  Created by Eric, August, 2021.
  Released into the public domain.

  ELCPPort.h - Library for BOC-ELCP.
  Modified from bocbot.h by Chalex, August, 2021.
*/
#pragma once

#include <string.h>
#include "Arduino.h"

class ELCPPort
{
public:
  ELCPPort(int port); //type 0 = servo, type 1 = motor, type 2 = sensor
  virtual void init();
  void moveServo(int target);
  void moveMotor(int direction, int speed);

protected:
  int _port;
  int _portgpio;
  int _portpwm;
  int _portadc;
};