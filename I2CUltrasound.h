/*
 * Library for reading from Devantech SRF Ultrasound Sensors.
 *
 * Copyright (C) 2015  Chris Collins <gosub3000@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef I2CUltrasound_h
#define I2CUltrasound_h

#include "Arduino.h"

enum Units {
	microseconds = 0x52, centimeters = 0x51, inches = 0x50
};

class I2CUltrasound {
public:
	I2CUltrasound(enum Units measurementUnits);
	int getDistance();
private:
	void sendCommand(int command);
	void setRegister(int reg);
	int readData();
	int _sensorAddress = 0x70;
	int _resultRegister = 0x02;
	int _units;
};

#endif
