/**
 * @file pins.h
 * @brief Pin configuration header for ESP32-based robot.
 *
 * This file defines all the pin mappings for communication, motor control,
 * line sensors, and ultrasonic sensors.
 */

#ifndef PINS_H
#define PINS_H

/** @name Communication Pins
 *  Pins used for communication between components.
 */
///@{
#define COM_P1 18  /**< Communication Pin 1 */
#define COM_P2 19  /**< Communication Pin 2 */
#define COM_P3 21  /**< Communication Pin 3 */
#define COM_P4 3   /**< Communication Pin 4 */
///@}

/** @name Motor Control Pins
 *  Pins used to control the motors (H-bridge driver).
 */
///@{
#define ENA 15     /**< Enable pin for Motor A */
#define IN1 2      /**< Input 1 for Motor A */
#define IN2 4      /**< Input 2 for Motor A */
#define IN3 16     /**< Input 1 for Motor B */
#define IN4 17     /**< Input 2 for Motor B */
#define ENB 5      /**< Enable pin for Motor B */
///@}

/** @name Line Sensor Pins
 *  Digital input pins connected to line-following sensors.
 */
///@{
#define D1 13      /**< Line sensor 1 */
#define D2 12      /**< Line sensor 2 */
#define D3 14      /**< Line sensor 3 */
#define D4 27      /**< Line sensor 4 */
#define D5 26      /**< Line sensor 5 */
///@}

/** @name Ultrasonic Sensor Pins
 *  Pins used for ultrasonic distance measurement.
 */
///@{
#define ECHO 33    /**< Echo pin for ultrasonic sensor */
#define TRIG 25    /**< Trigger pin for ultrasonic sensor */
///@}

#endif // PINS_H
