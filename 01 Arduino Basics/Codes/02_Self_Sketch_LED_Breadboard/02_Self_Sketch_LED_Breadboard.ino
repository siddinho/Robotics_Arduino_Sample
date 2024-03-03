/* LED on BREADBOARD made by Siddharth Alternating LED's Code*/

int ledBulb1 = 7; // digital pin 7 


void setup() {

  pinMode(ledBulb1,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);



  // put your setup code here, to run once:

}

void loop() {

  digitalWrite(ledBulb1,HIGH);
  delay(1000);

  digitalWrite(ledBulb1,LOW);
  delay(1000);


  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);

  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);

  // put your main code here, to run repeatedly:

}
