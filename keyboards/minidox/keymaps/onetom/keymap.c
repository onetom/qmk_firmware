#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _NUM 1
#define _SFT 2
#define _NAV 3
#define _SYM 4

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = VERTICAL_LAYOUT( // 0
  KC_Q,                  KC_W,                  KC_E,                  KC_R,                  KC_T,
  KC_A,                  KC_S,                  KC_D,                  KC_F,                  KC_G,
  MT(MOD_LCTL, KC_Z),    MT(MOD_LALT, KC_X),    LT(_NAV, KC_C),        LT(_SYM, KC_V),        LT(_SFT, KC_BSPC),
                                                ALT_T(KC_TAB),         LT(_SFT, KC_BSPC),     GUI_T(KC_SPC),

  KC_Y,                  KC_U,                  KC_I,                  KC_O,                  KC_P,
  KC_H,                  KC_J,                  KC_K,                  KC_L,                  KC_ESC,
  LT(_NUM, KC_SPC),      KC_B,                  MT(MOD_RALT, KC_N),    MT(MOD_RCTL, KC_M),    MT(MOD_RSFT, KC_ENT),
  GUI_T(KC_ENT),         LT(_NUM, KC_SPC),      KC_LCTL
),

[_NUM] = VERTICAL_LAYOUT( // 1
  KC_1,                  KC_2,                  KC_3,                  KC_4,                  KC_5,
  KC_F1,                 KC_F2,                 KC_F3,                 KC_F4,                 KC_F5,
  _______,               _______,               _______,               _______,               _______,
                                                _______,               _______,               KC_DEL,

  KC_6,                  KC_7,                  KC_8,                  KC_9,                  KC_0,
  KC_F6,                 KC_F7,                 KC_F8,                 KC_F9,                 KC_F10,
  _______,               _______,               _______,               _______,               _______,
  _______,               _______,               _______
),

[_SFT] = VERTICAL_LAYOUT( // 2
  LSFT(KC_1),            LSFT(KC_2),            LSFT(KC_3),            LSFT(KC_4),            LSFT(KC_5),
  KC_F11,                KC_F12,                KC_F13,                KC_F14,                KC_F15,
  _______,               _______,               _______,               _______,               _______,
                                                _______,               _______,               _______,

  LSFT(KC_6),            LSFT(KC_7),            LSFT(KC_8),            LSFT(KC_9),            LSFT(KC_0),
  KC_F16,                KC_F17,                KC_F18,                KC_F19,                KC_GRV,
  _______,               _______,               _______,               _______,               _______,
  _______,               _______,               _______
),


[_NAV] = VERTICAL_LAYOUT( // 3
  _______,               _______,               _______,               _______,               _______,
  KC_TAB,                _______,               _______,               _______,               _______,
  _______,               _______,               _______,               _______,               _______,
                                                _______,               _______,               _______,

  KC_MINS,               KC_EQL,                KC_LBRC,               KC_RBRC,               KC_BSLS,
  KC_COMM,               KC_DOT,                KC_SLSH,               KC_SCLN,               KC_QUOT,
  _______,               KC_LEFT,               KC_UP,                 KC_DOWN,               KC_RIGHT,
  _______,               _______,               _______
),


[_SYM] =  VERTICAL_LAYOUT( // 4
  _______,               _______,               _______,               _______,               _______,
  LSFT(KC_TAB),          _______,               _______,               _______,               _______,
  RESET,                 _______,               _______,               _______,               _______,
                                                _______,               _______,               _______,

  LSFT(KC_MINS),         LSFT(KC_EQL),          LSFT(KC_LBRC),         LSFT(KC_RBRC),         LSFT(KC_BSLS),
  LSFT(KC_COMM),         LSFT(KC_DOT),          LSFT(KC_SLSH),         LSFT(KC_SCLN),         LSFT(KC_QUOT),
  _______,               KC_HOME,               KC_PGUP,               KC_PGDN,               KC_END,
  _______,               _______,               _______
)
};

void persistant_deifault_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);;
}
