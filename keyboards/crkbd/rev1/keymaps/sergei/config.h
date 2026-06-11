#pragma once

//#define USE_MATRIX_I2C

// Home row mod tuning
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD    // pick the hold action when another key is tapped inside the tapping term
// QUICK_TAP_TERM left at default: tap a home-row mod then hold it again to
// auto-repeat the tap (e.g. hold j/k/l to scroll in vim).

// This board runs RGB Matrix (per-LED), not RGBLIGHT. Animations are off unless
// explicitly enabled here. SOLID_COLOR (used by the color presets) is always
// available; CYCLE_LEFT_RIGHT is the flowing multicolor "sea waves" effect.
#ifdef RGB_MATRIX_ENABLE
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#endif
