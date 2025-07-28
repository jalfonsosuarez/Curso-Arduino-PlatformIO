#include <Arduino.h>
// https://descubrearduino.com/l293d/
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA 25
#define SCL 26
#define LCD_ADDRESS 0X3F //  0x7C // 0X27

#define VELOCIDAD 14
#define DIRPIN_1 12
#define DIRPIN_2 13

// Estados posibles
#define PARO 0
#define DERECHA 1
#define IZQUIERDA 2

#define POT 32

// Diodos LED
#define ROJO 0
#define VERDE 15
#define AZUL 4

void cambioEstado(int estadoNuevo);
int leerPot();
void writeLCD(String message, int row);

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setup()
{
  Serial.begin(115200);

  pinMode(VELOCIDAD, OUTPUT);
  pinMode(DIRPIN_1, OUTPUT);
  pinMode(DIRPIN_2, OUTPUT);

  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);

  pinMode(POT, INPUT);

  Wire.begin(SDA, SCL);
  // Wire.beginTransmission(LCD_ADDRESS);

  lcd.init();
  lcd.noBacklight();
  delay(1000);
  lcd.backlight();
  lcd.clear();
}

void loop()
{

  cambioEstado(DERECHA);
  delay(5000);

  cambioEstado(PARO);
  delay(2000);

  cambioEstado(IZQUIERDA);
  delay(5000);

  cambioEstado(PARO);
  delay(2000);
}

void cambioEstado(int estadoNuevo)
{
  lcd.clear();
  switch (estadoNuevo)
  {
  case PARO:
    Serial.println("Motor parado.");
    writeLCD("Motor parado", 0);
    analogWrite(VELOCIDAD, 0); // Aapagamos el motor
    digitalWrite(ROJO, HIGH);
    digitalWrite(AZUL, LOW);
    digitalWrite(VERDE, LOW);
    break;
  case IZQUIERDA:
    // digitalWrite(VELOCIDAD, HIGH); // Encendemos el motor
    Serial.println("Girando en la dirección IZQUIERDA.");
    writeLCD("Giro IZQUIERDA", 0);
    writeLCD("Velocidad: " + String(leerPot()), 1);
    analogWrite(VELOCIDAD, leerPot());
    digitalWrite(DIRPIN_1, 0);
    digitalWrite(DIRPIN_2, 1);

    digitalWrite(ROJO, LOW);
    digitalWrite(AZUL, HIGH);
    digitalWrite(VERDE, LOW);
    break;
  case DERECHA:
    // digitalWrite(VELOCIDAD, HIGH); // Encendemos el motor
    Serial.println("Girando en la dirección DERECHA.");
    writeLCD("Giro DERECHA", 0);
    writeLCD("Velocidad: " + String(leerPot()), 1);
    analogWrite(VELOCIDAD, leerPot());
    digitalWrite(DIRPIN_1, 1);
    digitalWrite(DIRPIN_2, 0);

    digitalWrite(ROJO, LOW);
    digitalWrite(AZUL, LOW);
    digitalWrite(VERDE, HIGH);
    break;
  }
}

int leerPot()
{
  int valorPot = analogRead(POT);
  return map(valorPot, 0, 4096, 80, 255);
}

void writeLCD(String message, int row)
{
  lcd.setCursor(0, row);
  lcd.print(message);
}