#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4

// Tap: 4 / Hold: Command+Shift+4 (macOS area screenshot)
enum tap_dance_keycodes {
    DANCE_SHOT_4,
};

enum custom_keycodes {
    ST_FATARROW = SAFE_RANGE, // types =>
    ST_ARROW,                 // types ->
    PRESET_RED,               // solid underglow: red
    PRESET_GRN,               // solid underglow: green
    PRESET_BLU,               // solid underglow: blue
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_LAYER0] = LAYOUT(
    CW_TOGG,      KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,            KC_Y,    KC_U,                          KC_I,                          KC_O,                          KC_P,                          KC_BSLS,
    LT(3,KC_ESC), MT(MOD_LGUI,KC_A), MT(MOD_LALT,KC_S), MT(MOD_LSFT,KC_D), MT(MOD_LCTL,KC_F), KC_G,            KC_H,    MT(MOD_LCTL|MOD_RCTL,KC_J),    MT(MOD_LSFT|MOD_RSFT,KC_K),    MT(MOD_LALT|MOD_RALT,KC_L),    MT(MOD_LGUI|MOD_RGUI,KC_SCLN), LT(4,KC_QUOT),
    KC_TRNS,        KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,            KC_N,    KC_M,                          KC_COMM,                       KC_DOT,                        KC_SLSH,                       C(G(KC_Q)),
                                                        KC_TRNS,             KC_TAB,            LT(1,KC_SPC),    LT(2,KC_ENT), KC_BSPC,                  KC_TRNS
  ),

  [_LAYER1] = LAYOUT(
    KC_TRNS, KC_TRNS, S(KC_7), S(KC_8), KC_TRNS,   KC_PMNS,    S(KC_MINS),  S(KC_LBRC), S(KC_RBRC), KC_EQL,    ST_FATARROW, KC_TRNS,
    KC_TRNS, KC_TRNS, S(KC_4), S(KC_5), S(KC_6), KC_PPLS,    KC_MINS,     KC_LBRC,    KC_RBRC,    S(KC_EQL), ST_ARROW,    KC_GRV,
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
    UG_TOGG,    UG_NEXT,    UG_HUEU, UG_SATU, UG_VALD, UG_VALU,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
    UG_PREV,    UG_HUED,    UG_SATD, UG_SPDU, UG_SPDD, KC_TRNS,    KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_TRNS, KC_TRNS,
    KC_TRNS,    PRESET_RED, PRESET_GRN, PRESET_BLU, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
                           KC_TRNS, KC_TRNS,   KC_MSTP,    KC_MPLY,  KC_MUTE,  KC_TRNS
  ),

  [_LAYER4] = LAYOUT(
    KC_NUM, KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS,    KC_TRNS, KC_F9,  KC_F8,  KC_F7,   KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS, TD(DANCE_SHOT_4), KC_5, KC_6, KC_TRNS,    KC_TRNS, KC_F6,  KC_F5,  KC_F4,   KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_0,  KC_1, KC_2, KC_3, KC_TRNS,    KC_TRNS, KC_F3,  KC_F2,  KC_F1,   KC_F10, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
  )

};

// Oryx-style dual-function: hold action fires at TAPPING_TERM and is held
// down until release; tap action fires on a quick press.
typedef enum { TD_NONE, TD_SINGLE_TAP, TD_SINGLE_HOLD } td_state_t;

static td_state_t dance_shot_4_state;

static td_state_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        return (state->interrupted || !state->pressed) ? TD_SINGLE_TAP : TD_SINGLE_HOLD;
    }
    return TD_NONE;
}

void dance_shot_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_shot_4_state = dance_step(state);
    switch (dance_shot_4_state) {
        case TD_SINGLE_TAP:  register_code16(KC_4); break;
        case TD_SINGLE_HOLD: register_code16(LGUI(LSFT(KC_4))); break;
        default: break;
    }
}

void dance_shot_4_reset(tap_dance_state_t *state, void *user_data) {
    switch (dance_shot_4_state) {
        case TD_SINGLE_TAP:  unregister_code16(KC_4); break;
        case TD_SINGLE_HOLD: unregister_code16(LGUI(LSFT(KC_4))); break;
        default: break;
    }
    dance_shot_4_state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [DANCE_SHOT_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_shot_4_finished, dance_shot_4_reset),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ST_FATARROW: // =>
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            return false;
        case ST_ARROW: // ->
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        case PRESET_RED:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(0, 255, 255);
            }
            return false;
        case PRESET_GRN:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(74, 255, 255);
            }
            return false;
        case PRESET_BLU:
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(169, 255, 255);
            }
            return false;
    }
    return true;
}
