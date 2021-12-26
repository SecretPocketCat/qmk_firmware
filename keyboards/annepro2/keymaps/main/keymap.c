#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"
#include "wpm.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
};

enum custom_keycodes {
    DEL_WORD = 30000,
    BCKSPC_WORD,
};

 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_LAYER] = KEYMAP( /* Base */
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      LT(_FN2_LAYER, KC_CAPSLOCK), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
      KC_LCTRL, LALT_T(KC_LGUI), LT(_FN1_LAYER,KC_HOME), KC_SPC, LT(_FN1_LAYER,KC_END), MO(_FN2_LAYER), KC_RGUI, KC_RCTRL
  ),

  [_FN1_LAYER] = KEYMAP(
      KC_GRV, KC_TRNS, RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5), RALT(KC_6), RALT(KC_7), RALT(KC_8), RALT(KC_9), RALT(KC_0), KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, LWIN(KC_Z), LSFT(KC_UP), KC_MY_COMPUTER, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RIGHT), KC_TRNS, KC_TRNS, KC_BSPACE, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DELETE, KC_TRNS, KC_TRNS,
      KC_TRNS, LWIN(KC_Z), LWIN(KC_X), KC_CALCULATOR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_FN2_LAYER] = KEYMAP(
      KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MEDIA_PREV_TRACK,
      KC_TRNS, KC_TRNS, RCS(KC_UP), KC_TRNS, KC_F5, KC_TRNS, KC_TRNS, KC_TRNS, RCTL(KC_UP), KC_TRNS, KC_PSCREEN, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK,
      KC_TRNS, RCS(KC_LEFT), RCS(KC_DOWN), RCS(KC_RIGHT), KC_TRNS, KC_TRNS, BCKSPC_WORD, RCTL(KC_LEFT), RCTL(KC_DOWN), RCTL(KC_RIGHT), DEL_WORD, KC_AUDIO_MUTE, KC_MEDIA_PLAY_PAUSE,
      KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_AP2_USB, KC_AP_LED_PREV_PROFILE, KC_AP_LED_NEXT_PROFILE, KC_AP_LED_ON, KC_AP_LED_OFF, KC_AP_LED_NEXT_INTENSITY, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};
const uint16_t keymaps_size = sizeof(keymaps);

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
  // main loop stuff goes here?

  if(!layer_state_is(_FN1_LAYER) && !layer_state_is(_FN2_LAYER)) {
    uint8_t current_wpm = get_current_wpm();
    const annepro2Led_t col = {
      .p.red = 255,
      .p.green = 255,
      .p.blue = 255,
      .p.alpha = 255,
    };

    const annepro2Led_t col_off = {
      .p.red = 0,
      .p.green = 0,
      .p.blue = 0,
      .p.alpha = 0,
    };

    uint8_t wpm_key_count = current_wpm / 10;
    
    if (wpm_key_count > 10) {
      wpm_key_count = 10;
    }

    for (size_t i = 1; i <= 10; i++)
    {
      if (i <= wpm_key_count) {
        annepro2LedMaskSetKey(0, i, col);
      } else {
        annepro2LedMaskSetKey(0, i, col_off);
      }
    }
  }
}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    annepro2LedEnable();
    annepro2LedSetProfile(0);
}

const annepro2Led_t LAYER1_COL = {
    .p.red = 0,
    .p.green = 250,
    .p.blue = 130,
    .p.alpha = 130
};

const annepro2Led_t LAYER2_COL = {
    .p.red = 120,
    .p.green = 0,
    .p.blue = 250,
    .p.alpha = 130
};

const int8_t LAYER1_KEYS[][2] = 
{ 
  {0,0},
  {0,2},
  {0,3},
  {0,4},
  {0,5},
  {0,6},
  {0,7},
  {0,8},
  {0,9},
  {0,10},
  {1,1},
  {1,2},
  {1,3},
  {1,8},
  {2,1},
  {2,2},
  {2,3},
  {2,6},
  {2,7},
  {2,8},
  {2,9},
  {2,10},
  {3,2},
  {3,3},
  {3,4},
};

const uint8_t LAYER1_SIZE = sizeof(LAYER1_KEYS) / sizeof(LAYER1_KEYS[0]);

const int8_t LAYER2_KEYS[][2] = 
{ 
  {0,1},
  {0,2},
  {0,3},
  {0,4},
  {0,5},
  {0,6},
  {0,7},
  {0,8},
  {0,9},
  {0,10},
  {0,11},
  {0,12},
  {0,13},
  {1,2},
  {1,4},
  {1,8},
  {1,10},
  {1,11},
  {1,12},
  {1,13},
  {2,1},
  {2,2},
  {2,3},
  {2,6},
  {2,7},
  {2,8},
  {2,9},
  {2,10},
  {2,11},
  {2,12},
  {3,2},
  {3,3},
  {3,4},
  {3,5},
  {3,6},
  {3,7},
  {3,8},
  {3,9},
  {3,10},
  {3,11},
  {4,6},
};

const uint8_t LAYER2_SIZE = sizeof(LAYER2_KEYS) / sizeof(LAYER2_KEYS[0]);

void set_layer_color(const int8_t layer_keys[][2], uint8_t key_count, annepro2Led_t color) {
   for (short i = 0; i < key_count; i++) {
      int8_t r = layer_keys[i][0];
      int8_t c = layer_keys[i][1];
      annepro2LedMaskSetKey(r, c, color);
    }
}

layer_state_t layer_state_set_user(layer_state_t layer) {
  switch(get_highest_layer(layer)) {
    case _FN1_LAYER:
      set_layer_color(LAYER1_KEYS, LAYER1_SIZE, LAYER1_COL);
      break;
    case _FN2_LAYER:
      set_layer_color(LAYER2_KEYS, LAYER2_SIZE, LAYER2_COL);
      break;
    default:
      // Reset back to the current profile
      annepro2LedResetForegroundColor();
      break;
  }

  return layer;
}

bool led_update_user(led_t leds) {
  if (leds.caps_lock) {
    // Set the caps-lock color
    const annepro2Led_t color = {
        .p.red = 255,
        .p.green = 255,
        .p.blue = 255,
        .p.alpha = 255
    };

    annepro2LedMaskSetKey(2, 0, color);
  } else {
    // Reset the capslock if there is no layer active
    if(!layer_state_is(_FN1_LAYER) && !layer_state_is(_FN2_LAYER)) {
      const annepro2Led_t color = {
          .p.red = 0,
          .p.green = 0,
          .p.blue = 0,
          .p.alpha = 0
      };
      annepro2LedMaskSetKey(2, 0, color);
    }
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case BCKSPC_WORD:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_LEFT)SS_UP(X_LCTRL)SS_UP(X_LSHIFT)SS_TAP(X_BSPACE));
        }
        return false;

      case DEL_WORD:
          if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_RIGHT)SS_UP(X_LCTRL)SS_UP(X_LSHIFT)SS_TAP(X_BSPACE));
          }
          return false;
    }

    return true;
};
