#include <LiquidCrystal.h>
#include "DHT.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define DHTPIN 6
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define DHTPIN2 7
DHT dht2(DHTPIN2, DHTTYPE);

const byte but = 8;
const byte but2 = 9;

void setup() {
  pinMode (but, INPUT);
  pinMode (but2, INPUT);
  
  dht.begin();
  dht2.begin();

  lcd.begin(16, 2);
}

void loop() {

  if(digitalRead (but) == LOW){
     int t = dht.readTemperature();
     lcd.setCursor(0, 0);
     lcd.print("Temperature:" + String (t) + char(223) + "C");
     delay (50);
  }
  if(digitalRead (but) == HIGH){
     int t2 = dht2.readTemperature();
     lcd.setCursor(0, 0);
     lcd.print("Temperature:" + String (t2) + char(223) + "C");
     delay (50);
  }
  if(digitalRead (but2) == HIGH){
     for(int i = 0; i < 16; i++){
        lcd.scrollDisplayRight();
        delay(100);
     }
     for(int i = 0; i < 16; i++){
        lcd.scrollDisplayLeft();
        delay(100);
     }
  }
  
}
