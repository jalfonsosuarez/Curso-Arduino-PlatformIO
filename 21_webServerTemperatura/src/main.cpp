#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>
#include <ArduinoJson.h>
#define LED 2

#define DHTPIN 13
#define DHTTYPE DHT22

const char *ssid = "Aula 1";
const char *pwd = "Horus.2025";

String ledStatus = "off"; // estado del led

DHT dhtSensor(DHTPIN, DHTTYPE);
float temperature;
float humidity;

String homePage = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Document</title></head><body><h1>Hola mundo</h1><h2>Esta es la página home</h2><hr><a href=\"/firstPage\">Ir a la primera página.</a></body></html>";
String firstPage = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><title>Document</title></head><body><h2>Esta es la primera página</h2><hr></body></html>";

WebServer server(80);

// --------------
// void homePage();
// void firstPage();
void ledON();
void ledOFF();
void readTemperature();
// --------------

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  Serial.begin(115200);
  dhtSensor.begin();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n");
  Serial.print("Conectado a: ");
  Serial.println(WiFi.localIP());

  // server.on("/", homePage);
  // server.on("/firstPage", firstPage);
  server.on("/led_ON", ledON);
  server.on("/led_OFF", ledOFF);
  server.on("/temperature", readTemperature);

  server.begin(); // Inicia el servidor
  Serial.println("Servidor iniciado");
}

void loop()
{
  server.handleClient();
}

// void homePage()
// {
//   // server.send(200, "text/html", homePage);
// }

// void firstPage()
// {
//   // server.send(200, "text/html", firstPage);
// }

void ledON()
{
  digitalWrite(LED, HIGH);
  ledStatus = "on";
  server.send(200, "text/html", "Led ON");
}

void ledOFF()
{
  digitalWrite(LED, LOW);
  ledStatus = "off";
  server.send(200, "text/html", "Led OFF");
}

void readTemperature()
{
  temperature = dhtSensor.readTemperature();
  humidity = dhtSensor.readHumidity();
  // String html = "<h1>La temperatura es: " + String(temperature) + "&ordm; " + "y la humedad es: " + String(humidity) + "%</h1>";
  // server.send(200, "text/html", html);

  // Genera un json y lo envía
  JsonDocument doc;
  doc["temperature"] = temperature;
  doc["humidity"] = humidity;
  String outDoc;
  serializeJson(doc, outDoc);
  server.send(200, "text/json", outDoc);
}