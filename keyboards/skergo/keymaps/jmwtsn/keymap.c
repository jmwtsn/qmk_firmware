/* Copyright (C) 2021  Keyz.io Ltd.
* Copyright (C) 2022  Jay Watson  jmwtsn@gmail.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
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

enum custom_keycodes {
    MSG = SAFE_RANGE,
    NML,
    RNA,
    GEN,
    BSIG,
    DNC,
    DNC2,
    NIS,
    SELNUM,
    DISCO,
    MSJIG,
    NOCON,
    SLSAST,
    ASTSLS,
    NXT,
    JIGGY1,
    JIGGY2
};


/*  Bunch of code from DIYCharles' Mouse Jiggler project.


bool mouse_jiggle_mode = false;

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
  
  if (mouse_jiggle_mode) {
    tap_code(KC_MS_UP);
    tap_code(KC_MS_DOWN);
  } else {

  }
}

*/

/*
  if (!waiting) {
    tap_code(KC_MS_UP);
    tap_code(KC_MS_DOWN);
    key_timer = timer_read();
    waiting = true;
  } else if (timer_elapsed(key_timer) > 60000) {
    waiting = false;    
  }
 
  
  if (mouse_jiggle_mode) {      
   
  } else {

  }
}

*/


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    

    case MSG:
        if (record->event.pressed) {
            SEND_STRING("204" SS_TAP(X_ENT)
			SS_DELAY(200) SS_TAP(X_TAB) 
			SS_DELAY(200) "Message left at "SS_LCTL("v")". ");
        } else {
        }
        break;
        
		    
    case NML:
        if (record->event.pressed) {
            SEND_STRING(/*  SS_TAP(X_NOCON)  */   
                        "203" SS_TAP(X_ENT)
            		SS_DELAY(200) SS_TAP(X_TAB) 
            		SS_DELAY(200) "No message left at "SS_LCTL("v")". ");
        } else {
        }
        break;
        
		    
    case RNA:
        if (record->event.pressed) {
            SEND_STRING("201" SS_TAP(X_ENT) 
                        SS_DELAY(200) SS_TAP(X_TAB)
                        SS_DELAY(200) "RNA at "SS_LCTL("v")". ");
        } else {
        }
        break;
        
		    
    case GEN:
        if (record->event.pressed) {
            SEND_STRING("Generic VM. ");
        } else {
        }
        break;

		    
    case BSIG:
        if (record->event.pressed) {
            SEND_STRING("202" SS_TAP(X_ENT) 
                        SS_DELAY(200) SS_TAP(X_TAB)
                        SS_DELAY(200) "Busy signal at "SS_LCTL("v")". ");
        } else {
        }
        break;
        
		    
    case DNC:
        if (record->event.pressed) {
            SEND_STRING("Did not call. ");
        } else {
        }
        break;
        
        
    case DNC2:
        if (record->event.pressed) {
            SEND_STRING("Interupted by call-in. ");
        } else {
        }
        break;
        
		    
    case NIS:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_END) SS_UP(X_LALT)
                        SS_DELAY(300) 
                        SS_TAP(X_TAB) 
                        SS_TAP(X_TAB) 
                        SS_TAP(X_TAB) 
                        SS_TAP(X_TAB) 
                        SS_TAP(X_ENT) 
                        SS_DELAY(2500) "800" 
                        SS_TAP(X_ENT)
                        SS_TAP(X_TAB) 
                        SS_DELAY(200) "No valid numbers available. ");
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
        
        
    case NOCON:
        if (record->event.pressed) {
            SEND_STRING(
            SS_DOWN(X_LALT)SS_TAP(X_TAB)SS_UP(X_LALT)
            SS_DELAY(200)
            SS_TAP(X_TAB) 
            SS_DELAY(300) "n" 
            SS_TAP(X_TAB) SS_TAP(X_ENT)
            SS_DELAY(200) 
            );
        } else {
        }
        break;
        
        
    case SELNUM:
        if (record->event.pressed) {
            SEND_STRING(
            SS_TAP(X_F7)
            SS_DELAY(100)
            SS_TAP(X_ENT)
            SS_DELAY(200)            //turn on caret browsing and wait
            SS_LCTL("f")"Calling "
            SS_TAP(X_ENT)
            SS_TAP(X_ESC)
            SS_DELAY(200)
            SS_TAP(X_RIGHT)          //move to start of phone number
            SS_DOWN(X_LCTL)
            SS_DOWN(X_LSFT)
            SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)SS_TAP(X_RIGHT)
            SS_UP(X_LCTL)  
            SS_TAP(X_LEFT)SS_UP(X_LSFT)
            SS_LCTL("c")             //select phone number
            SS_TAP(X_F7)             //turn off caret browsing
            SS_DOWN(X_LALT)SS_TAP(X_TAB)SS_UP(X_LALT)
            SS_DELAY(200)            //switch to VCC and wait
            SS_LCTL("v")             //paste number
            SS_TAP(X_ENT)
            );
        } else {
        }
        break;


    case DISCO:
        if (record->event.pressed) {
            SEND_STRING(
            SS_TAP(X_TAB)SS_TAP(X_TAB)
            SS_DOWN(X_LCTL) "d" SS_UP(X_LCTL)
            SS_DOWN(X_LSFT)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_UP(X_LSFT)
            ); 
        } else {
        }
        break;
        
    case NXT:
        if (record->event.pressed) {
            SEND_STRING(
            SS_TAP(X_TAB)
            SS_DELAY(200)
            SS_TAP(X_ENT) 
            SS_DELAY(2000)"c");
        } else {
        }
        break;
        
        

/*   DIYCHarles mouse jiggler macro

    case JIGGY1:
      if (record->event.pressed) {
        mouse_jiggle_mode = true;
      } else {
        mouse_jiggle_mode = false;
      }
      break;
        
*/        

	    
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(    /*Qwerty*/
		KC_ESC,  KC_1,    KC_2,   KC_3,  KC_4,   KC_5,    KC_6,        KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS, KC_EQL,  KC_GRV,  KC_BSPC,
		LT(2,KC_TAB),     KC_Q,   KC_W,  KC_E,   KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_PGUP,
		LT(3,KC_BSPC),    KC_A,   KC_S,  KC_D,   KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, LT(3,KC_ENT),       KC_PGDN,
		KC_LSFT, KC_Z,    KC_X,   KC_C,  KC_V,   KC_B,                 KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,          KC_UP,     KC_END,
		KC_LCTL, KC_LALT, LT(1,KC_ENT),  KC_LGUI,                      KC_SPC,        MT(KC_LCTL,KC_PSCR),                  KC_LEFT, KC_DOWN, KC_RGHT),


	[1] = LAYOUT(    /*Numpad*/
		_______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, KC_LNUM, KC_DEL,
		_______, _______, _______, _______, _______, _______,              KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______, SLSAST,  ASTSLS,  _______, KC_VOLU,
		_______, _______, _______, DISCO,   NOCON,   _______,              KC_P4,   KC_P5,   KC_P6,   _______, _______, _______, _______,          KC_VOLD,
		_______, _______, _______, NXT,     _______, _______,              KC_P1,   KC_P2,   KC_P3,   _______, _______, _______, KC_PGUP,          MU_TOG,
		_______, _______, _______, _______,                                KC_P0,   _______,                            KC_HOME, KC_PGDN, KC_END),


	[2] = LAYOUT(    /*Function & mouse*/
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
		_______, _______, _______, _______, _______, _______,           _______, _______, KC_MS_U, _______, _______, _______, _______, _______, KC_WH_U,
		_______, _______, _______, _______, _______, _______,           _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______,          KC_WH_D,
		_______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,          KC_BTN3,
		_______, _______, _______, _______,                             KC_BTN1, KC_BTN2,                            _______, _______, _______),


	[3] = LAYOUT(    /*Macros*/
		_______, MSG,     NML,     RNA,     GEN,     BSIG,    DNC,      DNC2,    NIS,     _______, SELNUM,  _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,           _______, _______, KC_UP,   _______, _______, _______, _______, _______, KC_BRIU,
		_______, _______, _______, _______, _______, _______,           _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,          KC_BRID,
		_______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,          KC_INS,
		_______, _______, _______, _______,                             _______, _______,                            _______, _______, _______),


	[4] = LAYOUT(    /*Colemak*/
		_______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
		_______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,              KC_J,    KC_L,    KC_K,    KC_L,    KC_SCLN, _______, _______, _______, _______,
		KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,              KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______, _______,          _______,
		_______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,              KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, _______,          _______,
		_______, _______, _______, _______,                             _______, _______,                            _______, _______, _______)


};
