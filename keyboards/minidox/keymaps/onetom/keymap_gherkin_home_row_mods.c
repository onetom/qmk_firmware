#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _NUM 1
#define _NAV 2

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LL(mod, kc) MT(MOD_L##mod, KC_##kc) // Left mod toggle + key
#define RR(mod, kc) MT(MOD_R##mod, KC_##kc)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = VERTICAL_LAYOUT( // 0
  KC_Q,                  KC_W,                  KC_E,                  KC_R,                  KC_T,
  LL(CTL, A),            LL(ALT, S),            LL(SFT, D),            LL(GUI, F),            KC_G,
  LL(CTL, Z),            LL(ALT, X),            LL(SFT, C),            LL(GUI, V),            LT(_NAV, KC_SPC),
                                                _______,               LT(_NAV, KC_SPC),      _______,

  KC_Y,                  KC_U,                  KC_I,                  KC_O,                  KC_P,
  KC_H,                  RR(GUI, J),            RR(SFT, K),            RR(ALT, L),            RR(CTL, ESC),
  LT(_NUM, KC_BSPC),     RR(GUI, B),            RR(SFT, N),            RR(ALT, M),            RR(CTL, ENT),
  _______,               LT(_NUM, KC_BSPC),      _______
),


[_NUM] = VERTICAL_LAYOUT( // 1
  KC_1,                  KC_2,                  KC_3,                  KC_4,                  KC_5,
  LL(CTL, F1),           LL(ALT, F2),           LL(SFT, F3),           LL(GUI, F4),           KC_F5,
  LL(CTL, F11),          LL(ALT, F12),          LL(SFT, F13),          LL(GUI, F14),          KC_DEL,
                                                _______,               KC_DEL,                _______,

  KC_6,                  RR(GUI, 7),            RR(SFT, 8),            RR(ALT, 9),            RR(CTL, 0),
  KC_F6,                 RR(GUI, F7),           RR(SFT, F8),           RR(ALT, F9),           RR(CTL, F10),
  _______,               _______,               _______,               _______,               _______,
  _______,               _______,               _______
),


[_NAV] = VERTICAL_LAYOUT( // 2
  KC_GRV,                KC_HOME,               KC_UP,                 KC_END,                _______,
  LL(CTL, TAB),          LL(ALT, LEFT),         LL(SFT, DOWN),         LL(GUI, RIGHT),        _______,
  _______,               _______,               _______,               _______,               _______,
                                                RESET,                 _______,               _______,

  KC_MINS,               KC_EQL,                KC_LBRC,               KC_RBRC,               KC_BSLS,
  KC_COMM,               RR(GUI, DOT),          RR(SFT, SLSH),         RR(ALT, SCLN),         RR(CTL, QUOT),
  KC_ENT,                _______,               KC_PGUP,               KC_PGDN,               _______,
  _______,               KC_ENT,               _______
)
};

void persistant_deifault_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);;
}
