/*
This program uses the sevseg library to display numbers on a multi-digit LED display
connected to the arduino. 
*/

#include <SevSeg.h>

SevSeg sevSeg;
byte segmentPins[] = { 5, 4, 2, 3, 6, 7, 8, 9}; // In order A, B, C, D, E, F, G, DP
byte digitPins[] = {13, 12, 11, 10}; // D4, D3, D2, D1 -- Reading left to right


void setup() {
  pinMode(5, OUTPUT); // A
  pinMode(4, OUTPUT); // B
  pinMode(2, OUTPUT); // C
  pinMode(3, OUTPUT); // D
  pinMode(6, OUTPUT); // E
  pinMode(7, OUTPUT); // F
  pinMode(8, OUTPUT); // G
  pinMode(9, OUTPUT); // DP
  pinMode(10, OUTPUT); // D1
  pinMode(11, OUTPUT); // D2
  pinMode(12, OUTPUT); // D3
  pinMode(13, OUTPUT); // D4

  byte numDigits = 4;

  bool resistorsOnSegments = true; // We have wired 1 Kohm resistors
  byte hardwareConfig = COMMON_CATHODE;
  bool updateWithDelays = false;
  bool leadingZeros = false;
  bool disableDecPoint = true;
  sevSeg.setBrightness(90);

  sevSeg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  Serial.begin(9600);

}

void loop() {
    //display1234();
    //counterLoop();
    //counterLoopReverse();
    counterLoopDisplay();
}

void display1234()
{
    sevSeg.setNumber(1234);
    sevSeg.refreshDisplay();
    delay(1000);
}

void counterLoop()
{
  for(int i = 0; i < 10000; i++)
  {
    sevSeg.setNumber(i);
    sevSeg.refreshDisplay();
    //delay(1000);
  }
}

void counterLoopReverse()
{
  for(int i = 9999; i > 0; i--)
  {
    sevSeg.setNumber(i);
    sevSeg.refreshDisplay();
    //delay(1000);
  }
}

void counterLoopDisplay()
{
  for(int d = 0; d < 4; d++)
  {
    digitalWrite(digitPins[d], LOW);

    for(int i = 0; i < 8; i++)
    {
      digitalWrite(i, HIGH);
      delay(100);
    }

    sevSeg.refreshDisplay();
  }
}
