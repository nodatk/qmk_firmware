// Copyright 2022 Takeshi Noda (nodatk@gmail.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { B9, B6, A4, B8 }
#define MATRIX_COL_PINS { A7, A6, A5, A1, B13, B14, B15, B1, C14, C15, A3, B10, A8, B0}

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 8
#define TAPPING_TERM 150

#define FORCE_NKRO

#ifdef AUDIO_ENABLE
  #define AUDIO_PIN A0
  #define AUDIO_PIN_ALT B3
  #define AUDIO_PIN_ALT_AS_NEGATIVE
  #define STARTUP_SONG SONG(STARTUP_SOUND)
  #define AUDIO_INIT_DELAY
#endif
