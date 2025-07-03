/**
 * @file line_follower.ino 
 * @brief Main code of the line follower.
 */

#include "ultrasonic.h"
#include "linetracking.h"
#include "motors.h"
#include "communication.h"

const int OBSTACLE_DETECTION_DISTANCE = 15; // in centimeters

// Electronic components
Motor motors;
LineSensor lineSensor;
UltrasonicSensor ultrasonicSensor;
CommunicationProtocol communicationProtocol;

void setup() { }

void loop() {
  // Read correction info
  Movement currMovement = lineSensor.findLine();
  
  // Obstacle detected (in cm)
  if (ultrasonicSensor.findObstacle() < OBSTACLE_DETECTION_DISTANCE) currMovement = Movement::STOP;

  // Stop signal
  //if (communicationProtocol.readManeuverInfo() == Movement::STOP) currMovement = Movement::STOP;

  // Move forward
  if (currMovement == Movement::FORWARD)
    motors.moveForward();
  
  // Move left
  else if (currMovement == Movement::LEFT) 
    motors.turnLeft();
  
  // Move right
  else if (currMovement == Movement::RIGHT) 
    motors.turnRight();
  
  // Stop
  else 
    motors.stop();
  
  // Send information to Raspberry pi
  //communicationProtocol.sendManeuverInfo(currMovement);  
}
