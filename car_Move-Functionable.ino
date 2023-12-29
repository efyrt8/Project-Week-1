#include <LiquidCrystal.h>
// Motor A connections
int enA = 11;
int in1 = A2;
int in2 = A3;
// Motor B connections
int enB = 3;
int in3 = A4;
int in4 = A5;

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int seconds=0;

int i=0;

void setup() {
    // LCD
    lcd.begin(16, 2);

  // Print a message to the LCD
    lcd.print("Prepare to begin");
    lcd.print("Moving in");
    lcd.setCursor(0,1);
    lcd.print("3");
    delay(1000);
    lcd.print(" ");
    lcd.setCursor(1,1);
    lcd.print("2");
    delay(1000);
    lcd.print(" ");
    lcd.setCursor(2,1);
    lcd.print("1");
    delay(1000);
    lcd.print(" ");
    lcd.clear();
    lcd.print("Start!");
    lcd.clear();
    lcd.print("Moving");
    // Set all the motor control pins to outputs
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    
    // Turn off motors - Initial state
    analogWrite(in1, LOW);
    analogWrite(in2, LOW);
    analogWrite(in3, LOW);
    analogWrite(in4, LOW);
}

void loop(){
  while (i<=10){
    //Count Seconds
    lcd.setCursor(0,1);
    lcd.print(seconds);
    seconds+=1;
    moveForward();
    delay(1000);
    i+=1;
  }
  stopMotors();
}
void moveForward() {
    // Set motors to maximum speed
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    // Turn on motor A & B forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}
void stopMotors() {
    // Turn off motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    lcd.clear();
    lcd.print("Complete");
    delay(1000);
    lcd.clear();
} 


