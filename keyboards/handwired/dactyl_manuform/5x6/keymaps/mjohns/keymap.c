#include QMK_KEYBOARD_H
#include "version.h"

#define L_BASE 0
#define L_SYMBOLS 1
#define L_NUMBERS 2
#define L_FUNCTION 3
#define L_SHIFT 4
#define L_THUMB_L 5
#define L_THUMB_R 6
#define L_SHIFT_FUNCTION 7


#define LAYOUT_tracer_std(                                            \
    LQ,LW,LE,LR,LT,         RY,RU,RI,RO,RP,  \
    LA,LS,LD,LF,LG,         RH,RJ,RK,RL,RCOLON,  \
    LZ,LX,LC,LV,LB,         RN,RM,RCOMMA,RPERIOD,RQUESTION,  \
        L62,L63,                         R63,R64,      \
                    L51,         R51,                  \
            L40,L41,L42,         R42,R41,R40,          \
                    L50,         R50                  )\
   /* matrix positions */                                               \
   {                                                                    \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, L51, L50, L42, KC_NO, KC_NO }, \
    { KC_NO, L41, L40, L63, L62, KC_NO }, \
    { KC_NO, LB, LV, LC, LX, LZ }, \
    { KC_NO, LG, LF, LD, LS, LA }, \
    { KC_NO, LT, LR, LE, LW, LQ }, \
\
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, R51, R50, R42, KC_NO, KC_NO }, \
    { KC_NO, R41, R40, R63, R64, KC_NO }, \
    { KC_NO, RN, RM, RCOMMA, RPERIOD, RQUESTION }, \
    { KC_NO, RH, RJ, RK, RL, RCOLON }, \
    { KC_NO, RY, RU, RI, RO, RP }, \
   }

// Kalih Brown switches
#define LAYOUT_tracer_nonstd(                                            \
    LQ,LW,LE,LR,LT,         RY,RU,RI,RO,RP,  \
    LA,LS,LD,LF,LG,         RH,RJ,RK,RL,RCOLON,  \
    LZ,LX,LC,LV,LB,         RN,RM,RCOMMA,RPERIOD,RQUESTION,  \
        L62,L63,                         R63,R64,      \
                    L51,         R51,                  \
            L40,L41,L42,         R42,R41,R40,          \
                    L50,         R50                  )\
   /* matrix positions */                                               \
   {                                                                    \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, L51, KC_NO, LV, LF, LR }, \
    { KC_NO, L42, KC_NO, LB, LG, LT }, \
    { KC_NO, L40, L63, LC, LD, LE }, \
    { KC_NO, L41, L62, LX, LS, LW }, \
    { KC_NO, L50, KC_NO, LZ, LA, LQ }, \
\
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, R42, RN, RH, RY }, \
    { KC_NO, KC_NO, R51, RM, RJ, RU }, \
    { KC_NO, R63, R40, RCOMMA, RK, RI }, \
    { KC_NO, R64, R41, RPERIOD, RL, RO }, \
    { KC_NO, KC_NO, R50, RQUESTION, RCOLON, RP }, \
   }

#define LAYOUT_tracer LAYOUT_tracer_nonstd

#define LAYOUT_tracer_stacked(                  \
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
 LAYOUT_tracer(                                            \
    L00,L01,L02,L03,L04,         R00,R01,R02,R03,R04,  \
    L10,L11,L12,L13,L14,         R10,R11,R12,R13,R14,  \
    L20,L21,L22,L23,L24,         R20,R21,R22,R23,R24,  \
        L30,L31,                         R30,R31,      \
                    L32,         R32,                  \
            L40,L41,L42,         R40,R41,R42,          \
                    L50,         R50                  )


enum custom_keycodes {
  MY_ALT_TAB = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

#define MY_IS_MAC
#ifdef MY_IS_MAC
  #define MY_KC_LCTL KC_LGUI
  #define MY_LCTL LGUI
  #define MY_WIN_PICKER LCTL(KC_UP)
  #define MY_SHIFT_INSERT LGUI(KC_V)
  #define MY_CTL_ALT_DELETE LALT(LGUI(KC_ESC))
#else
  #define MY_KC_LCTL KC_LCTL
  #define MY_LCTL LCTL
  #define MY_WIN_PICKER MY_ALT_TAB
  #define MY_SHIFT_INSERT LSFT(KC_INSERT)
  #define MY_CTL_ALT_DELETE LALT(LCTL(KC_DELETE))
#endif



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[L_BASE] = LAYOUT_tracer_stacked(
    KC_Q,             KC_W,           KC_E,           KC_R,                  KC_T,
    KC_A,             KC_S,           KC_D,           LT(L_NUMBERS, KC_F),   KC_G,
    LSFT_T(KC_Z),     KC_X,           KC_C,           KC_V,                  KC_B,

                                      KC_LALT,        MO(L_SYMBOLS),

                                                                             KC_LGUI,
                                      MO(L_THUMB_L),  MO(L_SHIFT),           KC_RCTL,
                                                                             MY_KC_LCTL,



    KC_Y,             KC_U,           KC_I,           KC_O,                   KC_P,
    KC_H,             KC_J,           KC_K,           KC_L,                   KC_SCLN,
    KC_N,             KC_M,           KC_COMM,        KC_DOT,                 RSFT_T(KC_SLSH),

                      MO(L_SYMBOLS),  KC_LALT,

    KC_TAB,
    KC_RCTL,          LT(L_THUMB_R,   KC_ENTER),      KC_SPACE,
    MY_KC_LCTL
),

[L_SYMBOLS] = LAYOUT_tracer(
    _______, KC_LCBR, KC_UNDS, KC_RCBR, KC_PERC,                 KC_AT,   KC_EXLM,  KC_EQUAL, KC_KP_PLUS, _______,
    KC_DQUO, KC_LPRN, KC_ASTR, KC_RPRN, KC_AMPR,                 KC_PIPE, KC_LABK, KC_MINUS, KC_RABK,     KC_QUOTE,
    KC_LSHIFT, KC_LBRC, KC_DLR,  KC_RBRC, KC_HASH,                 KC_CIRC, KC_TILD, KC_GRAVE, _______,     KC_BSLASH,
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
    OSL(L_SHIFT_FUNCTION),   _______,   _______,   _______,   _______,           KC_F10,   KC_F1,   KC_F2,   KC_F3,   _______,
               _______,   _______,                                                       _______,   _______,
                                                _______,           _______,
                          _______,   _______,   _______,           _______,   _______,   _______,
                                               _______,            _______
    ),


[L_SHIFT] = LAYOUT_tracer_stacked(
    LSFT(KC_Q),  LSFT(KC_W),    LSFT(KC_E),    LSFT(KC_R),   LSFT(KC_T),
    LSFT(KC_A),  LSFT(KC_S),    LSFT(KC_D),    LSFT(KC_F),   LSFT(KC_G),
    LSFT(KC_Z),  LSFT(KC_X),    LSFT(KC_C),    LSFT(KC_V),   LSFT(KC_B),
                                       _______,   _______,

                                               _______,
                          _______,   _______,  _______,
                                               _______,

 LSFT(KC_Y),    LSFT(KC_U),    LSFT(KC_I),    LSFT(KC_O),    LSFT(KC_P),
 LSFT(KC_H),    LSFT(KC_J),    LSFT(KC_K),    LSFT(KC_L),    LSFT(KC_SCLN),
 LSFT(KC_N),    LSFT(KC_M),    LSFT(KC_COMM), LSFT(KC_DOT),  LSFT(KC_SLSH),
                _______,   _______,

       KC_DELETE,
       KC_UNDS,   KC_BSPACE,   _______,
       _______

    ),

[L_THUMB_L] = LAYOUT_tracer(
    _______,   MY_WIN_PICKER, KC_END,   _______,   _______,           LALT(LCTL(LGUI(KC_Y))),     KC_PGUP,    LALT(LCTL(LGUI(KC_I))),   LALT(LCTL(LGUI(KC_O))),   _______,
    _______,   _______,   KC_PGDOWN,   _______,   _______,            KC_LEFT,                    KC_DOWN,    KC_UP,   KC_RIGHT,   _______,
    _______,   _______,   MY_LCTL(KC_C),  MY_LCTL(KC_V),   KC_HOME,   MY_SHIFT_INSERT,            LALT(LCTL(LGUI(KC_M))),   _______,   _______,   _______,
               _______,   _______,                                                       _______,   _______,
                                                _______,           KC_DELETE,
                          _______,   _______,   _______,           MY_ALT_TAB,  KC_TAB,   KC_ESC,
                                               _______,            _______
    ),

[L_THUMB_R] = LAYOUT_tracer(
    MY_CTL_ALT_DELETE,   _______,   _______,   _______,       _______,           _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   OSL(L_FUNCTION),_______,           _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,               _______,   _______,   _______,   _______,   _______,
               _______,   _______,                                                       _______,   _______,
                                                _______,           _______,
                          _______,   KC_DELETE, _______,           _______,   _______,   _______,
                                               _______,            _______
    ),
[L_SHIFT_FUNCTION] = LAYOUT_tracer(
    _______,   _______,   _______,   _______,   _______,           LSFT(KC_F12),   LSFT(KC_F7),   LSFT(KC_F8),   LSFT(KC_F9),   _______,
    _______,   _______,   _______,   _______,   _______,           LSFT(KC_F11),   LSFT(KC_F4),   LSFT(KC_F5),   LSFT(KC_F6),   _______,
    _______,   _______,   _______,   _______,   _______,           LSFT(KC_F10),   LSFT(KC_F1),   LSFT(KC_F2),   LSFT(KC_F3),   _______,
               _______,   _______,                                                       _______,   _______,
                                                _______,           _______,
                          _______,   _______,   _______,           _______,   _______,   _______,
                                               _______,            _______
    ),
};


static bool alt_tabbing = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case MY_ALT_TAB:
      if (record->event.pressed) {
        if (!alt_tabbing) {
          alt_tabbing = true;
#ifdef MY_IS_MAC
          SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_TAB));
#else
          SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_TAB));
#endif
        } else {
          SEND_STRING(SS_TAP(X_TAB));
        }
      }
      break;
    case MO(L_THUMB_L):
      if (!record->event.pressed && alt_tabbing) {
#ifdef MY_IS_MAC
        SEND_STRING(SS_TAP(X_LGUI));
#else
        SEND_STRING(SS_TAP(X_LALT));
#endif
        alt_tabbing = false;
      }
      break;
  }
  return true;
}


