# include<Servo.h>

Servo s1;
int pos = 0;

void setup() {

  Serial.begin(9600);

  s1.attach(9);
  s1.write(pos);
  // put your setup code here, to run once:

}

void loop() {

  Serial.write("Clockwise Rotation");
  Serial.write("\n");

  for (pos =0;pos<=180;pos+=10){
    s1.write(pos);
    // Serial.write("Position is "+pos);
    delay(1000);
  }

  Serial.write("Anti Clockwise Rotation");
  Serial.write("\n");

  for (pos=180;pos>=0;pos-=10){
    s1.write(pos);
    // Serial.write("Position is "+pos);
  delay(1000);  }



}
