const String STRING_VALUE_0 = "0";
const String STRING_VALUE_1 = "1";
const String STRING_VALUE_2 = "2";
const String STRING_VALUE_3 = "3";
const String STRING_VALUE_4 = "4";
const String STRING_VALUE_5 = "5";
const String STRING_VALUE_6 = "6";
const String STRING_VALUE_7 = "7";
const String STRING_VALUE_8 = "8";
const String STRING_VALUE_9 = "9";

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(9, 8, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  Serial.println("ArduProbe is a electric signal probe tool");
  Serial.println("using 16x2 LCD display with Hitachi HD44780 driver");
  Serial.println("controlled by LiquidCrystal library.");
  Serial.println("LCD<->Arduino pin:");
  Serial.println("RS<->9");
  Serial.println("En<->8");
  Serial.println("D4<->4");
  Serial.println("D5<->5");
  Serial.println("D6<->6");
  Serial.println("D7<->7");
  Serial.println("R/W<->GND");
  Serial.println("VSS<->GND");
  Serial.println("VCC<->5V");
  Serial.println("10K variable resistor:");
  Serial.println("     ->+5V");
  Serial.println("VO->[]");
  Serial.println("     ->GND");


  Serial.println("This code is in The MIT License (MIT)");
  Serial.println("Copyright (c) 2015 github.com/satr");

  lcd.begin(16, 2);
  write(0, 0, "ArduProbe");
  write(0, 1, "v 1.0");
  write(10, 0, "|  |");
  write(10, 1, "|  |");
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  delay(500);
}

void loop() {
  writeAnalogvalueues();
  delay(20);
}

void writeAnalogvalueues(){
  write(11, 0, getAnalogValue(2));
  write(14, 0, getAnalogValue(3));
  write(11, 1, getAnalogValue(6));
  write(14, 1, getAnalogValue(7));
}

String getAnalogValue(int pin){
  return convertAnalogToString(analogRead(pin));
}

String convertAnalogToString(int value){
  if(value > 1020)
    return STRING_VALUE_5;
  if(value < 204)
    return STRING_VALUE_0 + convertAnalogToString2(value);
  if(value < 408)
    return STRING_VALUE_1 + convertAnalogToString2(value - 204);
  if(value < 612)
    return STRING_VALUE_2 + convertAnalogToString2(value - 408);
  if(value < 816)
    return STRING_VALUE_3 + convertAnalogToString2(value - 612);
  return STRING_VALUE_4 + convertAnalogToString2(value - 816);
}

String convertAnalogToString2(int value){
  if(value < 17)
    return STRING_VALUE_0;
  if(value < 34)
    return STRING_VALUE_1;
  if(value < 51)
    return STRING_VALUE_2;
  if(value < 68)
    return STRING_VALUE_3;
  if(value < 85)
    return STRING_VALUE_4;
  if(value < 103)
    return STRING_VALUE_5;
  if(value < 120)
    return STRING_VALUE_6;
  if(value < 136)
    return STRING_VALUE_7;
  if(value < 154)
    return STRING_VALUE_8;
  return STRING_VALUE_9;
}

void write(int col, int row, String message){
  lcd.setCursor(col, row);
  lcd.print(message);
}
