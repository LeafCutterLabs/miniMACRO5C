#include QMK_KEYBOARD_H

#define _MAIN 0
#include "midi.h"

extern MidiDevice midi_device;

enum midi_cc_keycodes_LTRM { MIDI_CC1 = SAFE_RANGE, MIDI_CC2, MIDI_CC3, MIDI_CC4, MIDI_CC5 };
static uint8_t current_MIDI_ccNumber         = 1;
static char    current_MIDI_ccNumber_char[3] = {'0', '1', '\0'};

int16_t encoder0_val = 64;
int16_t encoder1_val = 64;
int16_t encoder2_val = 64;
int16_t encoder3_val = 64;
int16_t encoder4_val = 64;
#define encoder_step 3

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder*/
    if (clockwise) { //device, channel, number, value
      encoder0_val=encoder0_val+encoder_step;
      midi_send_cc(&midi_device, 0, 1, encoder0_val);
    } else {
      encoder0_val=encoder0_val-encoder_step;
      midi_send_cc(&midi_device, 0, 1, encoder0_val);
    }
  } else if (index == 1) { /* Second encoder*/  
    if (clockwise) {
      encoder1_val=encoder1_val+encoder_step;
      midi_send_cc(&midi_device, 0, 2, encoder1_val);
    } else {
      encoder1_val=encoder1_val-encoder_step;
      midi_send_cc(&midi_device, 0, 2, encoder1_val);
    }
  } else if (index == 2) { /* Third encoder*/  
    if (clockwise) {
      encoder2_val=encoder2_val+encoder_step;
      midi_send_cc(&midi_device, 0, 3, encoder2_val);
    } else {
      encoder2_val=encoder2_val-encoder_step;
      midi_send_cc(&midi_device, 0, 3, encoder2_val);
    }
  } else if (index == 3) { /* Fourth encoder*/  
    if (clockwise) {
      encoder3_val=encoder3_val+encoder_step;
      midi_send_cc(&midi_device, 0, 4, encoder3_val);
    } else {
      encoder3_val=encoder3_val-encoder_step;
      midi_send_cc(&midi_device, 0, 4, encoder3_val);
    }
  } else if (index == 4) { /* Fifth encoder*/  
    if (clockwise) {
      encoder4_val=encoder4_val+encoder_step;
      midi_send_cc(&midi_device, 0, 5, encoder4_val);
    } else {
      encoder4_val=encoder4_val-encoder_step;
      midi_send_cc(&midi_device, 0, 5, encoder4_val);
    }
	}
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //buttion closest to usb is first
  [_MAIN] = LAYOUT(
     MIDI_CC1, MIDI_CC2, MIDI_CC3, MIDI_CC4, MIDI_CC5
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MIDI_CC1:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 1;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '1';
            } else {
            }
            return false;
            break;
        case MIDI_CC2:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 2;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '2';
            } else {
            }
            return false;
            break;
        case MIDI_CC3:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 3;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '3';
            } else {
            }
            return false;
            break;
        case MIDI_CC4:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 4;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '4';
            } else {
            }
            return false;
            break;
        case MIDI_CC5:
            if (record->event.pressed) {
                current_MIDI_ccNumber         = 5;
                current_MIDI_ccNumber_char[0] = '0';
                current_MIDI_ccNumber_char[1] = '5';
            } else {
            }
            return false;
            break;
		default:
            break;
    }
    return true;
}
