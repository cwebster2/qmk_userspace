#pragma once

#include "eeprom.h"

enum layers {
    _COLEMAK_DH = 0,
    _COLEMAK_GAME,
    _QWERTY_GAME,

    _NAV,
    _SYM,
    _FN,
    _MOUSE,
    _MEDIA,
    _NUM,
};

#define COLEMAK DF(_COLEMAK_DH)
#define CMAK_GM DF(_COLEMAK_GAME)
#define QWTY_GM DF(_QWERTY_GAME)

#define MSE_ESC  LT(_MOUSE, KC_ESC)
#define NAV_SPC  LT(_NAV, KC_SPC)
#define MED_TAB  LT(_MEDIA, KC_TAB)
#define FUN_ENT  LT(_FN, KC_ENT)
#define NUM_BSP  LT(_NUM, KC_BSPC)
#define SYM_DEL  LT(_SYM, KC_DEL)

#define HR_A     LGUI_T(KC_A)
#define HR_R     LALT_T(KC_R)
#define HR_S     LCTL_T(KC_S)
#define HR_T     LSFT_T(KC_T)

#define HR_N     LSFT_T(KC_N)
#define HR_E     LCTL_T(KC_E)
#define HR_I     LALT_T(KC_I)
#define HR_O     LGUI_T(KC_O)

