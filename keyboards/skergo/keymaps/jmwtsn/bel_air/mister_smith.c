// Copyright 2022 Google LLC, Copyright 2022 Jay Watson jmwtsn@gmail.com
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//
// Addapted from Pascal Getreuer's Mouse Turbo Click
// For full documentation of Pascal Getreuer's original project, see
// https://getreuer.info/posts/keyboards/mouse-turbo-click

#include "features/mister_smith.h"

// This library relies on that mouse keys and the deferred execution API are
// enabled, which we check for here. Enable them in you rules.mk by setting:
//   MOUSEKEY_ENABLE = yes
//   DEFERRED_EXEC_ENABLE = yes
#if !defined(MOUSEKEY_ENABLE)
#error "get_jiggy_withit: Please set `MOUSEKEY_ENABLE = yes` in rules.mk."
#elif !defined(DEFERRED_EXEC_ENABLE)
#error "get_jiggy_withit: Please set `DEFERRED_EXEC_ENABLE = yes` in rules.mk."
#else

// The click period in milliseconds. For instance a period of 200 ms would be 5
// clicks per second. Smaller period implies faster clicking.
//
// WARNING: The keyboard might become unresponsive if the period is too small.
// I suggest setting this no smaller than 50.
#define JIGGY_PERIOD_MS 120000

static deferred_token click_token = INVALID_DEFERRED_TOKEN;
static bool click_registered = false;

// Callback used with deferred execution. It alternates between tapping left
// and right mouse keys.
static uint32_t get_jiggy_callback(uint32_t trigger_time, void *cb_arg) {
  if (click_registered) {
    tap_code16(KC_MS_L);
    click_registered = false;
  } else {
    click_registered = true;
    tap_code16(KC_MS_R);
  }
  return JIGGY_PERIOD_MS / 2;  // Execute callback again in half a period.
}

// Starts Turbo Click, begins the callback.
static void get_jiggy_start(void) {
  if (click_token == INVALID_DEFERRED_TOKEN) {
    uint32_t next_delay_ms = get_jiggy_callback(0, NULL);
    click_token = defer_exec(next_delay_ms, get_jiggy_callback, NULL);
  }
}

// Stops Turbo Click, cancels the callback.
static void get_jiggy_stop(void) {
  if (click_token != INVALID_DEFERRED_TOKEN) {
    cancel_deferred_exec(click_token);
    click_token = INVALID_DEFERRED_TOKEN;
/*    if (click_registered) {
      // If mouse button is currently registered, release it.
      unregister_code16(KC_MS_BTN1);
      click_registered = false;
    }  */
  }
}

bool process_get_jiggy_withit(uint16_t keycode, keyrecord_t* record,
                               uint16_t get_jiggy_keycode) {
  static bool locked = false;
  static bool tapped = false;
  static uint16_t tap_timer = 0;

  if (keycode == get_jiggy_keycode) {
    if (record->event.pressed) {  // Turbo Click key was pressed.
      if (tapped && !timer_expired(record->event.time, tap_timer)) {
        // If the key was recently tapped, lock turbo click.
        locked = true;
      } else if (locked) {
        // Otherwise if currently locked, unlock and stop.
        locked = false;
        tapped = false;
        get_jiggy_stop();
        return false;
      }
      // Set that the first tap occurred in a potential double tap.
      tapped = true;
      tap_timer = record->event.time + TAPPING_TERM;

      get_jiggy_start();
    } else if (!locked) {
      // If not currently locked, stop on key release.
      get_jiggy_stop();
    }

    return false;
  } else {
    // On an event with any other key, reset the double tap state.
    tapped = false;
    return true;
  }
}

#endif
