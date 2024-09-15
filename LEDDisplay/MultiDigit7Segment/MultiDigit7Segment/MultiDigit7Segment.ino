/*
This program uses the sevseg library to display numbers on a multi-digit LED display
connected to the arduino. 
*/

#include <SevSeg.h>

SevSeg sevSeg;
int pinA = 5, pinB = 4, pinC = 2, pinD = 3, pinE = 6, pinF = 7, pinG = 8, pinDP = 9; 
int dp1 = 10, dp2 = 11, dp3 = 12, dp4 = 13;
byte segmentPins[] = { pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP}; // In order A, B, C, D, E, F, G, DP
byte digitPins[] = {dp4, dp3, dp2, dp1}; // D4, D3, D2, D1 -- Reading left to right
bool updateWithDelays = false;


void setup() {
  pinMode(pinA, OUTPUT); // A
  pinMode(pinB, OUTPUT); // B
  pinMode(pinC, OUTPUT); // C
  pinMode(pinD, OUTPUT); // D
  pinMode(pinE, OUTPUT); // E
  pinMode(pinF, OUTPUT); // F
  pinMode(pinG, OUTPUT); // G
  pinMode(pinDP, OUTPUT); // DP
  pinMode(dp1, OUTPUT); // D1
  pinMode(dp2, OUTPUT); // D2
  pinMode(dp3, OUTPUT); // D3
  pinMode(dp4, OUTPUT); // D4

  byte numDigits = 4;

  bool resistorsOnSegments = true; // We have wired 1 Kohm resistors
  byte hardwareConfig = COMMON_CATHODE;
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
    //counterLoopSegments();
    counterLoopSegmentsDisplayNum();
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
    updateWithDelays = true;
  }
}

void counterLoopReverse()
{
  for(int i = 9999; i > 0; i--)
  {
    sevSeg.setNumber(i);
    sevSeg.refreshDisplay();
    updateWithDelays = true;
  }
}

void counterLoopSegments()
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

void counterLoopSegmentsDisplayNum()
{
  for(int d = 0; d < 4; d++)
  {
    clearScreen(false);

    digitalWrite(digitPins[d], LOW);

    // Display a number
    for(int num = 0; num < 10; num++)
    {
      lightSegments();
      displayNum(num);
      clearScreen(true);
      //lightSegments();
    }
  }

    clearScreen(false);
}

void lightSegments()
{
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(i, HIGH);
    delay(100);
  }

  clearScreen(true);
}

void clearScreen(bool clearSegmentsOnly)
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  digitalWrite(pinDP, LOW);

  if(!clearSegmentsOnly)
  {
    digitalWrite(dp1, HIGH);
    digitalWrite(dp2, HIGH);
    digitalWrite(dp3, HIGH);
    digitalWrite(dp4, HIGH);
  }
}

void displayNum(int num)
{
  switch(num)
  {
    case 0:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      digitalWrite(pinDP, LOW);
      delay(1000);
      break;
    case 1:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      digitalWrite(pinDP, LOW);
      delay(1000);
      break;
    case 2:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, LOW);
      delay(1000);
      break;
    case 3:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, LOW);
      delay(1000);
      break;
    case 4:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, LOW);
      delay(1000);
      break;
    case 5:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, LOW);
      delay(1000);
      break;
    case 6:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, LOW);
      delay(1000);
      break;
    case 7:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      digitalWrite(pinDP, LOW);
      delay(1000);
      break;
    case 8:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, LOW);
      delay(1000);
      break;
    case 9:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinDP, LOW);
      delay(1000);
      break;
    default:
      clearScreen(false);
      delay(1000);
      break;
  }
}
