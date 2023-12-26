#include <LiquidCrystal.h>
#include<IRremote.hpp>
#define IR_RECEIVE_PIN 9

int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; // قرار دادن پین ها در متغیر
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // پیکربندی ال سی دی
int Trig = 13;
int Echo = 12;
int laser = 8;

void setup() {
  // put your setup code here, to run once:
pinMode(Trig,OUTPUT);
pinMode(Echo,INPUT);
pinMode(laser,OUTPUT);
Serial.begin(9600);
lcd.begin(16, 2);
lcd.clear();
  
IrReceiver.begin(IR_RECEIVE_PIN,ENABLE_LED_FEEDBACK);// enable the receiver
}


void loop() {
  // put your main code here, to run repeatedly:
 float temp ,cm,m,inch ;
 sendsignal();  //calling send signal function to send a signal
 temp = pulseIn(Echo,HIGH);
 cm = distance_to_cm(temp);

  if (IrReceiver.decodedIRData.decodedRawData == 0XB847FF00){ // change the lcd information to meter
    m = cm / 100;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" M = ");
    lcd.setCursor(0,1);
    lcd.print(m);
    
    }

  
  if (IrReceiver.decodedIRData.decodedRawData == 0XBB44FF00){ //change the lcd information to centimeter
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" cm = ");
    lcd.setCursor(0,1);
    lcd.print(cm);
    
    }  
  
  if (IrReceiver.decodedIRData.decodedRawData == 0XBF40FF00){ //change the lcd information to inch
    
    inch = cm / 2.54;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" inch = ");
    lcd.setCursor(0,1);
    lcd.print(inch);
    
    }
  
  if (IrReceiver.decodedIRData.decodedRawData == 0XBA45FF00){ //turn on the laser beam
    digitalWrite(laser,HIGH);
    }
  
  if (IrReceiver.decodedIRData.decodedRawData == 0XB946FF00){ //turn off the laser beam
    digitalWrite(laser,LOW);
    }
  
  delay(500);

IR_remote();

}

void sendsignal(){
 digitalWrite(Trig,LOW);
 delayMicroseconds(2);
 digitalWrite(Trig,HIGH);
 delayMicroseconds(5);
}

long int distance_to_cm( int t){
  return (t / 2) * 0.03432;
}

void IR_remote(){
  if (IrReceiver.decode()) { // decode the received signal and store it in results
      Serial.println(IrReceiver.decodedIRData.decodedRawData,HEX);
      IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
      IrReceiver.printIRSendUsage(&Serial); // Print the statement required to send this data
      IrReceiver.resume(); // Enable receiving of the next value 
    }
   
}
