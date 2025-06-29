#include "ultrasonic.h"
#include "linetracking.h"
#include "motors.h"

// Electronic components
Motor motors;
LineSensor lineSensor;
UltrasonicSensor ultrasonicSensor;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  motors.moveForward();
  delay(1000);
  motors.stop();
  delay(1000);

}
