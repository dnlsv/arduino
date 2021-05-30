int ledPin = 7;
byte incomingByte;

void setup() {
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    incomingByte = Serial.read();

    if (incomingByte == '1') {
     tone(ledPin, 1000);
    }
    else if (incomingByte == '0') {
      noTone(ledPin);
    }
  }
  delay(10);
}
