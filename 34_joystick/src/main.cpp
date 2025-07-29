#include <Arduino.h>

#define AXIS_X 13
#define AXIS_Y 12
#define SWITCH 14
#define LED_RIGHT 32
#define LED_LEFT 33
#define LED_UP 18
#define LED_DOWN 19

int readX = 0;
int readY = 0;
boolean readSwitch = false;

int cero_x = 1968;
int cero_y = 1977;

int leds[] = {0, LED_UP, LED_DOWN, LED_LEFT, LED_RIGHT};

void ledOn(int led);
void allLed(boolean status);

void setup()
{
  Serial.begin(115200);

  pinMode(AXIS_X, INPUT);
  pinMode(AXIS_Y, INPUT);
  pinMode(SWITCH, INPUT_PULLUP);

  pinMode(LED_RIGHT, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_UP, OUTPUT);
  pinMode(LED_DOWN, OUTPUT);

  allLed(false);
}

void loop()
{

  readX = analogRead(AXIS_X);
  readY = analogRead(AXIS_Y);
  readSwitch = digitalRead(SWITCH);

  allLed(false);

  if (readX - cero_x > 10)
  {
    ledOn(4);
  }

  if (readX - cero_x < -10)
  {
    ledOn(3);
  }

  if (readY - cero_y > 10)
  {
    ledOn(2);
  }

  if (readY - cero_y < -10)
  {
    ledOn(1);
  }

  if (readSwitch == 0)
  {
    ledOn(5);
  }
}

void ledOn(int led)
{
  allLed(false);

  if (led >= 1 && led <= 4)
  {
    digitalWrite(leds[led], HIGH);
  }

  if (led == 5)
  {
    allLed(true);
  }
}

void allLed(boolean status)
{
  digitalWrite(LED_UP, status);
  digitalWrite(LED_DOWN, status);
  digitalWrite(LED_LEFT, status);
  digitalWrite(LED_RIGHT, status);
}