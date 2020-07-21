#include QMK_KEYBOARD_H
#include "version.h"

#define L_BASE 0
#define L_SYMBOLS 1
#define L_NUMBERS 2
#define L_FUNCTION 3
#define L_SHIFT 4
#define L_THUMB_L 5
#define L_THUMB_R 6

enum custom_keycodes {
  MY_ALT_TAB = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_BASE] = LAYOUT_tracer(
    KC_Q,         KC_W,    KC_E,    KC_R,                KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,         KC_S,    KC_D,    LT(L_NUMBERS, KC_F), KC_G,                    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    LSFT_T(KC_Z), KC_X,    KC_C,    KC_V,                KC_B,                    KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),
                  KC_LALT,    MO(L_SYMBOLS),                                                      MO(L_SYMBOLS),    KC_LALT,
                                        KC_ESC,                                   KC_TAB,
                      MO(L_THUMB_L),    MO(L_SHIFT),    KC_RCTL,                KC_RCTL, LT(L_THUMB_R, KC_ENTER),   KC_SPACE,
                                        KC_LGUI,                                KC_LGUI
    ),

[L_SYMBOLS] = LAYOUT_tracer(
    _______, KC_LCBR, KC_UNDS, KC_RCBR, KC_PERC,                 KC_AT,   KC_EXLM,  KC_EQUAL, KC_KP_PLUS, _______,
    KC_DQUO, KC_LPRN, KC_ASTR, KC_RPRN, KC_AMPR,                 KC_PIPE, KC_LABK, KC_MINUS, KC_RABK,     KC_QUOTE,
    _______, KC_LBRC, KC_DLR,  KC_RBRC, KC_HASH,                 KC_CIRC, KC_TILD, KC_GRAVE, _______,     KC_BSLASH,
             _______, _______,                                                     _______, _______,
                                        _______,                 _______,
                      _______, _______, _______,                 _______, _______, _______,
                                        _______,                 _______
    ),

[L_NUMBERS] = LAYOUT_tracer(
    RESET,     _______,   _______,   _______,   KC_AUDIO_VOL_UP,   KC_COMMA,  KC_7,      KC_8,      KC_9,   _______,
    _______,   _______,   _______,   _______,   KC_AUDIO_VOL_DOWN, KC_DOT,    KC_4,      KC_5,      KC_6,   _______,
    RESET,     _______,   _______,   _______,   _______,           KC_0,      KC_1,      KC_2,      KC_3,   _______,
               _______,   _______,                                                       _______,   _______,
                                                _______,           _______,
                          _______,   _______,   _______,           _______,   _______,   _______,
                                                _______,           _______
    ),

[L_FUNCTION] = LAYOUT_tracer(
    _______,   _______,   _______,   _______,   _______,           KC_F12,   KC_F7,   KC_F8,   KC_F9,   _______,
    _______,   _______,   _______,   _______,   _______,           KC_F11,   KC_F4,   KC_F5,   KC_F6,   _______,
    _______,   _______,   _______,   _______,   _______,           KC_F10,   KC_F1,   KC_F2,   KC_F3,   _______,
               _______,   _______,                                                       _______,   _______,
                                                _______,           _______,
                          _______,   _______,   _______,           _______,   _______,   _______,
                                               _______,            _______
    ),

[L_SHIFT] = LAYOUT_tracer(
    LSFT(KC_Q),  LSFT(KC_W),    LSFT(KC_E),    LSFT(KC_R),   LSFT(KC_T),                    LSFT(KC_Y),    LSFT(KC_U),    LSFT(KC_I),    LSFT(KC_O),    LSFT(KC_P),
    LSFT(KC_A),  LSFT(KC_S),    LSFT(KC_D),    LSFT(KC_F),   LSFT(KC_G),                    LSFT(KC_H),    LSFT(KC_J),    LSFT(KC_K),    LSFT(KC_L),    LSFT(KC_SCLN),
    LSFT(KC_Z),  LSFT(KC_X),    LSFT(KC_C),    LSFT(KC_V),   LSFT(KC_B),                    LSFT(KC_N),    LSFT(KC_M),    LSFT(KC_COMM), LSFT(KC_DOT),  LSFT(KC_SLSH),
               _______,   _______,                                                       _______,   _______,
                                                _______,           KC_DELETE,
                          _______,   _______,   _______,           KC_UNDS,   KC_BSPACE,   _______,
                                               _______,            _______
    ),

[L_THUMB_L] = LAYOUT_tracer(
    _______,   LCTL(KC_UP), KC_END,   _______,   _______,           LALT(LCTL(LGUI(KC_Y))),     KC_PGUP,    _______,   _______,   _______,
    _______,   _______,   KC_PGDOWN,   _______,   _______,           KC_LEFT,                  KC_DOWN,    KC_UP,   KC_RIGHT,   _______,
    _______,   _______,   LGUI(KC_C),  LGUI(KC_V),   KC_HOME,           LGUI(KC_V),   LALT(LCTL(LGUI(KC_M))),   _______,   _______,   _______,
               _______,   _______,                                                       _______,   _______,
                                                _______,           KC_DELETE,
                          _______,   _______,   _______,           MY_ALT_TAB,  KC_TAB,   KC_ESC,
                                               _______,            _______
    ),

[L_THUMB_R] = LAYOUT_tracer(
    RESET,   _______,   _______,   _______,       _______,           _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   MO(L_FUNCTION),_______,           _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,               _______,   _______,   _______,   _______,   _______,
               _______,   _______,                                                       _______,   _______,
                                                _______,           _______,
                          _______,   KC_DELETE, _______,           _______,   _______,   _______,
                                               _______,            _______
    ),
};

/*
[L_NUMBERS] = LAYOUT_tracer(
    _______,   _______,   _______,   _______,   _______,           _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,           _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,           _______,   _______,   _______,   _______,   _______,
               _______,   _______,                                                       _______,   _______,
                                                _______,           _______,
                          _______,   _______,   _______,           _______,   _______,   _______,
                                               _______,            _______
    ),
*/


/*

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    LALT(LSFT(KC_LCTRL)),KC_1,           KC_LALT,        KC_LCTRL,       KC_LGUI,        KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_LGUI,        KC_RCTRL,       KC_LALT,        KC_0,           LALT(LSFT(KC_LCTRL)),
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           LT(2,KC_F),     KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_LSHIFT,      LSFT_T(KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RSFT_T(KC_SLASH),KC_RSHIFT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LALT,        MO(1),          KC_LCTRL,                                                                                                       KC_LCTRL,       MO(1),          KC_LALT,        KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_LCTRL,       KC_LGUI,        KC_LGUI,        KC_LCTRL,
                                                                                                                    KC_ESCAPE,      KC_TAB,
                                                                                    MO(3),          OSL(4),         KC_LGUI,        KC_TAB,         LT(6,KC_ENTER), KC_SPACE
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LCBR,        KC_UNDS,        KC_RCBR,        KC_PERC,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AT,          KC_EXLM,        KC_EQUAL,       KC_KP_PLUS,     KC_TRANSPARENT, KC_F12,
    TO(0),          KC_DQUO,        KC_LPRN,        KC_ASTR,        KC_RPRN,        KC_AMPR,                                                                        KC_PIPE,        KC_LABK,        KC_MINUS,       KC_RABK,        KC_QUOTE,       KC_TRANSPARENT,
    KC_LSHIFT,      KC_TRANSPARENT, KC_LBRACKET,    KC_DLR,         KC_RBRACKET,    KC_HASH,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_TILD,        KC_GRAVE,       KC_TRANSPARENT, KC_BSLASH,      KC_LSHIFT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_BSPACE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_COMMA,       KC_7,           KC_8,           KC_9,           KC_9,           KC_TRANSPARENT,
    TO(0),          KC_TRANSPARENT, KC_MS_LEFT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,                                                                KC_DOT,         KC_4,           KC_5,           KC_6,           KC_4,           KC_TRANSPARENT,
    KC_LSHIFT,      RESET,          KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          TO(0),          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0,           KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_LSHIFT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,                                                                                                     KC_0,           KC_0,           KC_KP_DOT,      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPACE,      KC_DELETE
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_ENTER,       LCTL(KC_UP),    KC_END,         LGUI(KC_R),     LGUI(KC_T),     KC_TRANSPARENT,                                 KC_TRANSPARENT, LALT(LCTL(LGUI(KC_Y))),KC_PGUP,        LGUI(KC_TAB),   KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,
    TO(0),          LGUI(KC_A),     LGUI(KC_S),     KC_PGDOWN,      KC_DQUO,        LCTL(KC_UP),                                                                    KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LGUI(KC_Z),     LGUI(KC_X),     LGUI(KC_C),     LGUI(KC_V),     KC_HOME,        KC_TRANSPARENT,                                 KC_TRANSPARENT, LGUI(KC_V),     LALT(LCTL(LGUI(KC_M))),KC_DQUO,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,      LSFT(KC_F20),
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TAB,         KC_ESCAPE
  ),
  [4] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, LSFT(KC_1),     LSFT(KC_2),     LSFT(KC_3),     LSFT(KC_4),     LSFT(KC_5),     KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_6),     LSFT(KC_7),     LSFT(KC_8),     LSFT(KC_9),     LSFT(KC_0),     KC_TRANSPARENT,
    KC_TRANSPARENT, LSFT(KC_Q),     LSFT(KC_W),     LSFT(KC_E),     LSFT(KC_R),     LSFT(KC_T),     KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_Y),     LSFT(KC_U),     LSFT(KC_I),     LSFT(KC_O),     LSFT(KC_P),     LSFT(KC_BSLASH),
    TO(0),          LSFT(KC_A),     LSFT(KC_S),     LSFT(KC_D),     LSFT(KC_F),     LSFT(KC_G),                                                                     LSFT(KC_H),     LSFT(KC_J),     LSFT(KC_K),     LSFT(KC_L),     LSFT(KC_SCOLON),LSFT(KC_QUOTE),
    KC_TRANSPARENT, LSFT(KC_Z),     LSFT(KC_X),     LSFT(KC_C),     LSFT(KC_V),     LSFT(KC_B),     KC_TRANSPARENT,                                 KC_TRANSPARENT, LSFT(KC_N),     LSFT(KC_M),     LSFT(KC_COMMA), LSFT(KC_DOT),   LSFT(KC_SLASH), KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,      KC_UNDS,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          KC_TRANSPARENT, KC_BSPACE,      KC_TRANSPARENT
  ),
  [5] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_DOWN,        KC_PGDOWN,      KC_PGUP,        KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1
  ),
  [6] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_UP),    LCTL(KC_UP),    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_UP),    MO(7),          KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_V),     LGUI(KC_C),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F12,         KC_F7,          KC_F8,          KC_F9,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_F11,         KC_F4,          KC_F5,          KC_F6,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F10,         KC_F1,          KC_F2,          KC_F3,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
*/

bool alt_tabbing = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case MY_ALT_TAB:
      if (record->event.pressed) {
        if (!alt_tabbing) {
          alt_tabbing = true;
          SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_TAB));
        } else {
          SEND_STRING(SS_TAP(X_TAB));
        }
      }
      break;
    case MO(L_THUMB_L):
      if (!record->event.pressed && alt_tabbing) {
        SEND_STRING(SS_TAP(X_LGUI));
        alt_tabbing = false;
      }
      break;
  }
  return true;
}


