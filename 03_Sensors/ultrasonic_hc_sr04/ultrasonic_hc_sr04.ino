// Include NewPing Library
#include <NewPing.h>

// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
int TRIGGER_PIN =A4;
int ECHO_PIN = A5;
int led_pin = 11;

// Maximum distance we want to ping for (in centimeters).
int MAX_DISTANCE =400;	
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int distance = 0;

















void setup() {
	Serial.begin(9600);
  pinMode(led_pin, OUTPUT);

}

void loop() {
  distance = sonar.ping_cm();
  delay(1000);

  if (distance<=20 && distance!=0){
  digitalWrite(led_pin,HIGH);
  delay(1000);
  }
  else{
    digitalWrite(led_pin,LOW);
    delay(1000);


  }

  Serial.print("Distance = ");
	Serial.print(sonar.ping_cm());
	Serial.println(" cm");
	delay(500);
}