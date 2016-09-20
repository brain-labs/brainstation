/*
 * This is the source code of Brain Programming Language.
 * It is licensed under GNU GPL v. 3 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Brain, 2016.
 */

#ifndef BRAINSTATION_H
#define BRAINSTATION_H

// include types & constants of Wiring core API
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <LiquidCrystal.h>
#include <BrainDelegate.h>

/**
 * @brief Represents the Brain Station Console and also provide functions to be
 * used in the Arduino environment.
 */
class BrainStation : public BrainDelegate
{
public:
    BrainStation(LiquidCrystal *lcd, byte **sprites, int n_sprites);
    ~BrainStation() {}
    void update(Brain *brain);
private:
    byte **_sprites;
    LiquidCrystal *_lcd;
};

#endif // BRAINSTATION_H

