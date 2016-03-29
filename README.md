# CCollins I2C Ultrasound Library

This library is intended for addressing SRFxx Ultrasonic Distance Rangers using
I2C communications.

For example, using a SRF02, connect the pins as follows:
SRF02 | Arduino
----- | -------
5v Vcc | 5V
SDA | SDA or A4
SCL | SCL or A5
Mode | Do not connect
0v Ground | GND

This library requires the Wire library to create the I2C connection.

See the included example for use.

