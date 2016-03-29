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

#include "Arduino.h"
#include "I2CUltrasound.h"
// include wire library to read and write I2C commands:
#include <Wire.h>

I2CUltrasound::I2CUltrasound(enum Units measurementUnits) {
	_units = measurementUnits;

	// start the I2C bus
	Wire.begin();
}

void I2CUltrasound::sendCommand(int command) {
	// start I2C transmission
	Wire.beginTransmission(_sensorAddress);

	// send the command
	Wire.write(0x00);
	Wire.write(command);

	// end I2C transmission
	Wire.endTransmission();
}

/*
 * Set Register
 * Tells the SRF sensor to change the address pointer position
 *
 * @param address, the I2C device address
 * @param reg, the device register to set
 */
void I2CUltrasound::setRegister(int reg) {
	// start I2C transmission
	Wire.beginTransmission(_sensorAddress);

	// send the address to read from
	Wire.write(reg);

	// end I2C
	Wire.endTransmission();
}

/*
 * Read Data
 * Returns a result from the SRF sensor
 *
 * @returns, two bytes of data from the selected address/register pair.
 */
int I2CUltrasound::readData() {
	int result = 0;
	int bytes = 2;

	// send I2C request for data
	Wire.requestFrom(_sensorAddress, bytes);

	// wait for 2 bytes to return
	while (Wire.available() < bytes) {
		// busy wait
	}

	// read the two bytes and combine them into one int
	result = Wire.read() * 256;
	result = result + Wire.read();

	// return the result
	return result;
}

int I2CUltrasound::getDistance() {
	// send the command to read the distance
	sendCommand (_units);

	// wait at least 70 milliseconds for a result:
	delay(70);

	// set the register that you want to read the result from
	setRegister (_resultRegister);

	// read the result
	return readData();

}
