#pragma once

//#define USE_MATRIX_I2C

// Home row mod tuning
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 0   // holding a mod-tap right after tapping holds the mod, not a key repeat
#define PERMISSIVE_HOLD    // pick the hold action when another key is tapped inside the tapping term

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LAYERS    // per-keymap-layer underglow color indicators
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
