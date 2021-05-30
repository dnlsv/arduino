#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1);

void setup() {
  //Инициируем MAX7219
  lc.shutdown(0, false); // включаем дисплей энергосбережение дисплей
  lc.setIntensity(0, 8); // устанавливаем яркость (0-минимум, 15-максимум)
  lc.clearDisplay(0);// очищаем дисплей
}

void loop() {

  for(int i = 0; i <= 3; i++){
    for(int j = 1; j <= 7; j++){
      lc.setLed(0,i,j,true);
      delay(100);
    }
  }
  lc.clearDisplay(0);
  for(int i = 3; i >= 0; i--){
    for(int j = 7; j >= 1; j--){
      lc.setLed(0,i,j,true);
      delay(100);
    }
  }
  lc.clearDisplay(0);
}
