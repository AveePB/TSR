/**
 * @file communication.h
 * @brief Declaration of the CommunicationProtocol class for ESP32–Raspberry Pi communication.
 */

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "linetracking.h"

/**
 * @class CommunicationProtocol
 * @brief Handles GPIO-based communication between a Raspberry Pi and an ESP32.
 *
 * This class provides methods for sending maneuver information (e.g., motor states)
 * from the ESP32 to the Raspberry Pi, and for reading maneuver commands from the Pi.
 */
class CommunicationProtocol {
  public:
    /**
     * @brief Default constructor.
     *
     * Creates an uninitialized CommunicationProtocol instance. Pins must be set manually
     * or through a secondary method before use.
     */
    CommunicationProtocol();

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
    CommunicationProtocol(int in1, int in2, int out1, int out2);

    /**
     * @brief Sends the current motor spin directions to the Raspberry Pi.
     *
     * Uses output pins to encode the left and right motor directions (e.g., as bits or signals),
     * which the Raspberry Pi can decode to monitor robot status.
     *
     * @param movement the currently performed maneuver.
     */
    void sendManeuverInfo(Movement movement);

    /**
     * @brief Reads maneuver instructions from the Raspberry Pi.
     *
     * Checks the input pins and translates their state into a high-level Maneuver command.
     *
     * @return A Maneuver enum value: FORWARD, LEFT, RIGHT, or STOP.
     */
    Movement readManeuverInfo();

  private:
    int in1;  /**< GPIO input pin 1 for receiving maneuver instructions. */
    int in2;  /**< GPIO input pin 2 for receiving maneuver instructions. */
    int out1; /**< GPIO output pin 1 for sending status information. */
    int out2; /**< GPIO output pin 2 for sending status information. */
};

#endif // COMMUNICATION_H
