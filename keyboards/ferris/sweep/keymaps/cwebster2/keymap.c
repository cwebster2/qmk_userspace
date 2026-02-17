/* Copyright 2022 Casey Webster <casey@e1337.dev>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
    _QWERTY = 0,
    _FN,
    _SYMBOLS,
    _NUM,
    _NAV,
    _MOUSE,
    _MEDIA
};

#ifdef COMBO_ENABLE
enum combos {
    ZX_COPY,
    CV_PASTE,
    PB_PARENS,
    FP_CURLY,
    DV_SQUARE,
    MY_ESC,
    MY_DEL,
    RW_ESC,
    RW_DEL,
    MYL_LPRN,
    MYL_DOT,
    MYR_MUTE,
    MYR_BTN2
};

const uint16_t PROGMEM copy_combo[]  = { KC_Z, KC_X, COMBO_END };
const uint16_t PROGMEM paste_combo[] = { KC_C, KC_D, COMBO_END };
const uint16_t PROGMEM curly_combo[] = { KC_F, KC_P, COMBO_END };
const uint16_t PROGMEM parens_combo[] =  { KC_P, KC_B, COMBO_END };
const uint16_t PROGMEM square_combo[] = { KC_D, KC_V, COMBO_END };
const uint16_t PROGMEM esc_combo[] = { LT(_NAV, KC_TAB), LT(_MEDIA, KC_SPC), COMBO_END };
const uint16_t PROGMEM del_combo[] = { LT(_FN, KC_BSPC), LT(_NUM, KC_ENT), COMBO_END };
const uint16_t PROGMEM escL_combo[] = { KC_SPC, KC_TAB, COMBO_END };
const uint16_t PROGMEM delR_combo[] = { KC_ENT, KC_BSPC, COMBO_END };
const uint16_t PROGMEM lprnL_combo[] = { KC_RPRN, KC_UNDS, COMBO_END };
const uint16_t PROGMEM dotL_combo[] = { KC_0, KC_MINS, COMBO_END };
const uint16_t PROGMEM muteR_combo[] = { KC_MSTP, KC_MPLY, COMBO_END };
const uint16_t PROGMEM btn2R_combo[] = { MS_BTN1, MS_BTN3, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    [ZX_COPY]  = COMBO(copy_combo, LCTL_T(KC_C)),
    [CV_PASTE] = COMBO(paste_combo, LCTL_T(KC_V)),
    [PB_PARENS] = COMBO(parens_combo, KC_LPRN),
    [FP_CURLY] = COMBO(curly_combo, KC_LCBR),
    [DV_SQUARE] = COMBO(square_combo, KC_LBRC),
    [MY_ESC] = COMBO(esc_combo, LT(_MOUSE, KC_ESC)),
    [MY_DEL] = COMBO(del_combo, LT(_SYMBOLS, KC_DEL)),
    [RW_ESC] = COMBO(escL_combo, KC_ESC),
    [RW_DEL] = COMBO(delR_combo, KC_DEL),
    [MYL_LPRN] = COMBO(lprnL_combo, KC_LPRN),
    [MYL_DOT] = COMBO(dotL_combo, KC_DOT),
    [MYR_MUTE] = COMBO(muteR_combo, KC_MUTE),
    [MYR_BTN2] = COMBO(btn2R_combo, MS_BTN2),
};
#endif


#define LAYOUT_ferris(...)       LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 */
    [_QWERTY] = LAYOUT_ferris(
             KC_Q,         KC_W,         KC_E,         KC_R,  KC_T,    KC_Y,        KC_U,         KC_I,         KC_O,         KC_P,
      LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    KC_H, LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN),
             KC_Z,         KC_X,         KC_C,         KC_V,  KC_B,    KC_N,        KC_M,      KC_COMM,       KC_DOT,         KC_SLSH,
                             LT(_NAV, KC_SPC),  LT(_MEDIA, KC_TAB),    LT(_FN, KC_ENT),  LT(_NUM, KC_BSPC)
    ),
    [_FN] = LAYOUT_ferris(
      KC_F12,    KC_F7,    KC_F8,    KC_F9,    KC_SYRQ,    KC_NO,   KC_NO,    KC_NO,    KC_NO,    QK_BOOT,
      KC_F11,    KC_F4,    KC_F5,    KC_F6,    KC_TRNS,    KC_NO,   KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
      KC_F10,    KC_F1,    KC_F2,    KC_F3,    KC_PAUSE,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                     KC_SPC,   KC_TAB,     KC_ENT,  KC_BSPC
      ),
    [_SYMBOLS] = LAYOUT_ferris(
      KC_RCBR,    KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_LCBR,    KC_NO,   KC_NO,    KC_NO,    KC_NO,    QK_BOOT,
      KC_COLN,    KC_DLR,    KC_PERC,   KC_CIRC,   KC_PLUS,    KC_NO,   KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
      KC_TILD,    KC_EXLM,   KC_AT,     KC_HASH,   KC_PIPE,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                        KC_RPRN,   KC_UNDS,    KC_ENT,  KC_BSPC
    ),
    [_NUM] = LAYOUT_ferris(
      KC_RBRC,   KC_7,    KC_8,    KC_9,    KC_LBRC,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    QK_BOOT,
      KC_SCLN,   KC_4,    KC_5,    KC_6,    KC_EQL,    KC_NO,   KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
      KC_GRV,    KC_1,    KC_2,    KC_3,    KC_BSLS,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                   KC_RPRN, KC_MINS,   KC_ENT,  KC_BSPC
      ),
    [_NAV] = LAYOUT_ferris(
      QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_UNDO,  KC_CUT,  KC_COPY,  KC_PSTE,  KC_AGIN,
      KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,    KC_LEFT,  KC_DOWN, KC_UP,    KC_RGHT,  CW_TOGG,
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_HOME,  KC_PGDN, KC_PGUP,  KC_END,   KC_INS,
                                    KC_SPC,  KC_TAB,    KC_ENT,  KC_BSPC
      ),
    [_MOUSE] = LAYOUT_ferris(
      QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
      KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,    MS_LEFT,  MS_DOWN,  MS_UP,    MS_RGHT,  KC_NO,
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    MS_WHLL,  MS_WHLD,  MS_WHLU,  MS_WHLR,  KC_NO,
                                    KC_SPC,  KC_TAB,    MS_BTN1,  MS_BTN2
      ),
    [_MEDIA] = LAYOUT_ferris(
      QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
      KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,    KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_NO,
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
                                    KC_SPC,  KC_TAB,    KC_MSTP,  KC_MPLY
     ),
};

