#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_LAYER0] = LAYOUT(
    CW_TOGG,      KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,            KC_Y,    KC_U,                          KC_I,                          KC_O,                          KC_P,                          KC_BSLS,
    LT(3,KC_ESC), MT(MOD_LGUI,KC_A), MT(MOD_LALT,KC_S), MT(MOD_LSFT,KC_D), MT(MOD_LCTL,KC_F), KC_G,            KC_H,    MT(MOD_LCTL|MOD_RCTL,KC_J),    MT(MOD_LSFT|MOD_RSFT,KC_K),    MT(MOD_LALT|MOD_RALT,KC_L),    MT(MOD_LGUI|MOD_RGUI,KC_SCLN), LT(4,KC_QUOT),
    KC_TRNS,        KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,            KC_N,    KC_M,                          KC_COMM,                       KC_DOT,                        KC_SLSH,                       C(G(KC_Q)),
                                                        KC_TRNS,             KC_TAB,            LT(1,KC_SPC),    LT(2,KC_ENT), KC_BSPC,                  KC_TRNS
  ),

  [_LAYER1] = LAYOUT(
    KC_TRNS, KC_TRNS, S(KC_7), S(KC_8), KC_TRNS,   KC_PMNS,    S(KC_MINS),  S(KC_LBRC), S(KC_RBRC), KC_EQL,    QK_MACRO_1, KC_TRNS,
    KC_TRNS, KC_TRNS, S(KC_4), S(KC_5), S(KC_6), KC_PPLS,    KC_MINS,     KC_LBRC,    KC_RBRC,    S(KC_EQL), QK_MACRO_0, KC_GRV,
    KC_TRNS, KC_TRNS, S(KC_1), S(KC_2), S(KC_3), KC_TRNS,      S(KC_COMM),  S(KC_9),    S(KC_0),    S(KC_DOT), S(KC_GRV),  KC_TRNS,
                           KC_TRNS,   KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS
  ),

  [_LAYER2] = LAYOUT(
    KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    C(S(KC_TAB)), KC_TRNS,    KC_TRNS,   C(KC_TAB), KC_TRNS, QK_BOOT,
    KC_TRNS, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_TRNS,    KC_LEFT,      KC_DOWN,  KC_UP,   KC_RGHT,   KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_HOME,      KC_PGDN,  KC_PGUP, KC_END,    KC_TRNS, KC_TRNS,
                             KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS
  ),

  [_LAYER3] = LAYOUT(
    RM_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, RM_VALD, RM_VALU,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,      KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_TRNS, KC_TRNS,
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
                           KC_TRNS, KC_TRNS,   KC_MSTP,    KC_MPLY,  KC_MUTE,  KC_TRNS
  ),

  [_LAYER4] = LAYOUT(
    KC_NUM, KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS,    KC_TRNS, KC_F9,  KC_F8,  KC_F7,   KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS,    KC_TRNS, KC_F6,  KC_F5,  KC_F4,   KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_0,  KC_1, KC_2, KC_3, KC_TRNS,    KC_TRNS, KC_F3,  KC_F2,  KC_F1,   KC_F10, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
  )

};
