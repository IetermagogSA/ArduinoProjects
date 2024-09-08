/*
This program uses the sevseg library to display numbers on a single-digit LED display
connected to the arduino
*/

#include <SevSeg.h>

SevSeg sevSeg;

void setup() {
  byte numDigits = 1;
  byte digitPins[] = {}; // Not applicable to single-digit displays
  byte segmentPins[] = { 5, 4, 3, 10, 11, 12, 13, 2}; // In order A, B, C, D, E, F, G, DP
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
  for(int i = 0; i < 10; i++)
  {
    sevSeg.setNumber(i);
    delay(1000);
    sevSeg.refreshDisplay();
  }
}
