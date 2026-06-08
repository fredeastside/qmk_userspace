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
- RGB layer indicators: underglow color tracks the active layer (symbols=cyan,
  nav=blue, media=purple, numbers=green; base keeps its normal color).
- Tuned home row mods (`TAPPING_TERM 200`, `PERMISSIVE_HOLD`, `QUICK_TAP_TERM 0`,
  plus per-key `HOLD_ON_OTHER_KEY_PRESS` on the layer-tap keys only).
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

## Layout diagrams

Legend:

- Blank cells are transparent (fall through to the layer below).
- Home row holds (layer 0) are mods: left `A S D F` = Gui / Alt / Shift / Ctrl,
  right `J K L ;` = Ctrl / Shift / Alt / Gui.
- `Esc3` / `'4` = tap the key, hold for layer 3 / layer 4.
- `Spc1` / `Ent2` = tap Space / Enter, hold for layer 1 / layer 2.
- `CAPS` = Caps Word, `Lock` = Cmd+Ctrl+Q, `BOOT` = `QK_BOOT`.
- `4*` = tap `4`, hold for Cmd+Shift+4 (screenshot).
- `<Tab` / `Tab>` = Ctrl+Shift+Tab / Ctrl+Tab (prev / next tab).
- Layer 3 RGB: `RGB` toggle, `Mode`/`Mode-` next/prev animation,
  `Hue/Sat/Val/Spd +/-` adjust, `Red/Grn/Blu` solid-color presets.

```
Layer 0 - Base

,------+------+------+------+------+------.    ,------+------+------+------+------+------.
| CAPS |  Q   |  W   |  E   |  R   |  T   |    |  Y   |  U   |  I   |  O   |  P   |  \   |
|------+------+------+------+------+------|    |------+------+------+------+------+------|
| Esc3 |  A   |  S   |  D   |  F   |  G   |    |  H   |  J   |  K   |  L   |  ;   |  '4  |
|------+------+------+------+------+------|    |------+------+------+------+------+------|
|      |  Z   |  X   |  C   |  V   |  B   |    |  N   |  M   |  ,   |  .   |  /   | Lock |
`------+------+------+------+------+------'    `------+------+------+------+------+------'
                     ,------+------+------.    ,------+------+------.
                     |      | Tab  | Spc1 |    | Ent2 | Bsp  |      |
                     `------+------+------'    `------+------+------'

Layer 1 - Symbols

,------+------+------+------+------+------.    ,------+------+------+------+------+------.
|      |      |  &   |  *   |      |  -   |    |  _   |  {   |  }   |  =   |  =>  |      |
|------+------+------+------+------+------|    |------+------+------+------+------+------|
|      |      |  $   |  %   |  ^   |  +   |    |  -   |  [   |  ]   |  +   |  ->  |  `   |
|------+------+------+------+------+------|    |------+------+------+------+------+------|
|      |      |  !   |  @   |  #   |      |    |  <   |  (   |  )   |  >   |  ~   |      |
`------+------+------+------+------+------'    `------+------+------+------+------+------'
                     ,------+------+------.    ,------+------+------.
                     |      |      |      |    |      |      |      |
                     `------+------+------'    `------+------+------'

Layer 2 - Navigation

,------+------+------+------+------+------.    ,------+------+------+------+------+------.
|      |      |      |      |      |      |    | <Tab |      |      | Tab> |      | BOOT |
|------+------+------+------+------+------|    |------+------+------+------+------+------|
|      | Gui  | Alt  | Sft  | Ctl  |      |    | Left | Down |  Up  | Rght |      |      |
|------+------+------+------+------+------|    |------+------+------+------+------+------|
|      |      |      |      |      |      |    | Home | PgDn | PgUp | End  |      |      |
`------+------+------+------+------+------'    `------+------+------+------+------+------'
                     ,------+------+------.    ,------+------+------.
                     |      |      |      |    |      |      |      |
                     `------+------+------'    `------+------+------'

Layer 3 - Media + RGB

,------+------+------+------+------+------.    ,------+------+------+------+------+------.
| RGB  | Mode | Hue+ | Sat+ | Val- | Val+ |    |      |      |      |      |      |      |
|------+------+------+------+------+------|    |------+------+------+------+------+------|
|Mode- | Hue- | Sat- | Spd+ | Spd- |      |    | Prev | Vol- | Vol+ | Next |      |      |
|------+------+------+------+------+------|    |------+------+------+------+------+------|
|      | Red  | Grn  | Blu  |      |      |    |      |      |      |      |      |      |
`------+------+------+------+------+------'    `------+------+------+------+------+------'
                     ,------+------+------.    ,------+------+------.
                     |      |      | Stop |    | Play | Mute |      |
                     `------+------+------'    `------+------+------'

Layer 4 - Numbers + Function

,------+------+------+------+------+------.    ,------+------+------+------+------+------.
| Num  |      |  7   |  8   |  9   |      |    |      |  F9  |  F8  |  F7  |      |      |
|------+------+------+------+------+------|    |------+------+------+------+------+------|
|      |      |  4*  |  5   |  6   |      |    |      |  F6  |  F5  |  F4  |      |      |
|------+------+------+------+------+------|    |------+------+------+------+------+------|
|      |  0   |  1   |  2   |  3   |      |    |      |  F3  |  F2  |  F1  | F10  |      |
`------+------+------+------+------+------'    `------+------+------+------+------+------'
                     ,------+------+------.    ,------+------+------.
                     |      |      |      |    |      |      |      |
                     `------+------+------'    `------+------+------'
```

## Build

Compile only (produces `.build/crkbd_rev1_sergei.hex`):

```
qmk compile -kb crkbd/rev1 -km sergei
```

## Flash

Split board: flash each half separately with the same firmware, using the same
command for both:

```
qmk flash -kb crkbd/rev1 -km sergei
```

To flash a half it must be (1) plugged into USB and (2) in its bootloader. Enter
the bootloader by any of: pressing `QK_BOOT` (layer 2, top-right), the physical
reset button, or briefly bridging the controller's `RST` and `GND` pads twice.

No extra flags are required: feature toggles and the bootloader live in `rules.mk`,
and DFU is auto-detected. Add `-bl dfu` only if auto-detection fails.

> **Cable safety:** never plug or unplug the **TRRS** cable while USB is connected.
> The jack momentarily shorts its contacts and can damage a controller. Set the
> TRRS once with USB unplugged, then only ever move the **USB** cable. The flow
> below never disconnects the TRRS.

### Recommended procedure (TRRS stays connected)

Leave the TRRS cable joining both halves the whole time; only the USB cable moves.

1. Plug USB into the **left** half. Reset it into the bootloader (`QK_BOOT` works
   here since left is the master), then run the command. Unplug USB.
2. Plug USB into the **right** half. Reset it into the bootloader, run the **same**
   command. Unplug USB.
3. Plug USB back into the **left** half for normal use.

### When the reset button is only on the right half

`QK_BOOT` only resets the half that is currently the **master**, and handedness is
master-left, so:

- **Right half:** plug USB into the **right** half, press its physical reset button,
  then run the flash command. (TRRS can stay connected; the left half is just
  powered and idle.)
- **Left half:** with the **TRRS** still connected, plug USB into the **left** half
  (so left = master), then press `QK_BOOT` on the **right** half (hold the right
  `Enter` thumb for layer 2, tap the top-right key). The right half's keypress
  travels over TRRS and resets the master = left half into the bootloader. Run the
  flash command.

If you prefer not to use the `QK_BOOT` route for the left half, bridge `RST`-`GND`
twice on the left controller instead (works on any controller, button or not).

## Files

- `keymap.c` - layers, tap dance, custom keycodes (`process_record_user`), RGB
  layer indicators, and the per-key `HOLD_ON_OTHER_KEY_PRESS` rule.
- `config.h` - home row mod timing, RGBLIGHT layers/effects and limits.
- `rules.mk` - feature toggles (`CAPS_WORD`, `TAP_DANCE`, `LTO`) and `BOOTLOADER`.
