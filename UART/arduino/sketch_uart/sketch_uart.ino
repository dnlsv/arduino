int led_pin = 7;
byte incomingByte;

void setup() {
  pinMode(led_pin, OUTPUT); 
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    if (incomingByte == '1') {
     tone(led_pin, 1000);
    }
    else if (incomingByte == '0') {
      noTone(led_pin);
    }
  }
  delay(10);
}
