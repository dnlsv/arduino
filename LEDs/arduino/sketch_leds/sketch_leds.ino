const byte led_1 = 11;
const byte led_2 = 12;
const byte led_3 = 13;
const byte button = 2;

void setup() {
  pinMode (led_1, OUTPUT);
  pinMode (led_2, OUTPUT);
  pinMode (led_3, OUTPUT);
  pinMode (button, INPUT);
}

void loop() {
  if (digitalRead (button) == HIGH)
  {
    digitalWrite (led_1, HIGH);
    delay(1000);
    digitalWrite (led_2, HIGH);
    delay(1000);
    digitalWrite (led_3, HIGH);
  }
  else {
    digitalWrite (led_3, LOW);
    delay(1000);
    digitalWrite (led_2, LOW);
    delay(1000);
    digitalWrite (led_1, LOW);
  }
}
