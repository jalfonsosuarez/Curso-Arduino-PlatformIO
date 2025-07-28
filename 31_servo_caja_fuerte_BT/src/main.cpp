#include <Arduino.h>

#include <ESP32Servo.h>
#include <BluetoothSerial.h>

#define pinServo 15
#define ROJO 13
#define VERDE 14

Servo miServo;
BluetoothSerial serialBT;

String entrada = "";
String secreto = "1234";
bool primeraVez = true;

void setup()
{
  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);

  Serial.begin(115200);

  // BLUETOOTH
  serialBT.begin("Caja_Fuerte_Teo");

  // SERVO
  miServo.setPeriodHertz(50);
  miServo.attach(pinServo, 500, 2500);
  miServo.write(0);

  digitalWrite(ROJO, HIGH);
  digitalWrite(VERDE, LOW);
}

void loop()
{
  if (primeraVez)
  {
    serialBT.println("Introduzca la clave.");
    primeraVez = false;
  }

  if (serialBT.available())
  {
    entrada = serialBT.readStringUntil('\n');
    entrada.trim();
    if (entrada == secreto)
    {
      serialBT.println("Clave correcta");
      miServo.write(90);
      // Puerta abierta
      digitalWrite(ROJO, LOW);
      digitalWrite(VERDE, HIGH);
      delay(5000);

      serialBT.println("Puerta cerrada");
      digitalWrite(ROJO, HIGH);
      digitalWrite(VERDE, LOW);
      miServo.write(0);
    }
    else
    {
      serialBT.println("Clave incorrecta. Pruebe otra vez.");
    }
    serialBT.println("Introduzca la clave.");
  }
}
