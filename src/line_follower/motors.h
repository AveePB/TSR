/**
 * @file motors.h
 * @brief Declaration of the Motor class for basic motor-controlling logic.
 */

#ifndef MOTORS_H
#define MOTORS_H
#define SPEED 80

/**
 * @class Motor
 * @brief A class to handle a 2-channel L298N motor driver.
 *
 * Provides high-level methods to control robot movement by driving
 * two motors through direction and enable pins.
 */
class Motor {
  public:
    /**
     * @brief Default constructor.
     *
     * Initializes the Motor object without assigning any pins.
     */
    Motor();

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
    Motor(int ena, int in1, int in2, int in3, int in4, int enb);

    /**
     * @brief Destructor.
     *
     * Cleans up resources (currently does nothing).
     */
    ~Motor();

    /**
     * @brief Moves both motors forward.
     */
    void moveForward();

    /**
     * @brief Turns the robot left by adjusting motor directions.
     */
    void turnLeft();

    /**
     * @brief Turns the robot right by adjusting motor directions.
     */
    void turnRight();

    /**
     * @brief Stops both motors.
     */
    void stop();

  private:
    int ena; /**< Enable pin for left motor. */
    int in1; /**< IN1 pin for left motor direction. */
    int in2; /**< IN2 pin for left motor direction. */
    int in3; /**< IN3 pin for right motor direction. */
    int in4; /**< IN4 pin for right motor direction. */
    int enb; /**< Enable pin for right motor. */
    int speed; /**< Pwm speed (0-255). */
};

#endif // MOTORS_H
