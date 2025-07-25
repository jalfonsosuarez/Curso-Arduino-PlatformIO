#include <Arduino.h>
#include <BluetoothSerial.h>

#define LED 2

BluetoothSerial serialBT;

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(115200);
  serialBT.begin("BT_Alfonso");
  Serial.println("Dispositivo listo para emperejarse.");
}

void loop()
{
  // if (Serial.available() > 0)
  // {
  //   serialBT.write(Serial.read());
  // }

  if (serialBT.available())
  {
    String btRead = serialBT.readStringUntil('\n');
    btRead.trim();
    if (btRead == "LED_1")
    {
      digitalWrite(LED, HIGH);
    }
    if (btRead == "LED_0")
    {
      digitalWrite(LED, LOW);
    }
    Serial.println(btRead);
  }
}
