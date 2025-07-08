/**
 * @file motors.cpp
 * @brief Implementation of the Motor class for basic motor-controlling logic.
 */

#include "motors.h"
#include "pins.h"
#include <Arduino.h>

/**
 * @brief Default constructor.
 *
 * Initializes the Motor object without assigning any pins.
 */
Motor::Motor() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  this->ena = ENA;
  this->in1 = IN1;
  this->in2 = IN2;
  this->in3 = IN3;
  this->in4 = IN4;
  this->enb = ENB;

  this->speed = SPEED;
  this->stop();
}

/**
 * @brief Parameterized constructor.
 *
 * Initializes the Motor object with specified motor driver pins.
 *
 * @param ena Enable pin for left motor.
 * @param in1 IN1 pin for left motor direction.
 * @param in2 IN2 pin for left motor direction.
 * @param in3 IN3 pin for right motor direction.
 * @param in4 IN4 pin for right motor direction.
 * @param enb Enable pin for right motor.
 */
Motor::Motor(int ena, int in1, int in2, int in3, int in4, int enb) {
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enb, OUTPUT);

  this->ena = ena;
  this->in1 = in1;
  this->in2 = in2;
  this->in3 = in3;
  this->in4 = in4;
  this->enb = enb;

  this->speed = SPEED;
  this->stop();
}

/**
 * @brief Destructor.
 *
 * Cleans up resources (currently does nothing).
 */
Motor::~Motor() {
  this->stop();
}

/**
 * @brief Moves both motors forward.
 */
void Motor::moveForward() {
  // Set left motor to forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, this->speed);

  // Set right motor to forward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, this->speed);
}

/**
 * @brief Turns the robot left by adjusting motor directions.
 */
void Motor::turnLeft() {
  // Set left motor to backward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, this->speed);

  // Set right motor to forward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, this->speed);
}

/**
 * @brief Turns the robot right by adjusting motor directions.
 */
void Motor::turnRight() {
  // Set left motor to forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, this->speed);

  // Set right motor to backward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, this->speed);
}

/**
 * @brief Stops both motors.
 */
void Motor::stop() {
  // Stop left motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  // Stop right motor
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}
