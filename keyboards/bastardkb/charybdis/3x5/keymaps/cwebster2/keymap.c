/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#   include "timer.h"
#endif

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    _MOUSE,
    _NAV,
    _MEDIA,
    _FN,
    _NUM,
    _SYM,
};

#ifdef COMBO_ENABLE
enum combos {
    DV_SQUARE,
};

const uint16_t PROGMEM square_combo[] = { KC_D, KC_V, COMBO_END };

combo_t key_combos[] = {
    [DV_SQUARE] = COMBO( square_combo, KC_LBRC ),
};

#endif

// #define CHARYBDIS_AUTO_SNIPING_ON_LAYER _MOUSE

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define TAB_MED LT(_MEDIA, KC_TAB)
#define SPC_NAV LT(_NAV, KC_SPC)
#define ENT_FUN LT(_FN, KC_ENT)
// #define ENT_SYM LT(_SYM, KC_ENT)
#define BSP_NUM LT(_NUM, KC_BSPC)
#define _L_PTR(KC) LT(_MOUSE, KC)

#define _________HMR_L______________ LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T)
#define _________HMR_R______________ LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(
  // ╭───────────────────────────────────────────╮ ╭──────────────────────────────────────────────────╮
          KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,       KC_J,   KC_L,   KC_U,     KC_Y,    KC_QUOT,
  // ├───────────────────────────────────────────┤ ├──────────────────────────────────────────────────┤
          _________HMR_L______________,   KC_G,       KC_M,    _________HMR_R______________,
  // ├───────────────────────────────────────────┤ ├──────────────────────────────────────────────────┤
          KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,       KC_K,   KC_H,   KC_COMM,  KC_DOT,  KC_SLSH,
  // ╰───────────────────────────────────────────┤ ├──────────────────────────────────────────────────╯
                    KC_ESC,  SPC_NAV,  TAB_MED,       ENT_FUN,  BSP_NUM
  //             ╰───────────────────────────────╯ ╰─────────────────────────────────────────╯
  ),

  [_MOUSE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────╮
          QK_BOOT,   EE_CLR,    XXXXXXX,   DPI_MOD,   S_D_MOD,       S_D_MOD,   DPI_MOD,   XXXXXXX,   EE_CLR,    QK_BOOT,
  // ├──────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
          KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,   XXXXXXX,       XXXXXXX,   KC_LSFT,   KC_LCTL,   KC_LALT,   KC_LGUI,
  // ├──────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
          _______,   DRGSCRL,   SNIPING,   XXXXXXX,   XXXXXXX,       XXXXXXX,   XXXXXXX,   SNIPING,   DRGSCRL,   _______,
  // ╰──────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────╯
                         MS_BTN2, MS_BTN1,  MS_BTN3,                 MS_BTN3,   MS_BTN1
  //                   ╰────────────────────────────────────────╯ ╰─────────────────────────────────────────╯
  ),

  [_NAV] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────╮
          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_J, KC_L,         KC_U,         KC_Y,         KC_QUOT,
  // ├──────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
          KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,   KC_TRNS,       KC_M, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O),
  // ├──────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_K, KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,
  // ╰──────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────╯
                         KC_TRNS, KC_TRNS,  KC_TRNS,                 KC_ENT, KC_BSPC
  //                   ╰────────────────────────────────────────╯ ╰─────────────────────────────────────────╯
  ),

  [_MEDIA] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────╮
          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_J, KC_L,         KC_U,         KC_Y,         KC_QUOT,
  // ├──────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
          KC_LGUI,   KC_LALT,   KC_LCTL,   KC_LSFT,   KC_TRNS,       KC_M, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O),
  // ├──────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_K, KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,
  // ╰──────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────╯
                         KC_TRNS, KC_TRNS,  KC_TRNS,                 KC_ENT, KC_BSPC
  //                   ╰────────────────────────────────────────╯ ╰─────────────────────────────────────────╯
  ),

  [_FN] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────╮
          KC_Q,         KC_W,         KC_F,         KC_P,            KC_B,       QK_BOOT,    EE_CLR,     KC_TRNS,    KC_TRNS,    KC_TRNS,
  // ├──────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
          LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),    KC_G,       KC_TRNS,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,
  // ├──────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
          KC_Z,         KC_X,         KC_C,         KC_D,            KC_V,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  // ╰──────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────╯
                         KC_ESC, KC_SPC,  KC_TAB,                                KC_TRNS,    KC_TRNS
  //                   ╰────────────────────────────────────────────────────╯ ╰─────────────────────────────────────────╯
  ),

  [_NUM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────╮
          KC_Q,         KC_W,         KC_F,         KC_P,            KC_B,       QK_BOOT,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  // ├──────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
          LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),    KC_G,       KC_TRNS,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,
  // ├──────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
          KC_Z,         KC_X,         KC_C,         KC_D,            KC_V,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  // ╰──────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────╯
                         KC_ESC, KC_SPC,  KC_TAB,                                KC_TRNS,    KC_TRNS
  //                   ╰────────────────────────────────────────────────────╯ ╰─────────────────────────────────────────╯
  ),


  [_SYM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────╮
          KC_Q,         KC_W,         KC_F,         KC_P,            KC_B,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  // ├──────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
          LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),    KC_G,       KC_TRNS,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,
  // ├──────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────┤
          KC_Z,         KC_X,         KC_C,         KC_D,            KC_V,       KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
  // ╰──────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────╯
                         KC_ESC, KC_SPC,  KC_TAB,                                KC_TRNS,    KC_TRNS
  //                   ╰────────────────────────────────────────────────────╯ ╰─────────────────────────────────────────╯
  ),

};

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(_MOUSE);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_keymap(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(_MOUSE);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in
// rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif

// clang-format on
