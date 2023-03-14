#include "LedControl.h"

LedControl ledControl = LedControl(12, 10, 11, 1);

void setup() {
  //Инициируем MAX7219
  ledControl.shutdown(0, false); // включаем дисплей энергосбережение дисплей
  ledControl.setIntensity(0, 8); // устанавливаем яркость (0-минимум, 15-максимум)
  ledControl.clearDisplay(0);// очищаем дисплей
}

void loop() {

  for(int i = 0; i <= 3; i++){
    for(int j = 1; j <= 7; j++){
      ledControl.setLed(0,i,j,true);
      delay(100);
    }
  }
  ledControl.clearDisplay(0);
  for(int i = 3; i >= 0; i--){
    for(int j = 7; j >= 1; j--){
      ledControl.setLed(0,i,j,true);
      delay(100);
    }
  }
  ledControl.clearDisplay(0);
}
