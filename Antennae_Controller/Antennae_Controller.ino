#include <LiquidCrystal.h>
#include <Stepper.h>

LiquidCrystal lcd(2,3, 4, A3, A2, A1, A0);
Stepper myStepper1(2048, 9, 11, 10, 12);     //stepper motor 1
Stepper myStepper2(2048, 20,5,21,6);     //stepper motor 2

void setup() {
  //Ground pin A5 so as to set the contrast of the LCD 
  pinMode(A5,OUTPUT);
  digitalWrite(A5,LOW); 
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("REMOTE ANTENNAE");
  //Set stepper speed
  myStepper1.setSpeed(3);
  myStepper2.setSpeed(3);
  Serial.begin(9600);   
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
  
  //myStepper2.step(32);
  //myStepper1.step(32);
  String inputString;
  if(Serial.available()){
    while(Serial.available())
      {
        char inChar = (char)Serial.read(); //read the input
        inputString += inChar;        //make a string of the characters coming on serial
      }
      
      if(inputString.equals("1")){
          myStepper1.step(64);
          lcd.print("STEPPER 1 MOVE");
          Serial.println("STEPPER 1");
        }
      else if(inputString.equals("3")){
          myStepper2.step(64);
          lcd.print("STEPPER 2 MOVE");
          Serial.println("STEPPER 2");
        }
      //Serial.println("HAHAHA");
      inputString = "";
  }
}
