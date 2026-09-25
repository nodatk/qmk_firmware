// Copyright 2022 Takeshi Noda (nodatk@gmail.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "gpio.h"

#define LAL_NCV  LALT_T(KC_LNG2)
#define RAL_CNV  RALT_T(KC_LNG1)
#define LGU_NCV  LGUI_T(KC_LNG2)
#define RGU_ENT  RGUI_T(KC_ENT)
#define RGU_IN8  RGUI_T(KC_INT8)

#define RSF_SCL  RSFT_T(KC_SCLN)
#define RCT_ESC  RCTL_T(KC_ESC)
#define RCT_IN7  RCTL_T(KC_INT7)

#define LT1_SPC  LT(1, KC_SPC)
#define LT2_F    LT(2, KC_F)
#define LT2_N    LT(2, KC_N)
#define LT3_BS   LT(3, KC_BSPC)
#define LT3_V    LT(3, KC_V)
#define LT3_QOT  LT(3, KC_QUOT)
#define TG4      TG(4)

#define SFT_1    RSFT(KC_1)
#define SFT_2    RSFT(KC_2)
#define SFT_3    RSFT(KC_3)
#define SFT_4    RSFT(KC_4)
#define SFT_5    RSFT(KC_5)
#define SFT_6    LSFT(KC_6)
#define SFT_7    LSFT(KC_7)
#define SFT_8    LSFT(KC_8)
#define SFT_9    LSFT(KC_9)
#define SFT_0    LSFT(KC_0)
#define SFT_LBR  LSFT(KC_LBRC)

#define OSM_LSF  OSM(MOD_LSFT)

// Layer scaffold -- just enough to exercise per-layer behavior (LED pattern
// below); the actual key choices here are placeholders to replace later.
//   Layer 0 (0,0)=TG(1): toggle into layer 1
//   Layer 1 (0,0)=TG(1): toggle back to layer 0; (0,1)=TG(2): jump to layer 2
//   Layer 2 (0,0)=TG(2): toggle back to layer 0
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Layer 0, Base layer
  LAYOUT_orth_2x4(
    TG(1),   KC_W,    KC_E,    KC_R,
    KC_A,    KC_S,    KC_D,    KC_F
  ),

  // Layer 1, placeholder
  LAYOUT_orth_2x4(
    TG(1),   TG(2),   KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // Layer 2, placeholder
  LAYOUT_orth_2x4(
    TG(2),   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

// Status-LED (LED1/PC13, "LED_STATUS" net): steady on for layer 0, blinking
// (rate depends on the active layer) for anything else -- non-blocking:
// matrix_scan_user() runs once per main-loop iteration alongside normal
// matrix scanning/USB handling, so this never interferes with keyboard
// operation.
//
// Placeholder rates -- adjust freely.
static uint16_t status_led_blink_ms(void) {
    switch (get_highest_layer(layer_state)) {
        case 2:  return 250;  // fast
        default: return 750;  // layer 1 and any other non-zero layer
    }
}

void keyboard_post_init_user(void) {
    gpio_set_pin_output(C13);
}

void matrix_scan_user(void) {
    static uint32_t last_toggle = 0;

    if (get_highest_layer(layer_state) == 0) {
        gpio_write_pin_high(C13);
        last_toggle = timer_read32(); // so blinking restarts cleanly on layer change
        return;
    }

    if (timer_elapsed32(last_toggle) >= status_led_blink_ms()) {
        gpio_toggle_pin(C13);
        last_toggle = timer_read32();
    }
}
