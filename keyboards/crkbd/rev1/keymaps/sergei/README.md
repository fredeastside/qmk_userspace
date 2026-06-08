# Corne (crkbd rev1) - sergei keymap

A 5-layer keymap for the Corne / crkbd rev1 (`LAYOUT_split_3x6_3`, 42 keys),
ported from a ZSA Voyager Oryx layout. The full layout lives in `keymap.c`
(VIA is disabled), so the firmware is the single source of truth.

## Hardware

- Keyboard: crkbd rev1, Pro Micro footprint (atmega32u4).
- Bootloader: `atmel-dfu` (set in `rules.mk`). Controllers are DFU, flashed via `dfu`.
- Split handedness: QMK default (`MASTER_LEFT`). Keep the **left** half plugged
  into the computer. No `EE_HANDS`.

## Features

- Home row mods on both hands (GUI / Alt / Shift / Ctrl).
- Caps Word toggle (`CW_TOGG`) on the base layer's top-left key.
- Tap/hold screenshot key on layer 4: tap `4`, hold for `Cmd+Shift+4` (macOS area
  screenshot). Implemented with tap dance so the hold fires at `TAPPING_TERM`.
- `=>` and `->` macros on layer 1 (`SEND_STRING`, no VIA macros needed).
- RGB underglow controls and three solid-color presets (red / green / blue) on layer 3.
- `QK_BOOT` on layer 2 to enter the bootloader from the keyboard itself.

## Layers

- **0 - Base:** QWERTY letters, home row mods, Caps Word. Thumbs: Tab,
  `LT(1, Space)` / `LT(2, Enter)`, Backspace. Bottom-right is `Ctrl+Cmd+Q` (lock screen).
- **1 - Symbols** (hold left thumb / `Space`): brackets, operators, shifted digits,
  and the `=>` / `->` macros.
- **2 - Navigation** (hold right thumb / `Enter`): arrows, Home/End/PgUp/PgDn,
  tab switching, left-hand modifiers, and `QK_BOOT` (top-right).
- **3 - Media + RGB** (`LT(3, Esc)`): media transport and volume on the right;
  underglow toggle / mode / hue / sat / value / speed and color presets on the left.
- **4 - Numbers + Function** (`LT(4, ')`): numpad cluster, F1-F10, Num Lock, and the
  tap/hold screenshot key.

## Build

Compile only (produces `.build/crkbd_rev1_sergei.hex`):

```
qmk compile -kb crkbd/rev1 -km sergei
```

## Flash

Split board: flash each half separately with the same firmware.

```
qmk flash -kb crkbd/rev1 -km sergei
```

1. Plug in the **left** half, run the command, then enter the bootloader
   (press `QK_BOOT` on layer 2, or double-tap the physical reset, or short
   RST-GND twice). It flashes automatically.
2. Plug in the **right** half, run the **same** command again, enter its bootloader.
3. Reconnect the TRRS cable (with USB unplugged) and plug the **left** half into the
   computer.

No extra flags are required: the feature toggles live in `rules.mk`, the bootloader
is set there too, and DFU is auto-detected. Add `-bl dfu` only if auto-detection fails.

## Files

- `keymap.c` - layers, tap dance, and custom keycodes (`process_record_user`).
- `config.h` - RGBLIGHT effects and limits.
- `rules.mk` - feature toggles (`CAPS_WORD`, `TAP_DANCE`, `LTO`) and `BOOTLOADER`.
