#include <Keypad.h>
#include "LedControl.h"

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns

//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'f', '0', ' '}
};

byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 5, 4}; //connect to the column pinouts of the keypad

LedControl ledControl = LedControl(12, 10, 11, 1);
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


void setup() {
  //Инициируем MAX7219
  ledControl.shutdown(0, false); // включаем дисплей энергосбережение дисплей
  ledControl.setIntensity(0, 8); // устанавливаем яркость (0-минимум, 15-максимум)
  ledControl.clearDisplay(0);// очищаем дисплей
}

void loop() {
  
  for (int i = 0; i <= 3; i++){
    
    char customKey = customKeypad.getKey(); // считываем нажатую кдавишу
  
    if (customKey) {
      if (customKey == ' ') {
        ledControl.clearDisplay(0);
      }
      if(customKey == 'f') {
        ledControl.setChar(0, 0, 0, false);
        ledControl.setChar(0, 1, 0, false);
        ledControl.setChar(0, 2, 0, false);
        ledControl.setChar(0, 3, 0, false);
        delay(500);
        ledControl.setChar(0, 3, 1, false);
        delay(500);
        ledControl.setChar(0, 2, 1, false);
        delay(500);
        ledControl.setChar(0, 3, 0, false);
        delay(500);
        ledControl.setChar(0, 1, 1, false);
        delay(500);
        ledControl.setChar(0, 3, 1, false);
        delay(500);
        ledControl.setChar(0, 2, 0, false);
        delay(500);
        ledControl.setChar(0, 3, 0, false);
        delay(500);
        ledControl.setChar(0, 0, 1, false);
        delay(500);
        ledControl.setChar(0, 3, 1, false);
        delay(500);
        ledControl.clearDisplay(0);
        break;
      }
      ledControl.setChar(0, i, customKey, false);
    }
    else{
      i--;
    }
  }
}
