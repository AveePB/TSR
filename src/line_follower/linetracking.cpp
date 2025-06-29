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
  // Replace with actual sensor reading logic and movement decision.

  return Movement::STOP;
}
