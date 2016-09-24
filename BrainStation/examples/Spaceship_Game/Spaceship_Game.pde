/* This is the source code of Brain Programming Language.
 * It is licensed under GNU GPL v. 3 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Brain, 2016.
 */

#include <Brain.h>
#include <LiquidCrystal.h>
#include <BrainStation.h>

byte spaceship1[8] = {
  0b10000,
  0b11000,
  0b11100,
  0b11000,
  0b10000,
  0b00000,
  0b00000,
  0b00000
};

byte spaceship2[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b10000,
  0b11000,
  0b11100,
  0b11000,
  0b10000
};

byte shipmonster1[8] = {
  0b00001,
  0b00110,
  0b11110,
  0b00110,
  0b00001,
  0b00000,
  0b00000,
  0b00000
};

byte shipmonster2[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00001,
  0b00110,
  0b11110,
  0b00110,
  0b00001
};

byte laser1[8] = {
  0b00000,
  0b00000,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte laser2[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00111,
  0b00000,
  0b00000
};

byte *sprites[] = {
  (byte*)spaceship1,
  (byte*)spaceship2,
  (byte*)shipmonster1,
  (byte*)shipmonster2,
  (byte*)laser1,
  (byte*)laser2,
};

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
BrainStation brain_station = BrainStation(&lcd, sprites, 6);
Brain brain = Brain(&lcd, &Serial, &brain_station);

void setup()
{
  Serial.begin(57600);
  lcd.begin(16, 2);
  lcd.noAutoscroll();
  /*
    >>>>>>>?:+;<<<<<<< create one object

    check if the user pressed the ARROW UP
    >?->>>>>>>->>-<<<<<<<:>>; go to ARROW DOWN cell
    ?->>>>>+>>+:>>>>>>>;
    
    <?:++; put number 2 as control on 9th cell
    >% get sprite
    
    +?-:+; if 10th cell equals to minus 1 then is equal to sprite 1
    <<+?-:+++; if 10th equals to minus 1 then is equal to 3
    
    >>>>[-] clean 12th cell
    <<<<  go to the 8th cell
    --? check if cell is equal to 2
     -? check if cell is equal to 3
       -? check if cell is equal to 4
             ++++ add 4 if cell is not equal to 4
        : do nothing if cell is equal to 4
        ;
      : if cell is equal to 3
        +++>>>>+<<<< 
      ;
    :  if cell equal to 2 add 1
    ++>>>>+<<<<
    ;
  */
  brain.setCode(">>>>>>>?:+;<<<<<<?->>>>>>>->>-<<<<<<<:>>;?->>>>>+>>+:>>>>>>>;<?:++;>%+?-:+;<<+?-:+++;>>>>[-]<<<<--?-?-?++++;:+++>>>>+<<<<;:++>>>>+<<<<;");
}

void loop()
{
  // debug for checking the value of the cells
  //Serial.print(brain.getValue(KEY_LEFT_CELL));
  //Serial.print(brain.getValue(8));
  brain_station.handleEvents(&brain, &Serial);
  brain.run();
  delay(200);
}

