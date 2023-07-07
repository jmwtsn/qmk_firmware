# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
AUDIO_ENABLE = no           # Audio output
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
EXTRAKEY_ENABLE = yes       # Audio control and System control
MOUSEKEY_ENABLE = yes       # Mouse keys
NKRO_ENABLE = no            # Enable N-Key Rollover
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow

DYNAMIC_TAPPING_TERM_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

SRC += bel_air/mr_smith.c