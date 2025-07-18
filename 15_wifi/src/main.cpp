#include <Arduino.h>
#include <WiFi.h>

const char *ssid = "Aula 1";
const char *pwd = "Horus.2025";

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n");
  Serial.print("Conectado a: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  // put your main code here, to run repeatedly:
  int redes = WiFi.scanNetworks();
  Serial.println(redes);
  for (int i = 0; i < redes; i++)
  {
    Serial.print(WiFi.RSSI(i));
    Serial.print("\t");
    Serial.print(WiFi.channel(i));
    Serial.print("\t");
    Serial.println(WiFi.SSID(i).c_str());
  }

  delay(10000);
}
