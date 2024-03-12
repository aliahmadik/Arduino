int trig = 13;
int echo = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(5);
  
  int duration = pulseIn(echo,HIGH);
  int cm = duration_to_cm(duration);
  Serial.print("centimetre = ");
  Serial.println(cm);
  delay(500);
}

int duration_to_cm(int d){
  return ((d/2)/29);
}
