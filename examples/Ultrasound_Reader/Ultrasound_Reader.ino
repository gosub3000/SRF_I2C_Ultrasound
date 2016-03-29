/*
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
 *
 * SRF02 Sensor Reader
 *
 * Reads data from a Devantech SRF02 ultrasonic sensor.
 * Should also work for the SRF08 and SRF10 sensors as well.
 *
 * Sensor connections:
 * SDA - A4
 * SCL - A5
 *
 */
// include wire library to read and write I2C commands:
#include <Wire.h>
#include <I2CUltrasound.h>

I2CUltrasound sensor(centimeters);

void setup(){
  // open the serial port
  Serial.begin(9600);
}

void loop(){
  // send the command to read the result in cm
  int sensorReading = sensor.getDistance();
  
  // print it
  Serial.print("Distance: ");
  Serial.print(sensorReading);
  Serial.println(" cm");

  // wait for next reading
  delay(1000);
}