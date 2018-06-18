/* The same code as the partial tank circuit, but stripped down in order to make it look faster.
 * 
 * 
 */

#include <Servo.h>
 //pins
int buzzer = 9;
int laser = 8;
int lifeLED1 = 2;
int lifeLED2 = 3;
int indicatorLED = 4;

Servo leftServo;
Servo rightServo;

int center = 90;
int fwd = 120;
int back = 1250;

// radio inputs
int A = 10;
int B = 11;
int C = 13;
int D = 12;

int lightSensor = A0;
int sensorValue = 0;

int life = 2;
int wait = 20;

int a = 0;
int b = 0;
int c = 0;
int d = 0;



void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(lifeLED1, OUTPUT);
  pinMode(lifeLED2, OUTPUT);
  pinMode(laser, OUTPUT);

  pinMode(indicatorLED, OUTPUT);

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
    sensorValue = analogRead(lightSensor);
    Serial.println(sensorValue);
    
    if(sensorValue < 500) {
      a = digitalRead(A);
      b = digitalRead(B);
      c = digitalRead(C);
      d = digitalRead(D);
      Serial.println("In the if loop!");
      Serial.println(a);
      Serial.println(b);
      Serial.println(c);
      Serial.println(d);
      delay(wait);
      
      //one button == drive
      if(a == 1 && b ==0 && c == 0 && d ==0){//(b && c && d == 0 )){
        Serial.println("A LOOP===================");
        leftServo.write(30);
        delay(wait);
      }
      if(a == 0 && b ==1 && c == 0 && d ==0){//(b == HIGH && (a && c && d == LOW )){
        Serial.println("B LOOP===================");
        leftServo.write(30);
        rightServo.write(150);
        delay(wait);
      }
      if(a == 0 && b ==0 && c == 1 && d ==0){//(c == HIGH && (a && b && d == LOW )){
        Serial.println("C LOOP===================");
        leftServo.write(150);
        rightServo.write(30);
        delay(wait);
      }
      if(a == 0 && b ==0 && c == 0 && d ==1){//(c == HIGH && (a && b && d == LOW )){
        Serial.println("D LOOP===================");
        rightServo.write(30);
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

      
    }
    else {//sensorValue is > 500, life a life:
      life = life-1;
      tone(buzzer, 50);
      delay(900);
      noTone(buzzer);
      delay(100);
    }

    // assign life lights:
    switch (life) {
      case 2:
        digitalWrite(lifeLED1, HIGH);
        digitalWrite(lifeLED2, HIGH);
       break;
      case 1:
        digitalWrite(lifeLED1, HIGH);
        digitalWrite(lifeLED2, LOW);
       break;
      case 0:
        digitalWrite(lifeLED1, LOW);
        digitalWrite(lifeLED2, LOW);
        for(int i = 50; i <75; i++){
          tone(buzzer, i);
          delay(20);
        }
     }
 }
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
    delay(200);
    digitalWrite(lifeLED1, LOW);
    digitalWrite(lifeLED2, LOW);
    delay(200);
    life = 2;
}
