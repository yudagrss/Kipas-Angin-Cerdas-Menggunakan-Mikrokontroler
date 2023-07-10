 #include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2); 
#include <DHT.h>

DHT dht(2, DHT11);

int powerPin = 3;
int kipas = 4;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(powerPin, OUTPUT);
  digitalWrite(powerPin, LOW);
  pinMode(kipas,OUTPUT);
  digitalWrite(kipas, LOW);
 Serial.begin(9600);
 dht.begin();
  }

void loop() {
  digitalWrite(powerPin, HIGH);

  float suhu = dht.readTemperature();

   Serial.print("suhu: ");
   Serial.print(suhu);

   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Kipas Otomatis");
   lcd.setCursor(0,1);
   lcd.print("Suhu: ");
   lcd.setCursor(5,1);
   lcd.print(suhu);
   delay(1000);
   if(suhu>30.00)
   {
   digitalWrite(kipas,LOW);
   lcd.print("ON");
   }
   else{ 
    digitalWrite(kipas,HIGH);
    lcd.print("OFF");
   }
   }
  // put your main code here, to run repeatedly:
