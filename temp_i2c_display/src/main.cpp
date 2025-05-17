/*
  Test project for reading temperatures and displaying on I2C display
    Arduino: Elegoo Uno R3
      ->>> LiquidCrystal_I2C.h did not work with Arduino R4 Wifi
    Display: Inland 1602 I2C Module
    Temperature sensor: DS18B20
*/

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

// Setup Pins
#define pin_temp 8

// Setup DS18B20 temp sensor
OneWire onewire = OneWire(pin_temp);
DallasTemperature sensors(&onewire);

// Setup Inland 1602 I2C Display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  
  // Setup Serial
  Serial.begin(9600);
  while(!Serial);

  // Setup Temp Sensor
  sensors.begin();

  // Setup I2C Display
  lcd.begin(16, 2);
  lcd.setBacklight(1);

}
  
void loop()
{
  
  // Send request for temps
  sensors.requestTemperatures();
  double current_temp = sensors.getTempFByIndex(0);

  // Current Temperatures
  Serial.print("Current Temperature: ");
  Serial.println(current_temp);

  // Send temps to display
  lcd.setCursor(2, 0);
  lcd.print("Temp: ");
  lcd.print(current_temp);

  // Read delay
  delay(2000);

}