/**
 * @file communication.cpp
 * @brief Implementation of the CommunicationProtocol class for ESP32–Raspberry Pi communication.
 */

#include "pins.h"
#include "motors.h"
#include "communication.h"
#include <Arduino.h>
#include <utility>

/**
 * @brief Default constructor.
 *
 * Creates an uninitialized CommunicationProtocol instance. Pins must be set manually
 * or through a secondary method before use.
 */
CommunicationProtocol::CommunicationProtocol() {
  pinMode(COM_P1, INPUT);
  pinMode(COM_P2, INPUT);
  pinMode(COM_P3, OUTPUT);
  pinMode(COM_P4, OUTPUT);

  this->in1 = COM_P1;
  this->in2 = COM_P2;
  this->out1 = COM_P3;
  this->out2 = COM_P4;
}

/**
 * @brief Parameterized constructor.
 *
 * Initializes the communication interface with specific input and output pins.
 *
 * @param in1 GPIO input pin 1 (e.g., from Raspberry Pi).
 * @param in2 GPIO input pin 2 (e.g., from Raspberry Pi).
 * @param out1 GPIO output pin 1 (e.g., to Raspberry Pi).
 * @param out2 GPIO output pin 2 (e.g., to Raspberry Pi).
 */
CommunicationProtocol::CommunicationProtocol(int in1, int in2, int out1, int out2) {
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);

  this->in1 = in1;
  this->in2 = in2;
  this->out1 = out1;
  this->out2 = out2;
}

/**
 * @brief Sends the current motor spin directions to the Raspberry Pi.
 *
 * Uses output pins to encode the left and right motor directions (e.g., as bits or signals),
 * which the Raspberry Pi can decode to monitor robot status.
 *
 * @param movement the currently performed maneuver.
 */
void CommunicationProtocol::sendManeuverInfo(Movement movement) {
  // Communication bits
  std::pair<int, int> bits = {0, 0};

  // Forward maneuver (11)
  if (movement == Movement::FORWARD) bits = {1, 1};

  // Turn right maneuver (01)
  else if (movement == Movement::RIGHT) bits = {0, 1};

  // Turn left maneuver (10)
  else if (movement == Movement::LEFT) bits = {1, 0};

  // None maneuver (00)
  else if (movement == Movement::STOP) bits = {0, 0};

  // Send message
  digitalWrite(this->out1, bits.first);
  digitalWrite(this->out2, bits.second);
}

/**
 * @brief Reads maneuver instructions from the Raspberry Pi.
 *
 * Checks the input pins and translates their state into a high-level Maneuver command.
 *
 * @return A Movement enum value: FORWARD, LEFT, RIGHT, or STOP.
 */
Movement CommunicationProtocol::readManeuverInfo() {
  // Read communication bits
  std::pair<int, int> bits;
  bits.first = digitalRead(this->in1);
  bits.second = digitalRead(this->in2);

  // Forward maneuver (11)
  if (bits.first == 1 && bits.second == 1) return Movement::FORWARD;

  // Turn right maneuver (01)
  else if (bits.first == 0 && bits.second == 1) return Movement::RIGHT;

  // Turn left maneuver (10)
  else if (bits.first == 1 && bits.second == 0) return Movement::LEFT;

  // None maneuver (00)
  else if (bits.first == 0 && bits.second == 0) return Movement::STOP;

  // Safe return
  return Movement::STOP;
}
