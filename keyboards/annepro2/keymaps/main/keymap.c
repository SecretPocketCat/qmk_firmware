#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  L_ALPHA,
  L_NAV,
  L_NUM,
  L_CS,
  L_SYM,
  L_FUN,
  L_MED,
};

enum custom_keycodes {
    CODE_AND = 30000,
    CODE_OR,
    // DEL_WORD,
    // BCKSPC_WORD,
    // RUN_CMD,
    // RUN_POWERSHELL,
    // RUN_VS_CODE,
};

 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_ALPHA] = KEYMAP( /* Base */
      KC_NO, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_NO, KC_NO, KC_J, KC_L, KC_U, KC_Y, KC_SCOLON, KC_NO,
      KC_LSPO, KC_A, KC_R, KC_S, KC_T, KC_D, KC_NO, KC_NO, KC_H, KC_N, KC_E, KC_I, KC_O, KC_RSPC,
      KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_K, KC_M, KC_COMMA, KC_DOT, KC_SLASH,
      KC_NO, KC_NO, LT(L_MED, KC_ESCAPE), LT(L_NAV, KC_SPACE), LT(L_CS, KC_TAB), KC_NO, KC_NO, KC_NO, LT(L_SYM, KC_ENTER), LT(L_NUM, KC_BSPACE), LT(L_FUN, KC_DELETE), KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [L_NAV] = KEYMAP( /* Base */
      KC_NO, C(KC_X), C(KC_C), C(KC_V), C(KC_Z), C(KC_Y), KC_NO, KC_NO, C(KC_BSPACE), C(KC_LEFT), KC_UP, C(KC_RIGHT), C(KC_DELETE), KC_NO,
      KC_LSHIFT, KC_NO, KC_LGUI, KC_LALT, KC_LCTRL, KC_NO, KC_NO, KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, KC_LSHIFT,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, C(KC_PGUP), C(KC_PGDOWN), KC_PGDOWN, KC_PGUP, KC_CAPSLOCK,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TAB, KC_BSPACE, KC_DELETE, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [L_NUM] = KEYMAP( /* Base */
      KC_NO, S(KC_COMMA), KC_7, KC_8, KC_9, S(KC_DOT), KC_NO, KC_NO, C(KC_X), C(KC_C), C(KC_V), C(KC_Z), C(KC_Y), KC_NO,
      S(KC_9), KC_0, KC_1, KC_2, KC_3, KC_EQUAL, KC_NO, KC_NO, KC_BSLASH, KC_KP_PLUS, KC_KP_MINUS, KC_KP_ASTERISK, KC_KP_SLASH, S(KC_0),
      KC_NO, KC_NO, KC_4, KC_5, KC_6, S(KC_GRAVE), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_DOT, KC_SPACE, KC_COMMA, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [L_CS] = KEYMAP( /* Base */
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, RALT(KC_8), RALT(KC_5), RALT(KC_3), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [L_SYM] = KEYMAP( /* Base */
      KC_NO, KC_NO, KC_QUOTE, S(KC_5), S(KC_6), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      S(KC_9), S(KC_BSLASH), S(KC_7), KC_EQUAL, S(KC_1), S(KC_MINUS), KC_NO, KC_NO, KC_NO, S(KC_QUOTE), KC_RBRACKET, S(KC_RBRACKET), KC_SCOLON, S(KC_0),
      KC_NO, S(KC_SCOLON), KC_GRAVE, S(KC_3), S(KC_4), RALT(KC_E), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_LBRACKET, KC_SPACE, RSFT(KC_LBRACKET), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),
  
  [L_FUN] = KEYMAP( /* Base */
      KC_NO, KC_F12, KC_F7, KC_F8, KC_F9, C(KC_PSCREEN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_F11, KC_F4, KC_F5, KC_F6, KC_PSCREEN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),
  
  [L_MED] = KEYMAP( /* Base */
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
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
  {0,0}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}, {0,8}, {0,9}, {0,10},
  {1,1}, {1,2}, {1,4}, {1,8}, {1,10}, 
  {2,1}, {2,2}, {2,3}, {2,6}, {2,7}, {2,8}, {2,9}, {2,10},
  {3,4}, {4,4},
};

const uint8_t LAYER1_SIZE = sizeof(LAYER1_KEYS) / sizeof(LAYER1_KEYS[0]);

const int8_t LAYER2_KEYS[][2] = 
{ 
  {0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}, {0,8}, {0,9}, {0,10}, {0,11}, {0,12}, {0,13},
  {1,2}, {1,4}, {1,8}, {1,10}, {1,11}, {1,12}, {1,13},
  {2,1}, {2,2}, {2,3}, {2,6}, {2,7}, {2,8}, {2,9}, {2,10}, {2,11}, {2,12},
  {3,2}, {3,3}, {3,4}, {3,5}, {3,6}, {3,7}, {3,8}, {3,9}, {3,10}, {3,11},
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
    case L_NAV:
      set_layer_color(LAYER1_KEYS, LAYER1_SIZE, LAYER1_COL);
      break;
    case L_NUM:
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
    if(layer_state_is(L_ALPHA)) {
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
      case CODE_AND:
        if (record->event.pressed) {
          SEND_STRING("&&");
        }
        return false;

      case CODE_OR:
        if (record->event.pressed) {
          SEND_STRING("||");
        }
        return false;

      // case BCKSPC_WORD:
      //   if (record->event.pressed) {
      //     SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_LEFT)SS_UP(X_LCTRL)SS_UP(X_LSHIFT)SS_TAP(X_BSPACE));
      //   }
      //   return false;

      // case DEL_WORD:
      //     if (record->event.pressed) {
      //       SEND_STRING(SS_DOWN(X_LCTRL)SS_DOWN(X_LSHIFT)SS_TAP(X_RIGHT)SS_UP(X_LCTRL)SS_UP(X_LSHIFT)SS_TAP(X_BSPACE));
      //     }
      //     return false;

      // case RUN_CMD:
      //   if (record->event.pressed) {
      //     SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) "cmd" SS_TAP(X_ENTER));
      //   }
      //   return false;

      // case RUN_VS_CODE:
      //   if (record->event.pressed) {
      //     SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) "code" SS_TAP(X_ENTER));
      //   }
      //   return false;

      // case RUN_POWERSHELL:
      //   if (record->event.pressed) {
      //     SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) "powershell" SS_TAP(X_ENTER));
      //   }
      //   return false;
    }

    return true;
};
