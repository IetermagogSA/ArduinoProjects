/*
 The code below will use a button to 
 toggle an LED light on or off
*/

const int LEDPIN = 3;
const int BTNPIN = 2;

int btnState = 0;
int previousBtnState = 0;
int btnPushCount = 0;

void setup()
{
  pinMode(BTNPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  btnState = digitalRead(BTNPIN);
  
  if(btnState != previousBtnState)
  {
    btnPushCount++;  
    Serial.print("Button Pressed.");
    Serial.println(btnPushCount);
  }
  
  if(btnPushCount % 2 == 0)
    digitalWrite(LEDPIN, HIGH);
  else
    digitalWrite(LEDPIN, LOW);
  
  delay(100);
}