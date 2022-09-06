#include <Arduino.h>
#include "../lib/LibNextion/LibNextion.h"

/*Page 2*/
const int P_4 = 4;
const int P_2 = 2;
// char myTail[3] = {0xFF, 0xFF, 0xFF};
// char buffer[30] = {0};

void setActiveP2()
{
    sendCommand("tp2.txt=\"ACTIVE\"");
    sendCommand("tp2.bco=63488");
}

void setInactiveP2()
{
    sendCommand("tp2.txt=\"INACTIVE\"");
    sendCommand("tp2.bco=2016");
}

void checkStatusP2() {
  if(digitalRead(P_2) == HIGH) {
    setInactiveP2();
  } else {
    setActiveP2();
  }
}

void setup() {
  nexSerial.begin(9600);
  Serial.begin(9600);

  pinMode(P_2, INPUT);
  attachInterrupt(digitalPinToInterrupt(P_2), checkStatusP2, CHANGE);

}

void loop() {
  // put your main code here, to run repeatedly:
}