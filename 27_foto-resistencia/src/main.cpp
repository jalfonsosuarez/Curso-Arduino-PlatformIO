#include <Arduino.h>

#define FOTO_RESISTOR 12
#define LED 2
#define LED_UMBRAL 15
#define UMBRAL 1900

int resistorValue;

void setup()
{
  Serial.begin(115200);
  pinMode(FOTO_RESISTOR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED_UMBRAL, OUTPUT);
  digitalWrite(LED, LOW);
  digitalWrite(LED_UMBRAL, LOW);
}

void loop()
{
  int resistorValue = analogRead(FOTO_RESISTOR);
  int ledValue = map(resistorValue, 0, 4096, 0, 255);
  if (resistorValue >= UMBRAL)
  {
    digitalWrite(LED_UMBRAL, HIGH);
  }
  else
  {
    digitalWrite(LED_UMBRAL, LOW);
  }
  analogWrite(LED, ledValue);
  Serial.println(resistorValue);
  delay(200);
}
