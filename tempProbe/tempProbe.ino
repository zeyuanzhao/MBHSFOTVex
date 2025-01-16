#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int tim = 250;
LiquidCrystal lcd(4, 6,  10, 11, 12, 13);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin();

  lcd.begin(16, 2);
}

int cnt = 0;

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures(); 
  int tempC = sensors.getTempCByIndex(0);
  int tempF = sensors.getTempFByIndex(0);

  Serial.print("Celsius temperature: ");
  Serial.print(tempC); 
  Serial.print(" - Fahrenheit temperature: ");
  Serial.println(tempF);

  lcd.setCursor(0, 0);
  lcd.print("C: ");
  lcd.print(tempC);
  lcd.setCursor(0, 1);
  lcd.print("F: ");
  lcd.print(tempF);
  
  lcd.setCursor(10, 0);
  lcd.print(cnt);

  delay(tim);

  cnt++;
}  

