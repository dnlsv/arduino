#include <LedControl.h>

int DIN = 12;
int LOAD =  10;
int CLK = 11;

int dev_count = 4;
LedControl lc = LedControl(DIN, CLK, LOAD, dev_count);

byte D[8] = {B00000000, B00011000, B00100100, B00100100, B01111110, B01000010, B00000000, B00000000};
byte E[8] = {B00000000, B00111100, B00100000, B00111100, B00100000, B00111100, B00000000, B00000000};
byte N[8] = {B00000000, B00100100, B00100100, B00111100, B00100100, B00100100, B00000000, B00000000};
byte I[8] = {B00000000, B00100010, B00100110, B00101010, B00110010, B00100010, B00000000, B00000000};
byte S[8] = {B00000000, B00111100, B00100000, B00100000, B00100000, B00111100, B00000000, B00000000};  

void setup() {
  for (byte i = 0; i < dev_count; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 15);
    lc.clearDisplay(i);
  }
}

void loop() {
    for (byte i = 0; i < dev_count; i++) {
        lc.clearDisplay(i);
    }
  printText();
}

void printText()
{
  printByte(D, 0);
  delay(1000);
  printByte(E, 1);
  delay(1000);
  printByte(N, 2);
  delay(1000);
  printByte(I, 3);
  delay(1000);
  printByte(S, 0);
  printByte(S, 1);
  printByte(S, 2);
  printByte(S, 3);
  delay(1000);
}

void printByte(byte character [], byte addr)
{
  for (byte i = 0; i < 8; i++) lc.setRow(addr, i, character[i]);
}
