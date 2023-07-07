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
//#include "bel_air/mr_smith.h"tt

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
    NOCON,
    SLSAST,
    ASTSLS,
    NXT,
    JIGGY,
	PHNUM,
	NOTES
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

//  if (!process_get_jiggy_with_it(keycode, record, JIGGY)) { return false; }

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
            SEND_STRING("203" SS_TAP(X_ENT)
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
            SEND_STRING("Interrupted by call-in. ");
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
        
        

        
        
    case SELNUM:
        if (record->event.pressed) {
            SEND_STRING(
			SS_DOWN(X_LCTL)SS_TAP(X_TAB)SS_UP(X_LCTL)
		    SS_TAP(X_ESC)
            SS_TAP(X_F7)
            SS_DELAY(100)
            SS_TAP(X_ENT)
            SS_DELAY(200)            //turn on caret browsing and wait
            SS_LCTL("f")"Calling "
			SS_DELAY(100)
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
            SS_DOWN(X_LGUI)SS_TAP(X_3)SS_UP(X_LGUI)
            SS_DELAY(200)            //switch to VCC and wait
     		SS_LCTL("v")             //paste number
			SS_TAP(X_ENT)
            );
        } else {
        }
        break;






    case DISCO:										// Hang up VCC call
        if (record->event.pressed) {				// Start fron VCC number field
            SEND_STRING(
            SS_TAP(X_TAB)SS_TAP(X_TAB)				// Tab to My Interactions
            SS_DOWN(X_LCTL) "d" SS_UP(X_LCTL)		// Disconnect
            SS_DOWN(X_LSFT)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_TAP(X_TAB)SS_UP(X_LSFT)	// Return to VCC number field
            ); 
        } else {
        }
        break;
			
			
    case NOCON:										// Hang up VCC, switch to CMP and enter no contact
        if (record->event.pressed) {				// Start fron VCC number field
            SEND_STRING(
            SS_DOWN(X_LGUI)SS_TAP(X_4)SS_UP(X_LGUI)	// Switch to CMP (in Microsoft Edge)
            SS_DELAY(200)
            SS_TAP(X_TAB) 
            SS_DELAY(300) "n" 
            SS_TAP(X_TAB) SS_TAP(X_ENT)
            SS_DELAY(200) 
            );
        } else {
        }
        break;
			
        
    case NXT:										// Submits current CMP tscase and opens the next
        if (record->event.pressed) {				// Start fron CMP end notes field
			SEND_STRING(
			SS_TAP(X_TAB)							// Tab to submit button
            SS_DELAY(200)
            SS_TAP(X_ENT) 							// Enter to submit
            SS_DELAY(2500)"c"						// Open next case
			SS_DELAY(2000)
			SS_DOWN(X_LCTL)"0"SS_DELAY(50)"-"SS_UP(X_LCTL)		// Adjust zoom
			SS_DELAY(500)
			SS_TAP(X_DOWN)SS_DELAY(5ts0)SS_TAP(X_DOWN)SS_DELAY(150)
			SS_DOWN(X_LCTL)"0"SS_DELAY(50)"==="SS_UP(X_LCTL)SS_DELAY(1500)"c"
			SS_DELAY(500)SS_TAP(X_ENT)"1"
				SS_DOWN(X_LCTL)SS_TAP(X_TAB)"w"SS_UP(X_LCTL)   // Begin Notes shortcut
			SS_DELAY(50)SS_LALT("d")SS_DELAY(50)
			SS_LCTL("c")SS_DELAY(50)SS_LCTL("tv")
			SS_TAP(X_ENT)SS_DELAY(1500)" ");
        } else {
        }
        break;
	
			
			
	case PHNUM:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_LEFT)SS_TAP(X_LEFT)" (ph)"SS_TAP(X_LEFT));
        } else {
        }
        break;
    
		
		

		
	case NOTES:
        if (record->event.pressed) {
            SEND_STRING(
			SS_DOWN(X_LCTL)SS_TAP(X_TAB)"w"SS_UP(X_LCTL)
			SS_DELAY(50)SS_LALT("d")SS_DELAY(50)
			SS_LCTL("c")SS_DELAY(50)SS_LCTL("tv")
			SS_TAP(X_ENT)" ");
        } else {
        }
        break;
        

	    
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(    /*Qwerty*/
		KC_ESC,  KC_1,    KC_2,   KC_3,  KC_4,   KC_5,    KC_6,        KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS, KC_EQL,  KC_GRV,  KC_BSPC,
		LT(2,KC_TAB),     KC_Q,   KC_W,  KC_E,   KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_PGUP,
		KC_BSPC, HRM_A,   HRM_S,  HRM_D, HRM_F,  KC_G,                 KC_H,    HRM_J,   HRM_K,   HRM_L,  HRM_SCLN,KC_QUOT, LT(3,KC_ENT),       KC_PGDN,
		KC_LSFT, KC_Z,    KC_X,   KC_C,  KC_V,   KC_B,                 KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,          KC_UP,     KC_END,
		KC_LCTL, KC_LALT, LT(1,KC_ENT),  LGUI_T(KC_TAB),               KC_SPC,  MT(KC_LCTL,KC_PSCR),                  KC_LEFT, KC_DOWN, KC_RGHT),


	[1] = LAYOUT(    /*Numpad*/
		_______, MSG,     NML,     RNA,     GEN,     BSIG,    DNC,         DNC2,    PHNUM,   _______, SELNUM,  _______, _______, KC_NUM,  KC_DEL,
		_______, JIGGY,   _______, _______, _______, NOTES,                KC_P7,   KC_P8,   KC_P9,   KC_P0,   _______, SLSAST,  ASTSLS,  _______, KC_VOLU,
		KC_DEL,  _______, _______, DISCO,   NOCON,   _______,              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,          KC_VOLD,
		_______, _______, _______, NXT,     _______, _______,              KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, KC_PGUP,          MU_TOG,
		_______, _______, _______, _______,                                KC_P0,   _______,                            KC_HOME, KC_PGDN, KC_END),


	[2] = LAYOUT(    /*Function & mouse*/
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
		_______, _______, _______, _______, _______, _______,           _______, _______, KC_MS_U, _______, _______, _______, _______, _______, KC_WH_U,
		_______, _______, _______, _______, _______, _______,           _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______,          KC_WH_D,
		_______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,          KC_BTN3,
		_______, _______, _______, _______,                             KC_BTN1, KC_BTN2,                            _______, _______, _______),


	[3] = LAYOUT(    /*Macros*/
		_______, MSG,     NML,     RNA,     GEN,     BSIG,    DNC,      DNC2,    PHNUM,   _______, SELNUM,  _______, _______, _______, _______,
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
