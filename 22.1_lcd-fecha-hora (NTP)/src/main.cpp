#include <Arduino.h>
#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SDA 13
#define SCL 14
#define LCD_ADDRESS 0X3F // 0X27

const char *ssid = "Aula 1";
const char *password = "Horus.2025";

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP); // Hora verano España

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);

void setup()
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  timeClient.begin();
  /*
    Set offset time in seconds to adjust for your timezone, for example:
      GMT +1 = 3600
      GMT +2 = 7200
      GMT +8 = 28800
      GMT -1 = -3600
      GMT 0 = 0
  */
  timeClient.setTimeOffset(7200);
  Wire.begin(SDA, SCL);
  // Wire.beginTransmission(LCD_ADDRESS);

  timeClient.begin();

  lcd.init();
  lcd.noBacklight();
  lcd.clear();
}

void loop()
{

  timeClient.update();
  String formattedDate = timeClient.getFormattedDate();
  // Extract date
  // The format is: AAAA-MM-DDTHH:MM:SS
  int splitT = formattedDate.indexOf("T");
  String dayStamp = formattedDate.substring(0, splitT);
  // Extract time
  String timeStamp = formattedDate.substring(splitT + 1, formattedDate.length() - 1);

  lcd.setCursor(0, 0);
  lcd.backlight();
  lcd.print(dayStamp + " " + timeStamp);

  delay(1000);
}
