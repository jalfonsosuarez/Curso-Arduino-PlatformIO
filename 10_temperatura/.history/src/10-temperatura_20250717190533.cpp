#include <DHT.h>

#define DHTPIN 13
#define DHTTYPE DHT11
#define LED 12

DHT dht(DHTPIN, DHTTYPE);

float temp;
float hum; 

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  dht.begin();

}

void loop() {
  digitalWrite(LED, HIGH);
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println("\t Humedad: " + String(hum));

  digitalWrite(LED, LOW);
  
  delay(1000);

}
