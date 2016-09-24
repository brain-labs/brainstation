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
    if (!isGameOver(brain)) {
        _lcd->clear();
        delay(10);

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
    }
}

void BrainStation::handleEvents(Brain *brain, Stream *stream_in)
{
    while (stream_in->available()) {
        if (stream_in->read() == 'b' && stream_in->read() == 't') {
            char c = stream_in->read() - '0';
            Serial.print((int)c);
            if (c >= 0 && c <= 5) {
                brain->setValue(c, brain->getValue(c) + 1);
            } // else, btn will not be handled 
        } else {
            // clear input if it comes garbage
            stream_in->flush();
        }
    }
}

bool BrainStation::isGameOver(Brain *brain)
{
  return brain->getValue(IS_GAME_OVER_CELL) == GAME_OVER;
}
