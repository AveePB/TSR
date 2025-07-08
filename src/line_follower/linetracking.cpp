/**
 * @file linetracking.cpp
 * @brief Implementation of the LineSensor class for interpreting line-following sensor data.
 */

#include "linetracking.h"
#include "pins.h"
#include <Arduino.h>

/**
 * @brief Default constructor.
 *
 * Initializes the LineSensor using predefined pin constants from pins.h.
 */
LineSensor::LineSensor() {
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);

  this->d1 = D1;
  this->d2 = D2;
  this->d3 = D3;
  this->d4 = D4;
  this->d5 = D5;
}

/**
 * @brief Parameterized constructor.
 *
 * Assigns custom pin values to the sensor inputs.
 *
 * @param d1 Pin for leftmost sensor.
 * @param d2 Pin for left-middle sensor.
 * @param d3 Pin for center sensor.
 * @param d4 Pin for right-middle sensor.
 * @param d5 Pin for rightmost sensor.
 */
LineSensor::LineSensor(int d1, int d2, int d3, int d4, int d5) {
  pinMode(d1, INPUT);
  pinMode(d2, INPUT);
  pinMode(d3, INPUT);
  pinMode(d4, INPUT);
  pinMode(d5, INPUT);

  this->d1 = d1;
  this->d2 = d2;
  this->d3 = d3;
  this->d4 = d4;
  this->d5 = d5;
}

/**
 * @brief Destructor.
 *
 * Currently performs no operations, as no dynamic memory is used.
 */
LineSensor::~LineSensor() {

}

/**
 * @brief Reads sensor values and determines robot direction.
 *
 * Reads digital inputs from the five sensors and evaluates which direction
 * the robot should move based on the detected line pattern.
 *
 * @return A Movement value: FORWARD, LEFT, RIGHT or STOP.
 */
Movement LineSensor::findLine() {
  // Read data from sensor
  int in1 = digitalRead(this->d1);
  int in2 = digitalRead(this->d2);
  int in3 = digitalRead(this->d3);
  int in4 = digitalRead(this->d4);
  int in5 = digitalRead(this->d5);

  // Go forward
  if (
    (in1 == 0 && in2 == 0 && in3 == 1 && in4 == 0 && in5 == 0) || // 0 0 1 0 0
    (in1 == 0 && in2 == 1 && in3 == 1 && in4 == 1 && in5 == 0) || // 0 1 1 1 0
    (in1 == 1 && in2 == 1 && in3 == 1 && in4 == 1 && in5 == 1)    // 1 1 1 1 1
  ) return Movement::FORWARD;

  // Go right
  else if (
    (in1 == 0 && in2 == 0 && in3 == 0 && in4 == 0 && in5 == 1) || // 0 0 0 0 1
    (in1 == 0 && in2 == 0 && in3 == 0 && in4 == 1 && in5 == 0) || // 0 0 0 1 0
    (in1 == 0 && in2 == 0 && in3 == 0 && in4 == 1 && in5 == 1) || // 0 0 0 1 1
    (in1 == 0 && in2 == 0 && in3 == 1 && in4 == 1 && in5 == 0) || // 0 0 1 1 0
    (in1 == 0 && in2 == 0 && in3 == 1 && in4 == 1 && in5 == 1) || // 0 0 1 1 1
    (in1 == 0 && in2 == 0 && in3 == 1 && in4 == 1 && in5 == 1)    // 0 1 1 1 1
  ) return Movement::RIGHT;

  // Go left
  else if (
    (in1 == 1 && in2 == 0 && in3 == 0 && in4 == 0 && in5 == 0) || // 1 0 0 0 0
    (in1 == 0 && in2 == 1 && in3 == 0 && in4 == 0 && in5 == 0) || // 0 1 0 0 0
    (in1 == 1 && in2 == 1 && in3 == 0 && in4 == 0 && in5 == 0) || // 1 1 0 0 0
    (in1 == 0 && in2 == 1 && in3 == 1 && in4 == 0 && in5 == 0) || // 0 1 1 0 0
    (in1 == 1 && in2 == 1 && in3 == 1 && in4 == 0 && in5 == 0) || // 1 1 1 0 0
    (in1 == 1 && in2 == 1 && in3 == 1 && in4 == 0 && in5 == 0)    // 1 1 1 1 0
  ) return Movement::LEFT;

  // Don't move
  return Movement::STOP;
}
