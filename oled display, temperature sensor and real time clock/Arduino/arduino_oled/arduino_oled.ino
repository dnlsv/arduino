#include <SPI.h>
#include <Wire.h>
#include <DS3231.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 8
#define TWO_WIRE_BUS 7
#define THREE_WIRE_BUS 6
#define TEMPERATURE_PRECISION 9

const byte but1 = 1;
const byte but2 = 2;

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors1(&oneWire);
DeviceAddress Thermometer1;

OneWire twoWire(TWO_WIRE_BUS);
DallasTemperature sensors2(&twoWire);
DeviceAddress Thermometer2;

OneWire threeWire(THREE_WIRE_BUS);
DallasTemperature sensors3(&threeWire);
DeviceAddress Thermometer3;

float temp1 = 0.0;
float temp2 = 0.0;
float temp3 = 0.0;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

DS3231 clock;
RTCDateTime dt;

void setup() {
  pinMode (but1, INPUT);
  pinMode (but2, INPUT);
  
  display.begin(SSD1306_SWITCHCAPVCC);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
  clock.begin();
  clock.setDateTime(2019, 2, 8, 10, 23, 00);

  sensors1.begin();
  sensors1.getAddress(Thermometer1, 0);
  sensors1.setResolution(Thermometer1, TEMPERATURE_PRECISION);

  sensors2.begin();
  sensors2.getAddress(Thermometer2, 0);
  sensors2.setResolution(Thermometer2, TEMPERATURE_PRECISION);

  sensors3.begin();
  sensors3.getAddress(Thermometer3, 0);
  sensors3.setResolution(Thermometer3, TEMPERATURE_PRECISION);

}


void loop() {
  display.clearDisplay();
  dt = clock.getDateTime();
  sensors1.requestTemperatures();
  temp1 = sensors1.getTempC(Thermometer1);

  display.setTextSize(2);
  display.setCursor(24, 20);
  display.print(dt.hour);
  display.print(":");
  display.print(dt.minute);
  display.print(":");
  display.print(dt.second);
  display.setTextSize(1); 
  display.setCursor(0, 54);
  display.print("Temp 1: " + String(temp1) + " ");
  display.print((char)247);
  display.display();
  
  if(digitalRead (but1) == HIGH){
    sensors1.requestTemperatures();
    temp1 = sensors1.getTempC(Thermometer1);
    sensors2.requestTemperatures();
    temp2 = sensors2.getTempC(Thermometer2);
    sensors3.requestTemperatures();
    temp3 = sensors3.getTempC(Thermometer3);
    
    display.clearDisplay();
    display.setTextSize(1);
    
    display.setCursor(20, 10);
    display.print("Temp 1: " + String(temp1) + " ");
    display.print((char)247);

    display.setCursor(20, 30);
    display.print("Temp 2: " + String(temp2) + " ");
    display.print((char)247);

    display.setCursor(20, 50);
    display.print("Temp 3: " + String(temp3) + " ");
    display.print((char)247);
    
    display.display();
    delay (2000);
  }

  if(digitalRead (but2) == HIGH){
    display.startscrollright(0x00, 0x0F);
  }
  else{
    display.stopscroll();
  }
  
}
