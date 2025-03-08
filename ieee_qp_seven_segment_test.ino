#include <LiquidCrystal.h>


LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int trigPin = 3;
const int echoPin = 4; 

float duration, distance;
int counter = 0;  
unsigned long lastSensorTime = 0;
const unsigned long sensorInterval = 200;

void setup() {

  lcd.begin(16, 2);          
  lcd.setCursor(0, 0);     
  lcd.print("Counter:");    

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


  Serial.begin(9600);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastSensorTime >= sensorInterval) {
    lastSensorTime = currentTime;


    digitalWrite(trigPin, LOW);
    delayMicroseconds(0); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(0); 
    digitalWrite(trigPin, LOW);


    duration = pulseIn(echoPin, HIGH, 30000);
    if (duration > 0) {
      distance = (duration / 2.0) / 29.1; 

    
      if (distance <= 15) {
        counter++;
 
        lcd.setCursor(9, 0); 
        lcd.print(counter);  
        lcd.print("   ");  
      }
    }
  }
}
