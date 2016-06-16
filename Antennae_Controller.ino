#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3, 4, A3, A2, A1, A0);

void setup() {
  // set up the LCD's number of columns and rows:
  pinMode(A5,OUTPUT);
  digitalWrite(A5,LOW);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}