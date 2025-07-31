#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

#include <DHT.h>

// Pin del DHT22 y del ventilador
#define DHTPIN 4
#define DHTTYPE DHT11
#define FAN_PIN 2

// Objeto DHT
DHT dht(DHTPIN, DHTTYPE);
const char *ssid = "Aula 1";
const char *pwd = "Horus.2025";

//* Conexion con MQTT
const char *mqtt_server = "192.168.0.25";
int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

const char *mqtt_topic_sub = "curso_arduino/#";
const char *mqtt_topic_temp = "curso_arduino/alfonso/temperatura";
const char *mqtt_topic_hum = "curso_arduino/alfonso/humedad";
const char *mqtt_topic_pub = "curso_arduino/alfonso";
const char *mqtt_client_id = "ESP_Alfonso";

void callback(char *topic, byte *pyload, unsigned int length);
void reconnect();

static unsigned long lastMsg = 0;
unsigned long now;

float temp = 0.0;
float hum = 0.0;
String msg;

char tempStr[8];
char humStr[8];

void setup()
{
  Serial.begin(115200);
  dht.begin();

  pinMode(FAN_PIN, OUTPUT);
  digitalWrite(FAN_PIN, LOW);

  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n");
  Serial.print("Conectado a: ");
  Serial.println(WiFi.localIP());

  // MQTT
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop()
{
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  dtostrf(temp, 1, 2, tempStr);
  dtostrf(hum, 1, 2, humStr);

  if (!client.connected())
  {
    reconnect();
  }
  client.loop();

  now = millis();
  if (now - lastMsg > 10000)
  {
    lastMsg = now;
    client.publish(mqtt_topic_temp, tempStr);
    client.publish(mqtt_topic_hum, humStr);
    Serial.println("Mensaje enviado");
  }
}

// Functions
void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Mensaje recibido en [");
  Serial.print(topic);
  Serial.print("]: ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect()
{
  while (!client.connected())
  {
    Serial.println("Reconectando ....");
    if (client.connect(mqtt_client_id))
    {
      Serial.println("Conectado a MQTT.");
      client.subscribe(mqtt_topic_sub);
    }
    else
    {
      Serial.println("Fallo en la conexión");
      Serial.println("Error : " + client.state());
      delay(5000);
    }
  }
}