/* This is the source code of Brain Programming Language.
 * It is licensed under GNU GPL v. 3 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Brain, 2016.
 */

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
    _lcd->write(byte(0));
}
