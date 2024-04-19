int IRSensor = 9;
int LED = 13;
void setup() {
  // put your setup code here, to run once:
 
Serial.begin(115200);  
pinMode(IRSensor, INPUT); 
pinMode(LED, OUTPUT); 
}

// put your main code here, to run repeatedly:
void loop() {
 int sensorStatus = digitalRead(IRSensor); 
  if (sensorStatus == 1) // بررسی HIGH بودن
  {
 
    digitalWrite(LED, HIGH); // LED HIGH
    Serial.println("Motion Detected!"); //نمایش عبارت در سریال مانیتور
  }
  else  {
    
    digitalWrite(LED, LOW); // LED LOW
    Serial.println("Motion Ended!"); // نمایش عبارت در سریال مانیتور
  }

}
