#include <Arduino.h>
#include <DHT.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define DHTPIN 13
#define DHTTYPE DHT22

WiFiClient wifiClient;
HTTPClient httpClient;

const char *ssid = "Aula 1";
const char *pwd = "Horus.2025";
const char *httpServer = "192.168.0.25:5000/datos";

float temperature;
float humidity;

DHT dhtSensor(DHTPIN, DHTTYPE);

void wifiConnection();
void postData(float temperature, float humidity, String personName);

void setup()
{
  Serial.begin(115200);
  wifiConnection();
  dhtSensor.begin();
  // Serial.println("----- \t-----");
  // Serial.println("Temp \tHum");
  // Serial.println("----- \t-----");
}

void loop()
{
  temperature = dhtSensor.readTemperature();
  humidity = dhtSensor.readHumidity();

  // Serial.println(String(temperature) + "\t" + String(humidity));
  postData(temperature, humidity, "José Alfonso");

  delay(5000);
}

void wifiConnection()
{
  WiFi.begin(ssid, pwd);
  Serial.println("----------------------- WIFI CONNECTION ------------------");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n");
  Serial.print("Conectado a: ");
  Serial.println(WiFi.localIP());
  Serial.println("----------------------------------------------------------");
  delay(500);
  Serial.print("\n");
}

void postData(float temperature, float humidity, String personName)
{
  String params = "temp=" + String(temperature);
  params += "&hum=" + String(humidity);
  params += "&persona=" + personName;

  int httpCode;
  String payload;

  if (WiFi.status() == WL_CONNECTED)
  {
    String url = "http://" + String(httpServer);
    httpClient.begin(wifiClient, url);
    httpClient.addHeader("Content-Type", "application/x-www-form-urlencoded");
    httpCode = httpClient.POST(params);
    payload = httpClient.getString();

    Serial.println("Respuesta del servidor: " + String(httpCode));
    if (httpCode != 200)
    {
      Serial.println("Payload: " + payload);
    }
  }
}