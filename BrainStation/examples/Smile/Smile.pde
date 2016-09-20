/* This is an example made for testing purposes of BrainStation.
 * It is licensed under GNU GPL v. 3 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Brain, 2016.
 */

#include <Brain.h>
#include <LiquidCrystal.h>
#include <BrainStation.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

Brain brain = Brain(&lcd, &Serial, NULL);

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

byte *sprites[] = {(byte*)smiley};

BrainStation brain_station = BrainStation(&lcd, sprites, 1);

void setup()
{
  Serial.begin(57600);
  lcd.begin(16, 2);
  lcd.noAutoscroll();
  brain_station.update(&brain);
}

void loop()
{
}

