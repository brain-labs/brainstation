* This is the source code of Brain Programming Language.
 * It is licensed under GNU GPL v. 3 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Brain, 2016.
 */

#include <SPI.h>
#include <EEPROM.h>
#include <boards.h>
#include <RBL_nRF8001.h>
#include <Brain.h>
#include <BrainStation.h>
#include <LiquidCrystal.h>

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

byte *sprites[] = {
  (byte*)spaceship1,
  (byte*)spaceship2,
};

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
BrainStation brain_station = BrainStation(&lcd, sprites, 2);
Brain brain = Brain(&lcd, &Serial, &brain_station, analogRead(0));

void setup()
{    
  // Set your BLE Shield name here, max. length 10
  //ble_set_name("My Name");
  
  ble_begin();
  
  // Enable serial debug
  Serial.begin(57600);

  lcd.begin(16, 2);
  lcd.noAutoscroll();
  brain.setCode(">>>>>>>?:+;<<<<<<?->>>>>>>->>-<<<<<<<:>>;?->>>>>+>>+:>>>>>>>;<?:++;>%+?-:+;<<+?-:+++;>>>>[-]<<<<--?-?-?++++;:+++>>>>+<<<<;:++>>>>+<<<<;");
}

void loop()
{
  while (ble_available()) {
      char str[3];
      for (int i = 0; i < 3; i++) {
          str[i] = ble_read();
      }
      
      brain_station.handleEvents(&brain, str, 3);
  }
  
  brain.run();
  ble_do_events();
  delay(200);
}
