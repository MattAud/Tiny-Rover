/* This is the next iteration in the code after RFTankStripDown.
 * StripDown took the partial code and made it faster in order to decrease the stutter
 * and give a proof of concept. It was, however, still partial.
 * 
 * This code adds in the "rest" of the tank's features that are
 * mounted on the PCB:
 * -All 3 life LEDs (and lives)
 * -Both light sensors
 * -The potentiometer to adjust the sensitivity of the light sensors.
 * 
 * Last update: 20180710
 * 
 * To Do:
 * 
 * -Impliment fwd/back/stop vals?
 * -When you die, stay dead
 * -More songs?
 * -better steering
 * -Scroll lights in the set up?
 * 
 */

#include <Servo.h>
 //pins
int buzzer = 9;
int laser = 8;
int lifeLED1 = 2;
int lifeLED2 = 3;
int lifeLED3 = 4;

Servo leftServo;
Servo rightServo;

int center = 90;
int fwd = 120;
int back = 50;

// radio inputs
int A = 10;
int B = 11;
int C = 13;
int D = 12;

int lightSensorL = A0;
int lightSensorR = A1;
int sensorValueL = 0;
int sensorValueR = 0;
int potentiometer = A3;

int life = 3;
int wait = 20;
int threshold = 650;

int a = 0;
int b = 0;
int c = 0;
int d = 0;



void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(lifeLED1, OUTPUT);
  pinMode(lifeLED2, OUTPUT);
  pinMode(lifeLED3, OUTPUT);
  pinMode(laser, OUTPUT);

  leftServo.attach(5);
  rightServo.attach(6);

  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);

  Serial.begin(9600);
}

void loop() {
  while(life > 0){
    Serial.println("In the life loop!");

    Serial.println("Read the trimpot:");
    threshold = analogRead(potentiometer);
    Serial.println(threshold);
    
    sensorValueL = analogRead(lightSensorL);
    sensorValueR = analogRead(lightSensorR);
    Serial.println(sensorValueL);
    Serial.println(sensorValueR);
    
    if(sensorValueL < threshold && sensorValueR < threshold) {
      Serial.println("In the if loop!");

      a = digitalRead(A);
      b = digitalRead(B);
      c = digitalRead(C);
      d = digitalRead(D);
      
      Serial.println(a);
      Serial.println(b);
      Serial.println(c);
      Serial.println(d);
      delay(wait);
      
      //one button == drive
      if(a == 1 && b ==0 && c == 0 && d ==0){//(b && c && d == 0 )){
        Serial.println("A LOOP===================");
        leftServo.write(10);
        delay(wait);
      }
      if(a == 0 && b ==1 && c == 0 && d ==0){//(b == HIGH && (a && c && d == LOW )){
        Serial.println("B LOOP===================");
        leftServo.write(10);
        rightServo.write(150);
        delay(wait);
      }
      if(a == 0 && b ==0 && c == 1 && d ==0){//(c == HIGH && (a && b && d == LOW )){
        Serial.println("C LOOP===================");
        leftServo.write(170);
        rightServo.write(30);
        delay(wait);
      }
      if(a == 0 && b ==0 && c == 0 && d ==1){//(c == HIGH && (a && b && d == LOW )){
        Serial.println("D LOOP===================");
        rightServo.write(150);
        delay(wait);
      }

      delay(wait);

      //two buttons == shoot
      if(a && b == 1 || c && d == 1 || a && c == 1 || b && d == 1 ){
        digitalWrite(laser, HIGH);
        // BA-DOOM!
        tone(buzzer, 75);
        delay(150);
        tone(buzzer, 50);
        delay(100);
        noTone(buzzer);
        delay(250);
        digitalWrite(laser, LOW);
      }

      // no buttons == stop
      if(a ==0 && b ==0  && c == 0 && d == 0){
        Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        leftServo.write(90);
        rightServo.write(90);
      }
    }// if sensor  value < threshold
    
    else {//sensorValue is > threshold, life a life:
      life = life-1;
      tone(buzzer, 50);
      delay(900);
      noTone(buzzer);
      delay(100);
    }

    // assign life lights:
    switch (life) {
      case 3:
        digitalWrite(lifeLED1, HIGH);
        digitalWrite(lifeLED2, HIGH);
        digitalWrite(lifeLED3, HIGH);
        break;
      case 2:
        digitalWrite(lifeLED1, HIGH);
        digitalWrite(lifeLED2, HIGH);
        digitalWrite(lifeLED3, LOW);
       break;
      case 1:
        digitalWrite(lifeLED1, HIGH);
        digitalWrite(lifeLED2, LOW);
        digitalWrite(lifeLED3, LOW);
       break;
      case 0:
        digitalWrite(lifeLED1, LOW);
        digitalWrite(lifeLED2, LOW);
        digitalWrite(lifeLED3, LOW);
        for(int i = 50; i <75; i++){
          tone(buzzer, i);
          delay(20);
        }
     } //switch life
 }// while live > 0

 
 //dead scenario: 
 for(int i = 75; i >50; i--){
    tone(buzzer, i);
    delay(20);
  }
  noTone(buzzer);
    delay(500);
    noTone(buzzer);
    delay(4000); 
    digitalWrite(lifeLED1, HIGH);
    digitalWrite(lifeLED2, HIGH);
    digitalWrite(lifeLED3, HIGH);
    delay(200);
    digitalWrite(lifeLED1, LOW);
    digitalWrite(lifeLED2, LOW);
    digitalWrite(lifeLED3, LOW);
    delay(200);
    life = 3;
} //loop
