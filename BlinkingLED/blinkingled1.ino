/*
 This code will make an LED blink
*/

const int LEDPIN = 3;

void setup()
{
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
}

void loop()
{
  int ledPinState = digitalRead(LEDPIN);
  
  if(ledPinState == HIGH)
    digitalWrite(LEDPIN, LOW);
  else
    digitalWrite(LEDPIN, HIGH);
  
  delay(1000);
}