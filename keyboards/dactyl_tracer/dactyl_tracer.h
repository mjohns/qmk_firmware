#pragma once

#include "quantum.h"
#include <stdint.h>
#include <stdbool.h>
#include "i2c_master.h"
#include <util/delay.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00

// I2C aliases and register addresses (see "mcp23018.md")
#define I2C_ADDR        0b0100000
#define I2C_ADDR_WRITE  ( (I2C_ADDR<<1) | I2C_WRITE )
#define I2C_ADDR_READ   ( (I2C_ADDR<<1) | I2C_READ  )
#define IODIRA          0x00            // i/o direction register
#define IODIRB          0x01
#define GPPUA           0x0C            // GPIO pull-up resistor register
#define GPPUB           0x0D
#define GPIOA           0x12            // general purpose i/o port register (write modifies OLAT)
#define GPIOB           0x13
#define OLATA           0x14            // output latch register
#define OLATB           0x15

extern i2c_status_t mcp23018_status;
#define ERGODOX_EZ_I2C_TIMEOUT 100

void init_ergodox(void);
uint8_t init_mcp23018(void);


#define LAYOUT_ergodox_pretty(                                           \
    L00,L01,L02,L03,L04,L05,L06,           R00,R01,R02,R03,R04,R05,R06,  \
    L10,L11,L12,L13,L14,L15,L16,           R10,R11,R12,R13,R14,R15,R16,  \
    L20,L21,L22,L23,L24,L25,                   R21,R22,R23,R24,R25,R26,  \
    L30,L31,L32,L33,L34,L35,L36,           R30,R31,R32,R33,R34,R35,R36,  \
    L40,L41,L42,L43,L44,                           R42,R43,R44,R45,R46,  \
                            L55,L56,   R50,R51,                          \
                                L54,   R52,                              \
                        L53,L52,L51,   R55,R54,R53 )                     \
                                          \
   /* matrix positions */                 \
    {                                     \
    { L00, L10, L20, L30, L40, KC_NO },   \
    { L01, L11, L21, L31, L41, L51 },     \
    { L02, L12, L22, L32, L42, L52 },     \
    { L03, L13, L23, L33, L43, L53 },     \
    { L04, L14, L24, L34, L44, L54 },     \
    { L05, L15, L25, L35, KC_NO, L55 },   \
    { L06, L16, KC_NO, L36, KC_NO, L56 }, \
                                          \
    { R00, R10, KC_NO, R30,KC_NO, R50 },  \
    { R01, R11, R21, R31,KC_NO, R51 },    \
    { R02, R12, R22, R32, R42, R52 },     \
    { R03, R13, R23, R33, R43, R53 },     \
    { R04, R14, R24, R34, R44, R54 },     \
    { R05, R15, R25, R35, R45, R55 },     \
    { R06, R16, R26, R36, R46, KC_NO }    \
    }

// Wiring with similar layout to ergodox ez. Cherry brown switches.
#define LAYOUT_tracer_std(                                            \
    L11,L12,L13,L14,L15,         R11,R12,R13,R14,R15,  \
    L21,L22,L23,L24,L25,         R21,R22,R23,R24,R25,  \
    L31,L32,L33,L34,L35,         R31,R32,R33,R34,R35,  \
        L62,L63,                         R63,R64,      \
                    L51,         R51,                  \
            L40,L41,L42,         R42,R41,R40,          \
                    L50,         R50                  )\
LAYOUT_ergodox_pretty( \
    KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,           KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,  \
    KC_NO,L11,L12,L13,L14,L15,KC_NO,                   KC_NO,R11,R12,R13,R14,R15,KC_NO,  \
    KC_NO,L21,L22,L23,L24,L25,                            R21,R22,R23,R24,R25,KC_NO,  \
    KC_NO,L31,L32,L33,L34,L35,KC_NO,                   KC_NO,R31,R32,R33,R34,R35,KC_NO,  \
    KC_NO,KC_NO,L62,L63,KC_NO,                           KC_NO,R63,R64,KC_NO,KC_NO,  \
                            L42,KC_NO,   KC_NO,R42,                          \
                                L51,   R51,                              \
                        L40,L41,L50,   R50,R41,R40 )                     


// The custom wiring from the board with kalih brown switches.
#define LAYOUT_tracer_custom(                                            \
    L00,L01,L02,L03,L04,         R00,R01,R02,R03,R04,  \
    L10,L11,L12,L13,L14,         R10,R11,R12,R13,R14,  \
    L20,L21,L22,L23,L24,         R20,R21,R22,R23,R24,  \
        L30,L31,                         R30,R31,      \
                    L32,         R32,                  \
            L40,L41,L42,         R40,R41,R42,          \
                    L50,         R50                  )\
                                          \
   /* matrix positions */                 \
    {                                     \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
    { KC_NO, L04,   L03,   L02,   L01,   L00 },   \
    { KC_NO, L14,   L13,   L12,   L11,   L10 },   \
    { KC_NO, L24,   L23,   L22,   L21,   L20 },   \
    { KC_NO, L41,   L40,   L31,   L30,   KC_NO },   \
    { KC_NO, L32,   L50,   L42,   KC_NO, KC_NO },   \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
                                          \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },  \
    { KC_NO, R00,   R01,   R02,   R03,   R04 },   \
    { KC_NO, R10,   R11,   R12,   R13,   R14 },   \
    { KC_NO, R20,   R21,   R22,   R23,   R24 },   \
    { KC_NO, R41,   R42,   R30,   R31,   KC_NO },   \
    { KC_NO, R32,   R50,   R40,   KC_NO, KC_NO },   \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO },   \
    }

#define LAYOUT_tracer_custom_stacked(                  \
    L00,L01,L02,L03,L04,       \
    L10,L11,L12,L13,L14,      \
    L20,L21,L22,L23,L24,      \
        L30,L31,              \
                    L32,      \
            L40,L41,L42,      \
                    L50,      \
     R00,R01,R02,R03,R04,  \
     R10,R11,R12,R13,R14,  \
     R20,R21,R22,R23,R24,  \
             R30,R31,      \
     R32,                  \
     R40,R41,R42,          \
     R50                  )\
 LAYOUT_tracer_custom(                                            \
    L00,L01,L02,L03,L04,         R00,R01,R02,R03,R04,  \
    L10,L11,L12,L13,L14,         R10,R11,R12,R13,R14,  \
    L20,L21,L22,L23,L24,         R20,R21,R22,R23,R24,  \
        L30,L31,                         R30,R31,      \
                    L32,         R32,                  \
            L40,L41,L42,         R40,R41,R42,          \
                    L50,         R50                  )

#define LAYOUT_tracer_std_stacked(                  \
    L00,L01,L02,L03,L04,       \
    L10,L11,L12,L13,L14,      \
    L20,L21,L22,L23,L24,      \
        L30,L31,              \
                    L32,      \
            L40,L41,L42,      \
                    L50,      \
     R00,R01,R02,R03,R04,  \
     R10,R11,R12,R13,R14,  \
     R20,R21,R22,R23,R24,  \
             R30,R31,      \
     R32,                  \
     R40,R41,R42,          \
     R50                  )\
 LAYOUT_tracer_std(                                            \
    L00,L01,L02,L03,L04,         R00,R01,R02,R03,R04,  \
    L10,L11,L12,L13,L14,         R10,R11,R12,R13,R14,  \
    L20,L21,L22,L23,L24,         R20,R21,R22,R23,R24,  \
        L30,L31,                         R30,R31,      \
                    L32,         R32,                  \
            L40,L41,L42,         R40,R41,R42,          \
                    L50,         R50                  )
