#include <stdint.h>
#include <stdbool.h>

#include QMK_KEYBOARD_H

// Include the main display functions so we don't have to initialize the display again
#include "hlc_tft_display/hlc_tft_display.h"

// Add a font, this font is generated using the QP CLI tools (https://docs.qmk.fm/quantum_painter#quantum-painter-cli)
#include "graphics/thintel15.qff.h"

#include "casey.h"

// Initialize the font
static painter_font_handle_t thintel;

// Setup painter devices
painter_device_t lcd;
painter_device_t lcd_surface;

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_BLUE);
}

static void set_underglow_color(hsv_t hsv) {
    rgb_t rgb = hsv_to_rgb(hsv);
    for (uint8_t i = 0; i < 6; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    hsv_t hsv = {0, 255, 64};

    bool game = false;
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _COLEMAK_DH:
            hsv = (hsv_t){HSV_BLUE};
            break;
        case _COLEMAK_GAME:
            hsv = (hsv_t){HSV_RED};
            game = true;
            break;
        case _QWERTY_GAME:
            hsv = (hsv_t){HSV_RED};
            game = true;
            break;
        default:
            hsv = (hsv_t){HSV_GREEN};
            break;
    }

    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }

    // TODO only set underglow
    set_underglow_color(hsv);

    // set some underglow for mods

    rgb_t rgb = hsv_to_rgb(hsv);
    // set per-key colors
    for (uint8_t i = 6; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x04)) { // 0x01 == LED_FLAG_MODIFIER
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }

    // red WASD
    if (game && !(is_keyboard_master())) {
        hsv = (hsv_t){HSV_RED};
        if (hsv.v > rgb_matrix_get_val()) {
            hsv.v = rgb_matrix_get_val();
        }
        rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(20, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(21, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(22, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(27, rgb.r, rgb.g, rgb.b);
    }

    // dim the non-36 key footprint
    if (!game) {
        hsv = (hsv_t){HSV_BLUE};
        hsv.v = 24;
        if (hsv.v > rgb_matrix_get_val()) {
            hsv.v = rgb_matrix_get_val();
        }
        rgb = hsv_to_rgb(hsv);

        for (uint8_t i = 30; i < 37; i++) {
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        // rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b);
        // rgb_matrix_set_color(31, rgb.r, rgb.g, rgb.b);
        // rgb_matrix_set_color(32, rgb.r, rgb.g, rgb.b);
        // rgb_matrix_set_color(33, rgb.r, rgb.g, rgb.b);
        // rgb_matrix_set_color(34, rgb.r, rgb.g, rgb.b);
        // rgb_matrix_set_color(35, rgb.r, rgb.g, rgb.b);
        // rgb_matrix_set_color(36, rgb.r, rgb.g, rgb.b);

        rgb_matrix_set_color(24, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(18, rgb.r, rgb.g, rgb.b);

        for (uint8_t i = 9; i < 13; i++) {
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
        // rgb_matrix_set_color(9, rgb.r, rgb.g, rgb.b);
        // rgb_matrix_set_color(10, rgb.r, rgb.g, rgb.b);
        // rgb_matrix_set_color(11, rgb.r, rgb.g, rgb.b);
        // rgb_matrix_set_color(12, rgb.r, rgb.g, rgb.b);
    }

    return false;
}



// This function is ran on bootup of the keyboard
bool module_post_init_user(void) {
    // Load the font in to memory.
    thintel = qp_load_font_mem(font_thintel15);

    return false;
}

// This function runs after every matrix scan
// bool display_module_housekeeping_task_user(bool second_display) {
//     // Create checks to see if the displays are set. We don't need to keep updating the display with the same image so this will save some CPU time.
//     static bool display_set = false;
//     static bool second_display_set = false;
//
//     // When the display isn't set, do the following
//     if (!display_set) {
//         // If it's the main display
//         if (!second_display) {
//             // Create text to write
//             static const char *text = "This is a user display!";
//
//             // Draw text on top left corner
//             qp_drawtext_recolor(lcd_surface, 0, 0, thintel, text, HSV_WHITE, HSV_BLACK);
//
//             switch (get_highest_layer(layer_state|default_layer_state)) {
//                 case _COLEMAK_DH:
//                     qp_drawtext_recolor(lcd_surface, 0, (thintel->line_height)*3, thintel, "COLEMAK", HSV_BLUE, HSV_BLACK);
//                     break;
//                 case _COLEMAK_GAME:
//                     qp_drawtext_recolor(lcd_surface, 0, (thintel->line_height)*3, thintel, "COLEMAK GAME", HSV_RED, HSV_BLACK);
//                     break;
//                 case _QWERTY_GAME:
//                     qp_drawtext_recolor(lcd_surface, 0, (thintel->line_height)*3, thintel, "QWERTY GAME", HSV_RED, HSV_BLACK);
//                     break;
//             }
//             // test fonts
//             int y = (thintel->lineheight)*4;
//             qp_drawtext_recolor(lcd_surface, 0, (thintel->line_height)*3, thintel, "COLEMAK", HSV_BLUE, HSV_BLACK);
//
//             // Make sure to not run this again.
//             display_set = true;
//         // If it's the secundairy display
//         } else {
//             // Create text to write
//             static const char *text = "This is a second user display!";
//
//             // Read width from text
//             int16_t width = qp_textwidth(thintel, text);
//
//             // Draw text on bottom right corner
//             qp_drawtext_recolor(lcd_surface, (LCD_WIDTH - width), (LCD_HEIGHT - thintel->line_height), thintel, text, HSV_WHITE, HSV_BLACK);
//
//             // Make sure to not run this again.
//             display_set = true;
//             second_display_set = true;
//         }
//     }
//
//     // Make sure that the second display loads correctly, sometimes it takes a little while for the keyboard to know it has a second display.
//     // So we reset the state and make it run again until the secondary display is drawn correctly
//     if(second_display && !second_display_set) {
//         display_set = false;
//     }
//
//     // Move surface to lcd, this actually writes the content to the physical display
//     qp_surface_draw(lcd_surface, lcd, 0, 0, 0);
//
//     return false;
// }
