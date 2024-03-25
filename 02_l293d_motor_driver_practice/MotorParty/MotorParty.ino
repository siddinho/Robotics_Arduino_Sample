// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
//#include <Servo.h>

// DC motor on M2
AF_DCMotor rightMotor(1);
AF_DCMotor leftMotor(2);


// DC hobby servo
//Servo servo1;
// Stepper motor on M3+M4 48 steps per revolution
//AF_Stepper stepper(48, 2);

void setup() {
  Serial.begin(9600);  // set up Serial library at 9600 bps
  Serial.println("Motor party!");

  // turn on servo
  //servo1.attach(9);

  // // initiate right motor
  // rightMotor.setSpeed(100);
  // rightMotor.run(RELEASE);  // Not running motor

  // initiate right motor
  leftMotor.setSpeed(200);
  leftMotor.run(RELEASE);

    // initiate right motor
  rightMotor.setSpeed(200);
  rightMotor.run(RELEASE);

}

void forward(int duration){
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
  delay(duration);

}


void backward(int duration){
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


void loop() {



  backward(5000);
  stop(2000);
  turnRight(3000);
  stop(2000);


  // // Forward Movement
  // leftMotor.run(FORWARD);
  // rightMotor.run(FORWARD);
  // delay(5000);


  // leftMotor.run(RELEASE);
  // rightMotor.run(RELEASE);
  // delay(5000);


  // leftMotor.run(BACKWARD);
  // rightMotor.run(BACKWARD);
  // delay(5000);

  // // Stop Movement
  // leftMotor.run(RELEASE);
  // rightMotor.run(RELEASE);
  // delay(2000);

  // // Stop Movement
  // leftMotor.run(BACKWARD);
  // //rightMotor.run(BACKWARD);
  // delay(5000);


  //   // Stop Movement
  // leftMotor.run(RELEASE);
  // //rightMotor.run(RELEASE);
  // delay(2000);



}