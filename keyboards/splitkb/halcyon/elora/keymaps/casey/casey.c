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

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    hsv_t hsv = {0, 255, 64};

    // if (get_highest_layer(layer_state|default_layer_state) == 2) {
    //     hsv = (hsv_t){130, 255, 64};
    // } else {
    //     hsv = (hsv_t){30, 255, 64};
    // }

    switch (get_highest_layer(layer_state)) {
        case 0:
            hsv = (hsv_t){HSV_BLUE};
            break;
        case 1:
            hsv = (hsv_t){HSV_RED};
            break;
        case 2:
            hsv = (hsv_t){HSV_RED};
            break;
        default:
            hsv = (hsv_t){HSV_GREEN};
            break;
    }

    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    rgb_t rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x01)) { // 0x01 == LED_FLAG_MODIFIER
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
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
bool display_module_housekeeping_task_user(bool second_display) {
    // Create checks to see if the displays are set. We don't need to keep updating the display with the same image so this will save some CPU time.
    static bool display_set = false;
    static bool second_display_set = false;

    // When the display isn't set, do the following
    if (!display_set) {
        // If it's the main display
        if (!second_display) {
            // Create text to write
            static const char *text = "This is a user display!";

            // Draw text on top left corner
            qp_drawtext_recolor(lcd_surface, 0, 0, thintel, text, HSV_WHITE, HSV_BLACK);

            // Make sure to not run this again.
            display_set = true;
        // If it's the secundairy display
        } else {
            // Create text to write
            static const char *text = "This is a second user display!";

            // Read width from text
            int16_t width = qp_textwidth(thintel, text);

            // Draw text on bottom right corner
            qp_drawtext_recolor(lcd_surface, (LCD_WIDTH - width), (LCD_HEIGHT - thintel->line_height), thintel, text, HSV_WHITE, HSV_BLACK);

            // Make sure to not run this again.
            display_set = true;
            second_display_set = true;
        }
    }

    // Make sure that the second display loads correctly, sometimes it takes a little while for the keyboard to know it has a second display.
    // So we reset the state and make it run again until the secondary display is drawn correctly
    if(second_display && !second_display_set) {
        display_set = false;
    }

    // Move surface to lcd, this actually writes the content to the physical display
    qp_surface_draw(lcd_surface, lcd, 0, 0, 0);

    return false;
}
