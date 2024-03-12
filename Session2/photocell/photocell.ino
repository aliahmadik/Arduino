
int LED = 9;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor_value = analogRead(A0);
  Serial.println(sensor_value);
  delay(500);
  
  if ( c <= 100 ) {
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
  }
}
