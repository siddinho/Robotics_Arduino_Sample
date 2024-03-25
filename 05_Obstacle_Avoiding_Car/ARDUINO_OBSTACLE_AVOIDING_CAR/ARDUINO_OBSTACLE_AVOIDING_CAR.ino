//ARDUINO OBSTACLE AVOIDING CAR//
// Before uploading the code you have to install the necessary library//
//AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install //
//NewPing Library https://github.com/livetronic/Arduino-NewPing// 
//Servo Library https://github.com/arduino-libraries/Servo.git //
// To Install the libraries go to sketch >> Include Library >> Add .ZIP File >> Select the Downloaded ZIP files From the Above links //


#include <AFMotor.h>  
#include <NewPing.h>
#include <Servo.h> 

// #define TRIG_PIN A4
// #define MAX_DISTANCE 400 
// #define MAX_SPEED 200 // sets speed of DC  motors
// #define MAX_SPEED_OFFSET 20

int TRIGGER_PIN =A4;
int ECHO_PIN = A5;
int MAX_DISTANCE = 400;
int distance = 0;
int left_distance = 0;
int right_distance = 0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

AF_DCMotor leftMotor (1);
AF_DCMotor rightMotor (2);
Servo s1;   

int pos = 0;


void backward(int duration){ // Motor Polarity Reversed
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
  delay(duration);

}


void forward(int duration){
  leftMotor.run(BACKWARD);
  rightMotor.run(BACKWARD);
  delay(duration);

}


void turnRight(int duration){
  leftMotor.run(FORWARD);
  rightMotor.run(BACKWARD);
  delay(duration);

}

void turnLeft(int duration){
  rightMotor.run(FORWARD);
  leftMotor.run(BACKWARD);
  delay(duration);

}

void stop(int duration){
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
  delay(duration);
}


void setup() {

  Serial.begin(9600);  // set up Serial library at 9600 bps
  Serial.println("Motor party!");

  // initiate left motor
  leftMotor.setSpeed(200);
  leftMotor.run(RELEASE);

    // initiate right motor
  rightMotor.setSpeed(200);
  rightMotor.run(RELEASE);

  // initiate Servo Motor
  s1.attach(10);  
  s1.write(0); 


}

void loop() {

  

//Checking Servo Conenection - Servo Working fine


  s1.write(0);
  delay(2000);
  distance = sonar.ping_cm();
  Serial.println("Distance in cm :");
  Serial.println(distance);
  delay(5000);



  s1.write(60);
  delay(2000);
  left_distance = sonar.ping_cm();
  Serial.println("Distance L in cm :");
  Serial.println(left_distance);
  delay(5000);
  // s1.write(50);
  // delay(5000);
  // s1.write(110);
  // delay(5000);

  // for (pos =0;pos<=180;pos+=90){
  //   s1.write(pos);
  //   delay(10000);
  // }
  // backward(5000);
  // stop(10000);
}


//  int distanceR = 0;
//  int distanceL =  0;
//  delay(40);
 
//  if(distance<=15)
//  {
//   moveStop();
//   delay(100);
//   moveBackward();
//   delay(300);
//   moveStop();
//   delay(200);
//   distanceR = lookRight();
//   delay(200);
//   distanceL = lookLeft();
//   delay(200);

//   if(distanceR>=distanceL)
//   {
//     turnRight();
//     moveStop();
//   }else
//   {
//     turnLeft();
//     moveStop();
//   }
//  }else
//  {
//   moveForward();
//  }
//  distance = readPing();
// }

// int lookRight()
// {
//     myservo.write(50); 
//     delay(500);
//     int distance = readPing();
//     delay(100);
//     myservo.write(115); 
//     return distance;
// }

// int lookLeft()
// {
//     myservo.write(170); 
//     delay(500);
//     int distance = readPing();
//     delay(100);
//     myservo.write(115); 
//     return distance;
//     delay(100);
// }

// int readPing() { 
//   delay(70);
//   int cm = sonar.ping_cm();
//   if(cm==0)
//   {
//     cm = 250;
//   }
//   return cm;
// }

// void moveStop() {
//   motor1.run(RELEASE); 
//   motor2.run(RELEASE);
//   motor3.run(RELEASE);
//   motor4.run(RELEASE);
//   } 
  
// void moveForward() {

//  if(!goesForward)
//   {
//     goesForward=true;
//     motor1.run(FORWARD);      
//     motor2.run(FORWARD);
//     motor3.run(FORWARD); 
//     motor4.run(FORWARD);     
//    for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
//    {
//     motor1.setSpeed(speedSet);
//     motor2.setSpeed(speedSet);
//     motor3.setSpeed(speedSet);
//     motor4.setSpeed(speedSet);
//     delay(5);
//    }
//   }
// }

// void moveBackward() {
//     goesForward=false;
//     motor1.run(BACKWARD);      
//     motor2.run(BACKWARD);
//     motor3.run(BACKWARD);
//     motor4.run(BACKWARD);  
//   for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
//   {
//     motor1.setSpeed(speedSet);
//     motor2.setSpeed(speedSet);
//     motor3.setSpeed(speedSet);
//     motor4.setSpeed(speedSet);
//     delay(5);
//   }
// }  

// void turnRight() {
//   motor1.run(FORWARD);
//   motor2.run(FORWARD);
//   motor3.run(BACKWARD);
//   motor4.run(BACKWARD);     
//   delay(500);
//   motor1.run(FORWARD);      
//   motor2.run(FORWARD);
//   motor3.run(FORWARD);
//   motor4.run(FORWARD);      
// } 
 
// void turnLeft() {
//   motor1.run(BACKWARD);     
//   motor2.run(BACKWARD);  
//   motor3.run(FORWARD);
//   motor4.run(FORWARD);   
//   delay(500);
//   motor1.run(FORWARD);     
//   motor2.run(FORWARD);
//   motor3.run(FORWARD);
//   motor4.run(FORWARD);
// }  
