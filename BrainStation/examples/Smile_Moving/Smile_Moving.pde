/* This is the source code of Brain Programming Language.
 * It is licensed under GNU GPL v. 3 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Brain, 2016.
 */

#include <Brain.h>
#include <LiquidCrystal.h>
#include <BrainStation.h>

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

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
BrainStation brain_station = BrainStation(&lcd, sprites, 1);
Brain brain = Brain(&lcd, &Serial, &brain_station);

void setup()
{
  Serial.begin(57600);
  lcd.begin(16, 2);
  lcd.noAutoscroll();
  brain.set_code(">>>>>>>?:++;>>>>+>>>>>>?:+;");
}

void loop()
{
  brain.run();
  delay(200);
}

