#include <Arduino.h>

#define SENSOR 4

void setup()
{
  Serial.begin(115200);
  pinMode(SENSOR, INPUT_PULLDOWN);
}

void loop()
{
  int lectura = touchRead(SENSOR);

  Serial.println(lectura);

  delay(500);
}
