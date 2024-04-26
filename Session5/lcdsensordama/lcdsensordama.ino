#include <DHT11.h>

#define DHT11_PIN 8
DHT11 dht11(DHT11_PIN);


#include <LiquidCrystal.h>
#define RS 2
#define E  3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
LiquidCrystal lcd(RS,E,D4,D5,D6,D7);

void setup(){
  lcd.begin(16, 2);
}
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Temp = ");
  lcd.print((int)dht11.readTemperature());
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humidity = ");
  lcd.print((int)dht11.readHumidity());
  lcd.print(" %");
  delay(2000);
}
