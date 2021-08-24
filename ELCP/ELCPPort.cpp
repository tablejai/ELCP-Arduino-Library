/*
  Morse.cpp - Library for BOC-ELCP
  Created by Eric, August, 2021
  Released into the public domain.
*/

#include "Arduino.h"
#include "ELCPPort.hpp"

/**
 * 
 * Port Table be like this:
 * X(Board Pin, PWM Pin, ADC Pin, GPIO Pin)
 * 
 */

#define PORT_TABLE   \
	X(1, 2, 54, A0)  \
	X(2, 3, 56, A2)  \
	X(3, 8, 58, A4)  \
	X(4, 9, 60, A6)  \
	X(5, 10, 62, 63) \
	X(6, 11, 64, 65) \
	X(7, 12, 66, 67) \
	X(8, 13, 68, 69)

#define X(BOARDPORT, PORTPWM, PORTADC, PORTGPIO) \
	if (port == BOARDPORT)                       \
	{                                            \
		_portpwm = PORTPWM;                      \
		_portadc = PORTADC;                      \
		_portgpio = PORTGPIO;                    \
	}

ELCPPort::ELCPPort(int port)
{
	_port = port;
	PORT_TABLE
}