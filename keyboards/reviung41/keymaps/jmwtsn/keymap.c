/* Copyright 2020 gtips
 * Copyright (C) 2022  Jay Watson  jmwtsn@gmail.com
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
#include "bel_air/mr_smith.h"

// Left-hand home row mods for Qwerty
#define HRM_A LGUI_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LSFT_T(KC_D)
#define HRM_F LCTL_T(KC_F)

// Right-hand home row mods for Qwerty
#define HRM_J RCTL_T(KC_J)
#define HRM_K RSFT_T(KC_K)
#define HRM_L LALT_T(KC_L)
#define HRM_SCLN RGUI_T(KC_SCLN)

// Left-hand home row mods for Colemak
#define CLHRM_A LGUI_T(KC_A)
#define CLHRM_R LALT_T(KC_R)
#define CLHRM_S LSFT_T(KC_S)
#define CLHRM_T LCTL_T(KC_T)

// Right-hand home row mods for Colemak
#define CLHRM_N RCTL_T(KC_N)
#define CLHRM_E RSFT_T(KC_E)
#define CLHRM_I LALT_T(KC_I)
#define CLHRM_O RGUI_T(KC_O)


enum custom_keycodes {
    EMAIL = SAFE_RANGE,
    SLSAST,
    ASTSLS,
    JIGGY
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!process_get_jiggy_with_it(keycode, record, JIGGY)) { return false; }

    switch (keycode) {
    
    case EMAIL:
        if (record->event.pressed) {
            SEND_STRING("jmwtsn@gmail");
        } else {
        }
        break;
		
	case SLSAST:
        if (record->event.pressed) {
            SEND_STRING("/*");
        } else {
        }
        break;
        
    case ASTSLS:
        if (record->event.pressed) {
            SEND_STRING("*/");
        } else {
        }
        break;	
		
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
  [0] = LAYOUT_reviung41(    //QWERTY
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    KC_BSPC,  HRM_A,    HRM_S,    HRM_D,    HRM_F,     KC_G,               KC_H,     HRM_J,    HRM_K,    HRM_L,    HRM_SCLN, KC_QUOT,
    RGB_TOG,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
                                  KC_LALT,  LT(2,KC_ENT),       KC_TAB,    LT(3,KC_SPC),       KC_PSCR),
 
  [1] = LAYOUT_reviung41(     //Colemak
    _______,   _______, _______,  KC_F,     KC_P,      KC_G,               KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  _______,   
    _______,   CLHRM_A, CLHRM_R,  CLHRM_S,  CLHRM_T,   KC_D,               KC_H,     CLHRM_N,  CLHRM_E,  CLHRM_I,  CLHRM_O,  _______,
    _______,   _______, _______,  _______,  _______,   _______,            KC_K,     _______,  _______,  _______,  _______,  _______,
                                            _______,   _______,  _______,  _______,  _______),


  [2] = LAYOUT_reviung41(    //SYMB	& NAV
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
    KC_DEL,   KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_PIPE,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_GRV,   KC_TILD,
    _______,  _______,  _______,  _______,  KC_CAPS,   KC_DQUO,            KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  RSFT_T(KC_SPC),
                                            _______,   _______,  KC_ENT,   _______,  _______),
  
  [3] = LAYOUT_reviung41(    //NUM & FUNC
    _______,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
    _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
    _______,  KC_ESC,   _______,  _______,  KC_CAPS,   KC_QUOT,            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
                                            _______,   _______,  KC_BSPC,  _______,  _______),
  
  [4] = LAYOUT_reviung41(    //RGB & MOUSE
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            JIGGY,    KC_NUM,   XXXXXXX,  XXXXXXX,  RGB_M_P,  RGB_M_B,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   KC_WH_U,            KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  RGB_M_SW, RGB_M_G,
    KC_ACL0,   KC_ACL1, KC_ACL2,  KC_BTN1,  KC_BTN2,   KC_WH_D,            DT_PRNT,  DT_DOWN,  DT_UP,    XXXXXXX,  RGB_M_T,  RGB_M_K,
                                            TG(1),     _______,  EMAIL,    _______,  _______),
  
/*  [#] = LAYOUT_reviung41(
    _______,   _______, _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,  _______,   
    _______,   _______, _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,  _______,
    _______,   _______, _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,  _______,
                                            _______,   _______,  _______,  _______,  _______),
*/

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, 2, 3, 4);
}


oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR(""), false);

   switch (get_highest_layer(layer_state)) {
        case 0:
			oled_write_ln_P(PSTR("Whatner hell?!"), false);
            break;
        case 1:
			oled_write_ln_P(PSTR("Don't Panic!  "), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("-=[]\\         "), false);
            break;
		case 4:
            oled_write_ln_P(PSTR("RGB & MOUSE   "), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined     "), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif