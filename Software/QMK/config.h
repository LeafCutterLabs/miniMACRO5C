 /*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xCEEB
#define PRODUCT_ID      0x0007
#define DEVICE_VER      0x0001
#define MANUFACTURER    leafcutterlabs
#define PRODUCT         miniMACRO5c
#define DESCRIPTION     5 key/rotary board with USB-C

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 5

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *                  NO_DIODE = switches are directly connected to AVR pins
 *
*/
// #define MATRIX_ROW_PINS { D0, D5 }
// #define MATRIX_COL_PINS { F1, F0, B0 }
// { D6, D7, D5, F1, F0 } v1 
#define DIRECT_PINS {   \
    { D6, D7, D5, C6, C7} \
}

//speed for double tap
#define TAPPING_TERM 200

#define UNUSED_PINS

/* rotary encoder 1,2,3 closest to usb port is 0*/
#define ENCODERS_PAD_B { D0, D2, E6, B0, B5}
#define ENCODERS_PAD_A { D1, D3, B7, B4, B6}
#define ENCODER_RESOLUTION 4 //default/suggested

#define MIDI_BASIC

/* ws2812 RGB LED */
#define RGB_DI_PIN D4
#define RGBLED_NUM 5    // Number of LEDs

#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0
