#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _NUM 1
#define _NAV 2
#define _CMD 3
#define _CTL 4

#define ___T___ KC_TRNS
#define CMD LM(_CMD, MOD_LGUI)
#define CTL LM(_CTL, MOD_LCTL)
#define NAV TG(_NAV)
#define NUM_BSP LT(_NUM, KC_BSPC)
#define NAV_SPC LT(_NAV, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( // 0
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_RSFT,
    KC_Z,    KC_X,    KC_C,    KC_V,    NUM_BSP,                   NAV_SPC, KC_B,    KC_N,    KC_M,    KC_ENT,
                               CTL,     NUM_BSP, CMD,     NAV,     NAV_SPC, KC_ESC
),


[_NUM] = LAYOUT( // 1
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_7,    KC_9,    KC_0,
    KC_ESC,  KC_MINS, KC_EQL,  S(KC_9), KC_LBRC,                   KC_RBRC, S(KC_0), KC_QUOT, KC_SCLN, ___T___,
    KC_GRV,  KC_LCTL, KC_LGUI, KC_LALT, ___T___,                   KC_TAB,  KC_BSLS, KC_COMM, KC_DOT,  KC_SLSH,
                               _______, ___T___, ___T___, ___T___, KC_TAB,  ___T___
),


[_NAV] = LAYOUT( // 2
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F15,                    KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC__VOLUP,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F14,                    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, ___T___,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,                    ___T___, KC_LALT, KC_LGUI, KC_LCTL, KC__VOLDOWN,
                               RESET,   KC_DEL,  ___T___, ___T___, ___T___, ___T___
),


[_CMD] = LAYOUT( // 3
    KC_1,    KC_2,    KC_E,    KC_R,    _______,                   _______, _______, _______, KC_9,    KC_0,
    KC_ESC,  KC_GRV, S(KC_TAB), KC_TAB, _______,                   _______, _______, _______, _______, ___T___,
    KC_Z,    KC_X,    KC_C,    KC_V,    _______,                   NAV_SPC, _______, _______, _______, _______,
                               _______, _______, ___T___, ___T___, NAV_SPC, ___T___
),

[_CTL] = LAYOUT( // 4
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    KC_ESC,  _______, S(KC_TAB),KC_TAB, _______,                   _______, _______, _______, _______, ___T___,
    _______, _______, _______, _______, _______,                   NAV_SPC, _______, _______, _______, _______,
                               _______, _______, ___T___, ___T___, NAV_SPC, ___T___
)

//[_EMPTY] = LAYOUT( // 15
//    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
//    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, ___T___,
//    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
//                               _______, _______, ___T___, ___T___, _______, _______
//)

};

void persistant_deifault_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);;
}
