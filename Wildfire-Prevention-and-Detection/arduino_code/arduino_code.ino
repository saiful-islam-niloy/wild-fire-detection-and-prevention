#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT22
#define FlamePin A0
#define GasPin A2
DHT dht(DHTPIN,DHTTYPE);
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
 lcd.begin(16,2);
 pinMode(FlamePin, INPUT_PULLUP);
 pinMode(GasPin , INPUT_PULLUP);
 dht.begin();
}

void loop() {
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  int Flame = digitalRead(FlamePin);
  int Gas = digitalRead(GasPin);

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print(" %");
  delay(1000);
  lcd.clear();
  if(Flame==HIGH)
 {
  lcd.setCursor(0, 0);
  lcd.print("FLAME");
  lcd.setCursor(0, 1);
  lcd.print("DETECTED!");
  delay(1000);
  lcd.clear();
  
}
else
{
 lcd.setCursor(0, 0);
  lcd.print("NO FLAME");
  lcd.setCursor(0, 1);
  lcd.print("DETECTED!");
  delay(1000);
  lcd.clear();
}
if(Gas == HIGH){
    lcd.setCursor(0,0);
    lcd.print("Gas Detected!");
    delay(1000);
    lcd.clear();
  }
else{
  lcd.setCursor(0,0);
  lcd.print("No Gas Detected!");
  delay(1000);
  lcd.clear();
}
lcd.clear();
delay(500);
}
