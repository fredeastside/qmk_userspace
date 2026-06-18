# Controllers use a DFU bootloader (Elite-C / DFU Pro Micro), not promicro/caterina
BOOTLOADER = atmel-dfu

VIA_ENABLE = no
CAPS_WORD_ENABLE = yes
TAP_DANCE_ENABLE = yes
REPEAT_KEY_ENABLE = yes   # tracks last keycode/mods for the LT4_REP thumb tap
LTO_ENABLE = yes
