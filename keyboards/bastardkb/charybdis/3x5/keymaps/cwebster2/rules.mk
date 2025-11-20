# MCU name
MCU = RP2040

BOARD = QMK_PM2040

# Bootloader selection
CONVERT_TO=rp2040_ce
BOOTLOADER = rp2040
PICO_INTRINSICS_ENABLED = no

# Build Options
#   change yes to no to disable
#
COMBO_ENABLE = yes
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
UNICODE_ENABLE = yes        # Unicode
CONSOLE_ENABLE = yes         # Console for debug
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
SPLIT_KEYBOARD = yes        # Use shared split_common code
SERIAL_DRIVER = vendor
NKRO_ENABLE = yes           # USB Nkey Rollover


COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output

