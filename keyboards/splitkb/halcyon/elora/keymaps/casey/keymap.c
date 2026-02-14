// Copyright 2026 Casey Webster <casey.webster@gmail.com>

#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK_DH = 0,
    _QWERTY_OFFSET,
    _NAV,
    _SYM,
    _FN,
    _MOUSE,
    _MEDIA,
    _NUM,
};

#define COLEMAK DF(_COLEMAK_DH)
#define QWERTY  DF(_QWERTY_OFFSET)

#define SYM LT(_SYM, KC_SPC)
#define NUM LT(_FUNC, KC_ENT)

#define MSE_ESC  LT(_MOUSE, KC_ESC)
#define NAV_SPC  LT(_NAV, KC_SPC)
#define MED_TAB  LT(_MEDIA, KC_TAB)
#define FN_END   LT(_FN, KC_ENT)
#define NUM_BKSP LT(_NUM, KC_BSPC)
#define SYM_DEL  LT(_SYM, KC_DEL)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define ALT_ENT  MT(MOD_LALT, KC_ENT)

#define _______COLEMAK_L2_____ LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),        KC_G
#define _______COLEMAK_R2_____        KC_M,  LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK_DH] = LAYOUT(
     QK_BOOT , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,                                        KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , QK_BOOT ,
     _______  , KC_Q ,  KC_W   ,  KC_F  ,   KC_P ,   KC_B ,                                        KC_J,   KC_L ,  KC_U ,   KC_Y ,KC_SCLN, _______,
     _______ , LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G ,                      KC_M,   LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O),  _______,
     _______ , KC_Z ,  KC_X   ,  KC_C  ,   KC_D ,   KC_V , _______, _______,     _______  , _______, KC_K,   KC_H ,KC_COMM, KC_DOT ,KC_SLSH, _______,
                                 _______, _______, KC_ESC, KC_SPC , KC_TAB   ,     KC_ENT , KC_BSPC ,KC_DEL, _______, _______
    ),


    // [_QWERTY_OFFSET] = LAYOUT(
    //  KC_ESC  , KC_1 ,  KC_2   ,  KC_3  ,   KC_4 ,   KC_5 ,                                        KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 , KC_ESC ,
    //  KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
    //  CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
    //  KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
    //                             ADJUST , KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
    // ),
};
