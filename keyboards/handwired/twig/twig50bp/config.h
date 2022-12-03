// Copyright 2022 Takeshi Noda (nodatk@gmail.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#ifdef AUDIO_ENABLE
  #define AUDIO_PIN A10
  #define AUDIO_PIN_ALT A11
  #define AUDIO_PIN_ALT_AS_NEGATIVE
  #define STARTUP_SONG SONG(STARTUP_SOUND)
  #define AUDIO_INIT_DELAY
#endif
