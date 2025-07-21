#include <Arduino.h>
#include <WiFi.h>

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(); // desconecta de cualquier red anterior
  delay(100);

  Serial.println("Escaneando redes...");
  int numRedes = WiFi.scanNetworks();

  if (numRedes == 0)
  {
    Serial.println("No se encontraron redes.");
  }
  else
  {
    Serial.printf("Se encontraron %d redes:\n", numRedes);
    for (int i = 0; i < numRedes; i++)
    {
      Serial.printf("%d: %s (%ddBm) - Seguridad: ", i + 1, WiFi.SSID(i).c_str(), WiFi.RSSI(i));
      wifi_auth_mode_t tipoAuth = WiFi.encryptionType(i);
      switch (tipoAuth)
      {
      case WIFI_AUTH_OPEN:
        Serial.println("Abierta (sin protección)");
        break;
      case WIFI_AUTH_WEP:
        Serial.println("WEP (obsoleta)");
        break;
      case WIFI_AUTH_WPA_PSK:
        Serial.println("WPA");
        break;
      case WIFI_AUTH_WPA2_PSK:
        Serial.println("WPA2");
        break;
      case WIFI_AUTH_WPA_WPA2_PSK:
        Serial.println("WPA/WPA2");
        break;
      case WIFI_AUTH_WPA2_ENTERPRISE:
        Serial.println("WPA2-Enterprise");
        break;
      case WIFI_AUTH_WPA3_PSK:
        Serial.println("WPA3");
        break;
      default:
        Serial.println("Desconocido");
        break;
      }
    }
  }
}

void loop()
{
  // no hace falta nada en el loop
}
