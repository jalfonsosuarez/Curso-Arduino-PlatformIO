#include <Arduino.h>
#include <ESP32Servo.h>

#define SERVOPIN 27

Servo miServo;

String entrada = "";
String secreto = "1234";

void limpiar();

void setup()
{
  Serial.begin(115200);
  miServo.setPeriodHertz(50);
  miServo.attach(SERVOPIN, 500, 2500);
  miServo.write(0);
}

void loop()
{
  if (Serial.available() > 0)
  {
    entrada = Serial.readStringUntil('\n');
    entrada.trim();
    if (entrada == secreto)
    {
      Serial.println("Clave correcta");
      miServo.write(90);
      delay(5000);
      miServo.write(0);
    }
    else
    {
      Serial.print("Clave no es correcta. Intente de nuevo");
    }
    limpiar();
  }
}

void limpiar()
{
  Serial.print("\u001b[2J"); // Borra la pantalla
  Serial.print("\u001b[H");  // Mueve el cursor a la esquina superior izquierda
}