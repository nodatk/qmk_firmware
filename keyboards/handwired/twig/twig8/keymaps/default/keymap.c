// Copyright 2022 Takeshi Noda (nodatk@gmail.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Layer 0, Base layer
  LAYOUT_orth_2x4(
    KC_Q,    KC_W,    KC_E,    KC_R,
    KC_A,    KC_S,    KC_D,    KC_F
  )
};
