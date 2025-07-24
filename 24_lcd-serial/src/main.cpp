#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA 13
#define SCL 14
#define ADDR 0x3F // 0x27 // La otra es 0x3F

LiquidCrystal_I2C lcd(ADDR, 16, 2);

void setup()
{
  Serial.begin(115200);
  Wire.begin(SDA, SCL);
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop()
{
  if (Serial.available())
  {
    delay(100);
    lcd.clear();
    while (Serial.available() > 0)
    {
      lcd.write(Serial.read());
    }
  }
}
