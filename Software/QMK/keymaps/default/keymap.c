#include QMK_KEYBOARD_H

#define _MAIN 0

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder*/
    if (clockwise) {
      tap_code(KC_1);
    } else {
      tap_code(KC_2);
    }
  } else if (index == 1) { /* Second encoder*/  
    if (clockwise) {
      tap_code(KC_3);
    } else {
      tap_code(KC_4);
    }
  } else if (index == 2) { /* Third encoder*/  
    if (clockwise) {
      tap_code(KC_5);
    } else {
      tap_code(KC_6);
    }
  } else if (index == 3) { /* Fourth encoder*/  
    if (clockwise) {
      tap_code(KC_7);
    } else {
      tap_code(KC_8);
    }
  } else if (index == 4) { /* Fifth encoder*/  
    if (clockwise) {
      tap_code(KC_9);
    } else {
      tap_code(KC_0);
    }
  }
}

enum {
  TD_RGB = 0
};

void dance_rgb_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_E);
	unregister_code (KC_E);
  } else if (state->count == 2) {
    rgblight_toggle();
  } else if (state->count == 3) {
    rgblight_step();
  }
}

//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_RGB] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_rgb_finished, NULL)
};

enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QMKBEST:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_LALT("a"));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};

//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //buttion closest to usb is first
  [_MAIN] = LAYOUT(
     KC_A, KC_B, KC_C, KC_D, TD(TD_RGB) 
  )
};
