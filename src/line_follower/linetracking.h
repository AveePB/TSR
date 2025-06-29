/**
 * @file linetracking.h
 * @brief Declaration of the LineSensor class for basic line-following logic.
 */

#ifndef LINETRACKING_H
#define LINETRACKING_H

/**
 * @enum Movement
 * @brief Represents the possible movement directions based on line sensor readings.
 */
enum class Movement {
  FORWARD, /**< Indicates the robot should continue moving forward. */
  LEFT,    /**< Indicates the robot should turn left. */
  RIGHT,    /**< Indicates the robot should turn right. */
  STOP    /**< Indicates the robot should stop. */
};

/**
 * @class LineSensor
 * @brief A class to handle a 5-channel digital line sensor array.
 *
 * This class provides methods to initialize line sensor pins and determine
 * the robot's movement based on the sensor readings.
 */
class LineSensor {
  public:
    /**
     * @brief Default constructor.
     *
     * Initializes the sensor without assigning pins. Pins must be set manually or unused.
     */
    LineSensor();

    /**
     * @brief Parameterized constructor.
     *
     * Initializes the line sensor with specified digital input pins.
     *
     * @param d1 Pin for leftmost sensor.
     * @param d2 Pin for left-middle sensor.
     * @param d3 Pin for center sensor.
     * @param d4 Pin for right-middle sensor.
     * @param d5 Pin for rightmost sensor.
     */
    LineSensor(int d1, int d2, int d3, int d4, int d5);

    /**
     * @brief Destructor.
     *
     * Cleans up any resources if necessary (currently unused).
     */
    ~LineSensor();

    /**
     * @brief Analyzes the line sensor readings and determines the robot's direction.
     *
     * @return A Movement enum indicating whether to go FORWARD, LEFT, or RIGHT.
     */
    Movement findLine();

  private:
    int d1; /**< GPIO pin for leftmost line sensor. */
    int d2; /**< GPIO pin for left-middle line sensor. */
    int d3; /**< GPIO pin for center line sensor. */
    int d4; /**< GPIO pin for right-middle line sensor. */
    int d5; /**< GPIO pin for rightmost line sensor. */
};

#endif // LINETRACKING_H
