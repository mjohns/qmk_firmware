#include QMK_KEYBOARD_H
#include "version.h"

#define _BASE 0
#define _LOWER 1



#define LAYOUT_dactyl( \
    L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35, \
              L42, L43,                                              R42, R43, \
                        L44, L45,                          R40, R41, \
                                  L54, L55,      R50, R51, \
                                  L52, L53,      R52, R53 \
) { \
    { L05, L15, L25, L35, XXX, L55 }, \
    { L04, L14, L24, L34, XXX, L54 }, \
    { L03, L13, L23, L33, L43, L44 }, \
    { L02, L12, L22, L32, L42, L45 }, \
    { L01, L11, L21, L31, XXX, L52 }, \
    { L00, L10, L20, L30, XXX, L53 }, \
\
    { R50, XXX, R30, R20, R10, R00 }, \
    { R51, XXX, R31, R21, R11, R01 }, \
    { R41, R42, R32, R22, R12, R02 }, \
    { R40, R43, R33, R23, R13, R03 }, \
    { R53, XXX, R34, R24, R14, R04 }, \
    { R52, XXX, R35, R25, R15, R05 }, \
}

#define LAYOUT_dactyl_stacked( \
    L00, L01, L02, L03, L04, L05,               \
    L10, L11, L12, L13, L14, L15,               \
    L20, L21, L22, L23, L24, L25,               \
    L30, L31, L32, L33, L34, L35,               \
              L42, L43,                         \
                        L44, L45,               \
                                  L54, L55,     \
                                  L52, L53,     \
              R00, R01, R02, R03, R04, R05, \
              R10, R11, R12, R13, R14, R15, \
              R20, R21, R22, R23, R24, R25, \
              R30, R31, R32, R33, R34, R35, \
                        R42, R43, \
              R40, R41, \
    R50, R51, \
    R52, R53 \
)  \
 LAYOUT_dactyl( \
    L00, L01, L02, L03, L04, L05,                          R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,                          R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                          R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,                          R30, R31, R32, R33, R34, R35, \
              L42, L43,                                              R42, R43, \
                        L44, L45,                          R40, R41, \
                                  L54, L55,      R50, R51, \
                                  L52, L53,      R52, R53)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_dactyl_stacked(
        KC_ESC     ,  KC_1     ,    KC_2     ,    KC_3      ,   KC_4   ,     KC_5     ,
        KC_F1      ,   KC_TAB     ,  KC_Q     ,    KC_W     ,    KC_E      ,   KC_R   ,
        KC_F2     ,    KC_LSFT      ,  KC_A     ,    KC_S     ,    KC_D      ,   KC_F   ,
        KC_F3     ,    KC_F4    ,  KC_Z     ,    KC_X     ,    KC_C      ,   KC_V   ,
                                    KC_F5    ,    KC_F6     ,
                                KC_LALT ,   KC_SPC       ,
                                 KC_F8     ,   KC_LCTL ,
                               MO(_LOWER)    ,   KC_F9        ,

        KC_6       ,  KC_7     ,    KC_8     ,    KC_9      ,   KC_0   ,     RESET  ,
        KC_Y       ,  KC_U     ,    KC_I     ,    KC_O      ,   KC_P   ,     RESET  ,
        KC_H       ,  KC_J     ,    KC_K     ,    KC_L      ,  KC_SCLN ,     KC_QUOT  ,
        KC_N       ,  KC_M     ,    KC_COMM  ,    KC_DOT    ,  KC_SLSH ,     KC_DEL   ,
                                    KC_6     ,    KC_X      ,
                 KC_ENT       ,   KC_SPC       ,
                  KC_LCTL     ,   KC_LALT      ,
                MO(_LOWER)    ,  MO(_LOWER)
        ),

    [_LOWER] = LAYOUT_dactyl_stacked(
        KC_BSPC    ,  KC_6     ,  KC_7     ,    KC_8     ,    KC_9      ,   KC_0   ,
        KC_BSLS    ,  KC_Y     ,  KC_U     ,    KC_I     ,    KC_O      ,   KC_P   ,
        KC_QUOT    ,  KC_H     ,  KC_J     ,    KC_K     ,    KC_L      ,  KC_SCLN ,
        KC_DEL     ,  KC_N     ,  KC_M     ,    KC_COMM  ,    KC_DOT    ,  KC_SLSH ,
                                    KC_F11  ,    KC_F12   ,
                                _______      ,   _______      ,
                                 _______     ,        _______ ,
                               _______       ,   _______      ,

        _______    ,  _______  ,    _______  ,    _______   ,  _______ ,     RESET    ,
        _______    ,  _______  ,    _______  ,    _______   ,  _______ ,     _______  ,
        _______    ,  _______  ,    _______  ,    _______   ,  _______ ,     _______  ,
        _______    ,  _______  ,    _______  ,    _______   ,  _______ ,     _______  ,
                                    _______  ,    _______    ,
                 _______      ,   _______      ,
                 _______      ,   _______      ,
                 _______      ,   _______
    ),
};



