#include <Arduino.h>

#define TRIGGER 13
#define ECHO 14
#define MAX_DIST 700
#define LED 15
#define BUZZER 12

float distance = 0.0;
float timeOut = MAX_DIST * 60;
int soundSpeed = 340;

int ledValue = 0;

int intervals[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

float getSonar();
int getInterval(float dist);
void buzz(int freq);

void setup()
{
  Serial.begin(115200);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop()
{
  distance = getSonar();

  int buzzType = getInterval(distance);

  if (buzzType < 1000)
  {
    buzz(buzzType);
  }

  ledValue = map(distance, 4, 300, 255, 0);
  Serial.println("Distancia: " + String(distance) + " cm");

  analogWrite(LED, ledValue);

  delay(500);
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

int getInterval(float dist)
{
  int out = 1000;

  for (int i = 0; i < 10; i++)
  {
    if (dist < intervals[i])
    {
      out = intervals[i];
      break;
    }
  }

  return out;
}

void buzz(int freq)
{
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(10 * freq);
  }
  return;
}