#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define COLUMNS 16
#define LINES 2
#define ADDRESS 0x20

unsigned long previousMillis = 0;
unsigned int seconds = 0;
unsigned int minutes = 0;
unsigned int hours = 0;

LiquidCrystal_I2C lcd(ADDRESS, COLUMNS, LINES);

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Stopwatch");
  lcd.setCursor(13, 0);
  lcd.print("C++");
  lcd.setCursor(0, 1);
  lcd.print("00:00:00");
}

void loop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    seconds++;

    if (seconds > 59) {
      seconds = 0;
      minutes++;
      if (minutes > 59) {
        minutes = 0;
        hours++;
      }
    }

    lcd.setCursor(0, 1);
    if (hours < 10) lcd.print("0");
    lcd.print(hours);
    lcd.print(":");

    if (minutes < 10) lcd.print("0");
    lcd.print(minutes);
    lcd.print(":");

    if (seconds < 10) lcd.print("0");
    lcd.print(seconds);
  }
}