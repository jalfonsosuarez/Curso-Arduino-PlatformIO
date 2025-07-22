#include <Arduino.h>

#define TRIGGER 13
#define ECHO 14
#define MAX_DIST 700
#define LED 15

float distance = 0.0;
float timeOut = MAX_DIST * 60;
int soundSpeed = 340;

int ledValue = 0;

float getSonar();

void setup()
{
  Serial.begin(115200);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  distance = getSonar();
  ledValue = map(distance, 4, 300, 255, 0);
  Serial.println("Distancia: " + String(distance) + " cm");

  analogWrite(LED, ledValue);

  delay(100);
}

float getSonar()
{
  unsigned long int pingTime = 0;
  float dist = 0.0;

  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  // pingTime = pulseIn(ECHO, HIGH, timeOut);
  // Serial.println("Ping time: " + String(pingTime));
  // dist = (float)pingTime * soundSpeed / 2 / 10000;
  // dist = pingTime;

  Serial.println("Ping time: " + String(pingTime));
  pingTime = pulseIn(ECHO, HIGH, timeOut);
  dist = pingTime / 59;

  return dist;
}