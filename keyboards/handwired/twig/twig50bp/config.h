// Copyright 2022 Takeshi Noda (nodatk@gmail.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { A9, A10, A11, A12 }
#define MATRIX_COL_PINS { B1, B0, A7, A6, A5, A4, A3, A2, A1, A0, B3, B4, B5, B6 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 8
#define TAPPING_TERM 150

#define FORCE_NKRO
