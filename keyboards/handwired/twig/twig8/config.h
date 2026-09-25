// Copyright 2022 Takeshi Noda (nodatk@gmail.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// This board's USB circuit (like Bonsai C4 itself) does not wire PA9 to
// VBUS, so the OTG_FS peripheral's VBUS-sensing comparator would otherwise
// see a permanently floating/low pin and conclude no cable is ever
// connected -- silently skipping the D+ pull-up/enumeration handshake
// forever, even though the device is physically plugged in and the ROM
// DFU bootloader (which does not use VBUS sensing) enumerates fine.
#define BOARD_OTG_NOVBUSSENS 1

#ifdef AUDIO_ENABLE
  #define AUDIO_PIN A0
  #define AUDIO_PIN_ALT B3
  #define AUDIO_PIN_ALT_AS_NEGATIVE
  #define STARTUP_SONG SONG(STARTUP_SOUND)
  #define AUDIO_INIT_DELAY
#endif
