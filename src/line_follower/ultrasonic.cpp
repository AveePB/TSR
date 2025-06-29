/**
 * @file ultrasonic.cpp
 * @brief Implementation of the UltrasonicSensor class for distance measurement.
 */

#include "ultrasonic.h"
#include "pins.h"
#include <Arduino.h>

/**
 * @brief Default constructor.
 *
 * Initializes the ultrasonic sensor using predefined pins (ECHO and TRIG) from pins.h.
 * Sets pin modes for input and output accordingly.
 */
UltrasonicSensor::UltrasonicSensor() {
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);

  this->echo = ECHO;
  this->trig = TRIG;
}

/**
 * @brief Parameterized constructor.
 * 
 * Initializes the ultrasonic sensor with user-defined echo and trigger pins.
 * Sets pin modes for the specified pins.
 * 
 * @param echo The pin connected to the sensor's echo output.
 * @param trig The pin connected to the sensor's trigger input.
 */
UltrasonicSensor::UltrasonicSensor(int echo, int trig) {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

  this->echo = echo;
  this->trig = trig;
}

/**
 * @brief Destructor.
 *
 * Cleans up any allocated resources (currently not required).
 */
UltrasonicSensor::~UltrasonicSensor() {
  // No dynamic resources to clean up
}

/**
 * @brief Measures and returns the distance to the nearest obstacle.
 * 
 * Sends a short HIGH pulse on the trigger pin to initiate a measurement.
 * Then listens for the echo and calculates the distance based on the time it takes
 * for the echo to return.
 * 
 * @return Distance to the obstacle in centimeters.
 */
float UltrasonicSensor::findObstacle() {
  // Send a short LOW pulse to ensure a clean HIGH pulse
  digitalWrite(this->trig, LOW);
  delayMicroseconds(2);

  // Send a short HIGH pulse to trigger the ultrasonic burst
  digitalWrite(this->trig, HIGH);
  delayMicroseconds(2);

  // End the trigger pulse
  digitalWrite(this->trig, LOW);

  // Measure the time it takes for the echo to return
  float duration = pulseIn(this->echo, HIGH);

  // Calculate the distance based on the speed of sound (343 m/s)
  float distance = (duration * 0.0343) / 2;

  return distance;
}
 