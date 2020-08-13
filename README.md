# ECE332 Diode Thermometer
Utilizing ATMega328 and a temperature sensitive diode to measure temperature

## Intended Use
The purpose of the Diode Thermometer is to be a low cost method to measure how well a new
drywall material will perform with heat. The current-voltage characteristics of a diode changes
with temperature, therefore by fixing the current across the diode at 100μA, the voltage can be
measured to calculate the temperature. In comparison to a reference temperature value
measured by the LM35, the Diode Thermometer has an error range of ±2 degrees Celsius.

## Operating Conditions
Operating voltage range of the device: 1.8V to 6V
Operating temperature: -55ºC to +125ºC
Storage temperature: -65ºC to +150ºC
Maximum DC Current per I/O pin: 40.0mA

## Setup Instructions
To operate the device, connect VCC (Pin 7) to a voltage source that is within the operating voltage
range (1.8V to 6V), GND (Pin 8, 22) to ground, and a 12V supply to the current source.
