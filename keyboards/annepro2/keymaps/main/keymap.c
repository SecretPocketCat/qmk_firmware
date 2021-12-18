#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
};

 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    LT(_FN2_LAYER, KC_CAPSLOCK), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
    KC_LCTRL, RALT_T(KC_LGUI), LT(_FN1_LAYER,KC_HOME), KC_SPC, LT(_FN1_LAYER,KC_END), MO(_FN2_LAYER), KC_RGUI, KC_RCTRL
),

 [_FN1_LAYER] = KEYMAP( /* Base */
    KC_GRV, KC_TRNS, RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5), RALT(KC_6), RALT(KC_7), RALT(KC_8), RALT(KC_9), RALT(KC_0), KC_TRNS, KC_TRNS, KC_DEL,
    KC_TRNS, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_MS_BTN4, KC_MS_BTN5, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS, KC_TRNS, KC_DELETE, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSPACE, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_MY_COMPUTER, LWIN(KC_X), KC_CALCULATOR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

 [_FN2_LAYER] = KEYMAP( /* Base */
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MEDIA_PREV_TRACK,
    KC_TRNS, KC_ACL2, KC_TRNS, KC_TRNS, KC_F5, KC_TRNS, KC_TRNS, KC_TRNS, RCS(KC_UP), KC_TRNS, KC_PSCREEN, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RCS(KC_LEFT), RCS(KC_DOWN), RCS(KC_RIGHT), KC_TRNS, KC_AUDIO_MUTE, KC_MEDIA_PLAY_PAUSE,
    KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_TRNS, KC_AP_LED_PREV_PROFILE, KC_AP_LED_NEXT_PROFILE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 ),
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    annepro2LedEnable();
    annepro2LedSetProfile(12);
}

layer_state_t layer_state_set_user(layer_state_t layer) {
  switch(get_highest_layer(layer)) {
    case _FN1_LAYER:
      annepro2LedSetForegroundColor(0, 17, 12);
      // annepro2LedSetForegroundColor(0, 138, 124);
      break;
    case _FN2_LAYER:
      annepro2LedSetForegroundColor(10, 0, 17);
      // annepro2LedSetForegroundColor(27, 0, 44);
      break;
    default:
      // Reset back to the current profile
      annepro2LedResetForegroundColor();
      break;
  }
  return layer;
}

// The function to handle the caps lock logic
// It's called after the capslock changes state or after entering layers 1 and 2.
bool led_update_user(led_t leds) {
  if (leds.caps_lock) {
    annepro2LedSetForegroundColor(255, 255, 255);
  } else {
    // Reset the capslock if there is no layer active
    if(!layer_state_is(_FN1_LAYER) && !layer_state_is(_FN2_LAYER)) {
      annepro2LedResetForegroundColor();
    }
  }

  return true;
}
