int pin_11 = 11;
int pin_12 = 12;
int pin_13 = 13;
volatile int state = LOW;
 
void setup()
{
  pinMode(pin_13, OUTPUT);
  pinMode(pin_12, OUTPUT);
  pinMode(pin_11, OUTPUT);

  Serial.begin(9600);  // запускаем монитор порта
  
  attachInterrupt(0, blink, RISING);
}
 
void loop()
{
  
}
 
void blink()
{
  state = !state;
  digitalWrite(pin_11, state);
  digitalWrite(pin_12, state);
  digitalWrite(pin_13, state);
}
