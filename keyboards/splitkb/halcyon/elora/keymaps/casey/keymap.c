// Copyright 2026 Casey Webster <casey.webster@gmail.com>

#include QMK_KEYBOARD_H

#include "casey.h"

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK_DH] = LAYOUT_elora_hlc(
     KC_LBRC , KC_1, KC_2, KC_3, KC_4, KC_5 ,                                         KC_6 ,KC_7, KC_8,    KC_9,   KC_0,    KC_RBRC,
     _______ , KC_Q, KC_W, KC_F, KC_P, KC_B ,                                         KC_J, KC_L, KC_U,    KC_Y,   KC_QUOT, _______,
     _______ , HR_A, HR_R, HR_S, HR_T, KC_G ,                                         KC_M, HR_N, HR_E,    HR_I,   HR_O,    _______,
     _______ , KC_Z, KC_X, KC_C, KC_D, KC_V , _______, _______,     _______, _______, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, _______,
               _______, _______, MSE_ESC, NAV_SPC , MED_TAB   ,     FUN_ENT, NUM_BSP, SYM_DEL, CMAK_GM, KC_PSCR,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_COLEMAK_GAME] = LAYOUT_elora_hlc(
     KC_GRV , KC_1, KC_2, KC_3, KC_4, KC_5 ,                                           KC_6 ,KC_7, KC_8,    KC_9,   KC_0,    KC_RBRC,
     KC_TAB , KC_Q, KC_W, KC_F, KC_P, KC_B ,                                           KC_J, KC_L, KC_U,    KC_Y,   KC_QUOT, KC_BSPC,
     KC_LCTL, KC_A, KC_R, KC_S, KC_T, KC_G ,                                           KC_M, HR_N, HR_E,    HR_I,   HR_O,    KC_SCLN,
     KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V , KC_LCTL, KC_LALT,     _______, _______, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
               KC_EQL, _______, KC_ESC, KC_SPC , KC_TAB   ,     FUN_ENT, NUM_BSP, SYM_DEL, QWTY_GM, KC_F12,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_QWERTY_GAME] = LAYOUT_elora_hlc(
     KC_GRV , KC_1, KC_2, KC_3, KC_4, KC_5 ,                                        KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , KC_ESC ,
     KC_TAB , KC_T, KC_Q, KC_W, KC_E, KC_R ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
     KC_LCTL, KC_G, KC_A, KC_S, KC_D, KC_F ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN, KC_QUOT,
     KC_LSFT, KC_B, KC_Z, KC_X, KC_C, KC_V ,  KC_LBRC,KC_CAPS,   _______  ,KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_MINS,
               KC_EQL, _______, KC_ESC, KC_SPC , KC_TAB   ,     FUN_ENT, NUM_BSP, SYM_DEL, COLEMAK, KC_F12,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),


    [_NUM] = LAYOUT_elora_hlc(
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
     KC_TRNS, KC_RBRC, KC_7,    KC_8,    KC_9,    KC_LBRC,                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                                        KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,
     KC_TRNS, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, KC_TRNS,
                                KC_TRNS, KC_TRNS, KC_DOT,  KC_0,    KC_MINS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_SYM] = LAYOUT_elora_hlc(
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
     KC_TRNS, KC_RCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_LCBR,                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                                       KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,
     KC_TRNS, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, KC_TRNS,
                                KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_UNDS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_FN] = LAYOUT_elora_hlc(
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
     KC_TRNS, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_SYRQ,                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_TRNS,                                       KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,
     KC_TRNS, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUSE, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT, KC_TRNS,
                                KC_TRNS, KC_TRNS, KC_MENU,  KC_SPC,  KC_TAB,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_NAV] = LAYOUT_elora_hlc(
     QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, KC_AGIN, KC_TRNS,
     KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,                                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CW_TOGG, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_RALT, KC_LEFT, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS , KC_TRNS,
                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS,  KC_ENT,  KC_BSPC, KC_DEL,  KC_TRNS, KC_TRNS,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_MOUSE] = LAYOUT_elora_hlc(
     QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,                                       MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_RALT, KC_LEFT, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_TRNS, KC_TRNS,
                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS,  MS_BTN1, MS_BTN3, MS_BTN2, KC_TRNS, KC_TRNS,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_MEDIA] = LAYOUT_elora_hlc(
     QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       UG_TOGG, UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, KC_TRNS,
     KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,                                       KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_RALT, KC_LEFT, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS,  KC_MSTP, KC_MPLY, KC_MUTE, KC_TRNS, KC_TRNS,
     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
};

