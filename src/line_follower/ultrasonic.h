/**
 * @file ultrasonic.h
 * @brief Declaration of the UltrasonicSensor class for obstacle detection using an ultrasonic sensor.
 */

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

/**
 * @class UltrasonicSensor
 * @brief A class to interact with an ultrasonic distance sensor.
 *
 * This class allows initialization and reading distance measurements using
 * a typical HC-SR04 ultrasonic sensor (or similar), which uses trigger and echo pins.
 */
class UltrasonicSensor {
  public:
    /**
     * @brief Default constructor.
     *
     * Initializes the sensor without assigning pins. You must manually set pins before use.
     */
    UltrasonicSensor();

    /**
     * @brief Parameterized constructor.
     * 
     * Initializes the ultrasonic sensor with specified echo and trigger pins.
     * 
     * @param echo The pin connected to the sensor's echo output.
     * @param trig The pin connected to the sensor's trigger input.
     */
    UltrasonicSensor(int echo, int trig);

    /**
     * @brief Destructor.
     *
     * Cleans up any resources if needed (currently does nothing).
     */
    ~UltrasonicSensor();

    /**
     * @brief Measures and returns the distance to the nearest obstacle.
     * 
     * Sends an ultrasonic pulse and listens for the echo to determine distance.
     * 
     * @return Distance to the obstacle in centimeters.
     */
    float findObstacle();

  private:
    int echo; /**< GPIO pin connected to the echo pin of the ultrasonic sensor. */
    int trig; /**< GPIO pin connected to the trigger pin of the ultrasonic sensor. */
};

#endif // ULTRASONIC_H
