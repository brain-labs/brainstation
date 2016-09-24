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
#include <Stream.h>
#include <BrainDelegate.h>

#define GAME_OVER 1
#define CTRL_CELLS 5

#define KEY_LEFT_CELL 0
#define KEY_UP_CELL 1
#define KEY_RIGHT_CELL 2
#define KEY_DOWN_CELL 3
#define KEY_A_CELL 4
#define KEY_B_CELL 5
#define IS_GAME_OVER_CELL 6
#define N_OBJECTS_CELL 7
#define NUM_SPRITE_BASE_CELL 10
#define X_SPRITE_BASE_CELL 11
#define Y_SPRITE_BASE_CELL 12

/**
 * @brief Represents the Brain Station Console and also provide functions to be
 * used in the Arduino environment.
 */
class BrainStation : public BrainDelegate
{
public:
    BrainStation(LiquidCrystal *lcd, byte **sprites, int n_sprites);
    void update(Brain *brain);
    void handleEvents(Brain *brain, Stream *stream_in);
private:
    byte **_sprites;
    LiquidCrystal *_lcd;

    bool isGameOver(Brain *brain);
};

#endif // BRAINSTATION_H

