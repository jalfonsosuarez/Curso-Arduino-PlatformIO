#include <Arduino.h>
#include <ESP32Servo.h>

#define SERVOPIN 12

Servo miServo;

void setup()
{
  miServo.setPeriodHertz(50);
  miServo.attach(SERVOPIN, 500, 2500);
}

void loop()
{
  miServo.release();
  for (int i = 0; i <= 180; i++)
  {
    miServo.write(i);
    delay(200);
  }
  for (int i = 180; i >= 0; i--)
  {
    miServo.write(i);
    delay(200);
  }
}
