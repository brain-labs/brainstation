/* This is the source code of Brain Programming Language.
 * It is licensed under GNU GPL v. 3 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Brain, 2016.
 */

#include <Brain.h>
#include "BrainStation.h"

BrainStation::BrainStation(LiquidCrystal *lcd, byte **sprites, int n_sprites)
{
    _sprites = sprites;
    _lcd = lcd;
    if (_lcd) {
        for (int i = 0; i < n_sprites; i++) {
            _lcd->createChar(i, sprites[i]);
        }
    }
}

void BrainStation::update(Brain *brain)
{
    _lcd->clear();
    delay(10);
    
    if (!isGameOver(brain)) {
        for (int i = 0, n_objects = brain->getValue(N_OBJECTS_CELL);
             i < n_objects;
             i++) {
            int cell_base = i * CTRL_CELLS;
            int s = brain->getValue(cell_base + NUM_SPRITE_BASE_CELL);
            int x = brain->getValue(cell_base + X_SPRITE_BASE_CELL);
            int y = brain->getValue(cell_base + Y_SPRITE_BASE_CELL);
            _lcd->setCursor(x, y);
            _lcd->write(byte(s));
        }
    } else {
        _lcd->setCursor(0, 0);
        _lcd->write("Game Over");    
    }
}

void BrainStation::handleEvents(Brain *brain, const char *input, int length)
{
    int i = 0;
    while (i <= length) {
        if (input[i++] == 'b' && input[i++] == 't') {
            char c = input[i++] - '0';
            if(c >= 0 && c <= 5) {
                brain->setValue(c, brain->getValue(c) + 1);
            } // else, btn will no be handled
        } else {
            return;
        }
    }
}

bool BrainStation::isGameOver(Brain *brain)
{
  return brain->getValue(IS_GAME_OVER_CELL) == GAME_OVER;
}
