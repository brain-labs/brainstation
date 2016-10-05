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

#define GAME_OVER 1
#define CTRL_CELLS 8

// keys 0 through 7 are pre-defined control cells
#define KEY_LEFT_CELL 0
#define KEY_UP_CELL 1
#define KEY_RIGHT_CELL 2
#define KEY_DOWN_CELL 3
#define KEY_A_CELL 4
#define KEY_B_CELL 5
#define IS_GAME_OVER_CELL 6
#define N_OBJECTS_CELL 7
// the cells 8 through 35 are for custom controls

// the cells 36 through 43 are reserved for the object 1,
// the cells 44 through 51 are reserved for the object 2
// and so on (we can have up to 8 objects as the LCD has only 8 chars)
// and Brainduino has only 100 cells.

#define NUM_SPRITE_BASE_CELL 41
#define X_SPRITE_BASE_CELL 42
#define Y_SPRITE_BASE_CELL 43

/**
 * @brief Represents the Brain Station Console and also provide functions to be
 * used in the Arduino environment.
 */
class BrainStation : public BrainDelegate
{
public:
    BrainStation(LiquidCrystal *lcd, byte **sprites, int n_sprites);
    void update(Brain *brain);
    void handleEvents(Brain *brain, const char *input, int length);
private:
    byte **_sprites;
    LiquidCrystal *_lcd;

    bool isGameOver(Brain *brain);
};

#endif // BRAINSTATION_H

