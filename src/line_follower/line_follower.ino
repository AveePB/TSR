/**
 * @file line_follower.ino 
 * @brief Main code of the line follower.
 */

#include "ultrasonic.h"
#include "linetracking.h"
#include "motors.h"
#include "communication.h"

// Electronic components
Motor motors;
LineSensor lineSensor;
UltrasonicSensor ultrasonicSensor;
CommunicationProtocol communicationProtocol;

void setup() { }

void loop() {
  // Read correction info
  Movement currMovement = lineSensor.findLine();
  
  // Obstacle detected
  if (lineSensor.findObstacle() < 15) motors.stop();

  // Move forward
  if (currMovement == Movement::FORWARD)
    motors.moveForward();
  
  // Move left
  else if (currMovement == Movement::LEFT)
    motors.turnLeft();
  
  // Move right
  else if (currMovement == Movement::RIGHT);
    motors.turnRight();
  
  // Stop
  else
    motors.stop();
}
