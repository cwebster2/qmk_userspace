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
//#include "raw_hid.h"
#define RAW_EPSIZE 8
#include <stdio.h>

#include "cwebster2.h"

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
    [_COLEMAK] = LAYOUT_ferris(
 /* ,-----------------------. -----------------------. */
      _______COLEMAK_L1_____, _______COLEMAK_R1_____,
      _______COLEMAK_L2_____, _______COLEMAK_R2_____,
      _______COLEMAK_L3_____, _______COLEMAK_R3_____,
      ____34_THUMBS_L_______, ____34_THUMBS_R_______
 /*           `---------------------'  `---------------------' */
    ),
    [_FN] = LAYOUT_ferris(
 /* ,-----------------------.  -----------------------. */
      _______FN_______L1____,  _______INACTIVE_R1____,
      _______FN_______L2____,  _______INACTIVE_R2____,
      _______FN_______L3____,  _______NAV______R2____,
      ____34_FN________T____,  ____34_INACTIVE__T____
 /*           `---------------------'  `---------------------' */
      ),
    [_SYMBOLS] = LAYOUT_ferris(
 /* ,-----------------------.  -----------------------. */
      _______SYM______L1____,  _______INACTIVE_R1____,
      _______SYM______L2____,  _______INACTIVE_R2____,
      _______SYM______L3____,  _______INACTIVE_R3____,
      ____34_SYM_______T____,  ____34_INACTIVE__T____
 /*           `---------------------'  `---------------------' */
    ),
    [_NUM] = LAYOUT_ferris(
 /* ,-----------------------. -----------------------. */
      _______NUM______L1____, _______INACTIVE_R1____,
      _______NUM______L2____, _______INACTIVE_R2____,
      _______NUM______L3____, _______INACTIVE_R3____,
      ____34_NUM_______T____, ____34_INACTIVE__T____
 /*           `---------------------'  `---------------------' */
      ),
    [_NAV] = LAYOUT_ferris(
 /* ,-----------------------. -----------------------. */
      _______INACTIVE_L1____, _______NAV______R1____,
      _______INACTIVE_L2____, _______NAV______R2____,
      _______INACTIVE_L3____, _______NAV______R3____,
      ____34_INACTIVE__T____, ____34_NAV_______T____
 /*           `---------------------'  `---------------------' */
      ),
    [_MOUSE] = LAYOUT_ferris(
 /* ,-----------------------. -----------------------. */
      _______INACTIVE_L1____, _______MOUSE____R1____,
      _______INACTIVE_L2____, _______MOUSE____R2____,
      _______INACTIVE_L3____, _______MOUSE____R3____,
      ____34_INACTIVE__T____, ____34_MOUSE_____T____
 /*           `---------------------'  `---------------------' */
      ),
    [_MEDIA] = LAYOUT_ferris(
 /* ,-----------------------. -----------------------. */
      _______INACTIVE_L1____, _______MEDIA____R1____,
      _______INACTIVE_L2____, _______MEDIA____R2____,
      _______INACTIVE_L3____, _______MEDIA____R3____,
      ____34_INACTIVE__T____, ____34_MEDIA_____T____
 /*           `---------------------'  `---------------------' */
     ),
};

#ifdef RAW_ENABLE
static void send_layer_via_hid(int layer) {
    uint8_t data[RAW_EPSIZE];
    data[0] = 1;
    data[1] = layer;
    raw_hid_send(data, sizeof(data));
    return;
}
#endif

