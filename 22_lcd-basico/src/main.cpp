#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA 13
#define SCL 14
#define LCD_ADDRESS 0X3F //  0x7C // 0X27

const char *ssid = "Aula 1";
const char *password = "Horus.2025";

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setup()
{
  Serial.begin(115200);

  Wire.begin(SDA, SCL);
  // Wire.beginTransmission(LCD_ADDRESS);

  lcd.init();
  lcd.noBacklight();
  delay(1000);
  lcd.backlight();
  lcd.clear();
  // lcd.setCursor(0, 0);
  // lcd.print("Hola mundo");
  // lcd.setCursor(0, 1);
  // lcd.print("Bienvenido...");
}

void loop()
{
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);
  lcd.setCursor(5, 0);
  lcd.print("Adios");
}
