const byte led1 = 1;
const byte led2 = 2;
const byte led3 = 3;
const byte but = 7;

void setup() {
pinMode (led1, OUTPUT);
pinMode (led2, OUTPUT);
pinMode (led3, OUTPUT);
pinMode (but, INPUT);
}

void loop() {
if (digitalRead (but) == HIGH)
{
  digitalWrite (led1, HIGH);
  delay(1000);
  digitalWrite (led2, HIGH);
  delay(1000);
  digitalWrite (led3, HIGH);
}
else {
  digitalWrite (led3, LOW);
  delay(1000);
  digitalWrite (led2, LOW);
  delay(1000);
  digitalWrite (led1, LOW);
}
}
