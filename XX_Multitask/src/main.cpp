#include <Arduino.h>

// Prueba Multitarea(Hilos)
TaskHandle_t Tarea0; // Tarea0 parpadeo LED 300 milisegundos
TaskHandle_t Tarea1; // Tarea1 parpadeo LED 1 Segundo

void loop0(void *parameter);
void loop1(void *parameter);

void setup()
{
  Serial.begin(115200);
  xTaskCreatePinnedToCore(loop0, "Tarea_0", 1000, NULL, 1, &Tarea0, 0); // Core 0
  xTaskCreatePinnedToCore(loop1, "Tarea_1", 1000, NULL, 1, &Tarea1, 1); // Core 0
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop0(void *parameter)
{ // Tarea1 parpadeo LED 300 milisegundos
  while (true)
  {
    digitalWrite(13, HIGH);
    delay(300);
    digitalWrite(13, LOW);
    delay(300);
  }
}

void loop1(void *parameter)
{ // Tarea1 parpadeo LED 1 Segundo
  while (true)
  {
    digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(12, LOW);
    delay(1000);
  }
}