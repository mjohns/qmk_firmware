#pragma once

// Kalih Brown switches
#define LAYOUT_tracer_kalih(                                            \
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

// Cherry mx switches
#define LAYOUT_tracer_cherry1(                                            \
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

// Cherry mx switches 2. With micro usb cable out. Latest build.
#define LAYOUT_tracer_cherry2(                                            \
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
    { KC_NO, L42,   KC_NO, LB,    LG,    LT }, \
    { KC_NO, L51,   KC_NO, LV,    LF,    LR }, \
    { KC_NO, L40,   L63,   LC,    LD,    LE }, \
    { KC_NO, L41,   L62,   LX,    LS,    LW }, \
    { KC_NO, L50,   KC_NO, LZ,    LA,    LQ }, \
\
    { KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,   KC_NO }, \
    { KC_NO, R42, KC_NO,   RN,       RH,      RY }, \
    { KC_NO, R51, KC_NO,   RM,       RJ,      RU }, \
    { KC_NO, R40,   R63,   RCOMMA,   RK,      RI }, \
    { KC_NO, R41,   R64,   RPERIOD,  RL,      RO }, \
    { KC_NO, R50, KC_NO,   RQUESTION, RCOLON, RP }, \
   }

#ifdef MY_IS_KALIH
#define LAYOUT_tracer LAYOUT_tracer_kalih
#endif

#ifdef MY_IS_CHERRY1
#define LAYOUT_tracer LAYOUT_tracer_cherry1
#endif

#ifdef MY_IS_CHERRY2
#define LAYOUT_tracer LAYOUT_tracer_cherry2
#endif

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
