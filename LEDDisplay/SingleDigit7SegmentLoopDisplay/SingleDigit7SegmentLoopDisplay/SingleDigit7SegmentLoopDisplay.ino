/*
This program uses the sevseg library to display numbers on a single-digit LED display
connected to the arduino. It will light up the display for a random amount of times and then display the next number
*/

#include <SevSeg.h>

SevSeg sevSeg;
  byte segmentPins[] = { 5, 4, 3, 10, 11, 12, 13, 2}; // In order A, B, C, D, E, F, G, DP


void setup() {
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);

  byte numDigits = 1;
  byte digitPins[] = {}; // Not applicable to single-digit displays
  bool resistorsOnSegments = true; // We have wired 220 ohm resistors
  byte hardwareConfig = COMMON_CATHODE;
  bool updateWithDelays = false;
  bool leadingZeros = false;
  bool disableDecPoint = true;
  sevSeg.setBrightness(90);

  sevSeg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  Serial.begin(9600);

}

void loop() {

  for(int j = 0; j < 10; j++)
  {
    for(int i = 0; i < 7; i++)
    {
      if(segmentPins[i] != 13)
      {
        digitalWrite(segmentPins[i], HIGH);
        delay(100);
      }
    }

    for(int i = 0; i < 7; i++)
    {
      if(segmentPins[i] != 13)
      {
        digitalWrite(segmentPins[i], LOW);
        delay(100);
      }
    }

    sevSeg.setNumber(j);
    sevSeg.refreshDisplay();
    delay(1000);
    sevSeg.blank();
  }
}
