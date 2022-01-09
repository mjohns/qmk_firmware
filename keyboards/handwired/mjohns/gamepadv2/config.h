#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x1308
#define DEVICE_VER      0x0001
#define MANUFACTURER    Michael Johns
#define PRODUCT         HalfBoard

#define DIODE_DIRECTION ROW2COL
#define MATRIX_ROWS 6
#define MATRIX_COLS 7

#define MATRIX_ROW_PINS { D6, F5, F4, F1, F0, B1 }
#define MATRIX_COL_PINS { B2, B3, B7, D0, D1, D2, D3  }

#define TAPPING_TOGGLE  1

#define TAPPING_TERM    200
#define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)


/* fix space cadet rollover issue */
#define DISABLE_SPACE_CADET_ROLLOVER

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    15

#define USB_MAX_POWER_CONSUMPTION 500
