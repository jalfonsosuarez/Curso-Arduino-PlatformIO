#include <Arduino.h>

// Prueba Multitarea(Hilos)
// https://docs.espressif.com/projects/esp-idf/en/v4.3/esp32/search.html?q=TaskHandle_t&check_keywords=yes&area=default
TaskHandle_t Tarea0; // Tarea0 parpadeo LED 300 milisegundos
TaskHandle_t Tarea1; // Tarea1 parpadeo LED 1 Segundo

void loop0(void *parameter);
void loop1(void *parameter);

void setup()
{
  Serial.begin(115200);
  /*
  https://docs.espressif.com/projects/esp-idf/en/v4.3/esp32/api-reference/system/freertos.html
  xTaskCreatePinnedToCore arguments:
    pvTaskCode .....: A pointer to the task's function (the code that the task will execute).
    pcName .........: A descriptive name for the task (useful for debugging).
    usStackDepth ...: The size of the task's stack memory (in words).
    pvParameters ...: A pointer to parameters that will be passed to the task function.
    uxPriority .....: The priority of the task (higher numbers mean higher priority).
    pvCreatedTask ..: A pointer to a variable where the handle of the created task will be stored.
    xCoreID ........: The core ID to which the task is pinned (0 or 1 for ESP32).
  */
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

void loop()
{
}