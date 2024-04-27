const int SW = 2;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
analogReference(DEFAULT);
}

void loop() {
  int vx = analogRead(A0);
  int vy = analogRead(A1);
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW));
  
  Serial.print("    | \t Vx =");
  Serial.print(vx);
  Serial.print("    | \t Vy=");
  Serial.println(vy);
  Serial.println("-------------------------------------------------");
  delay(1000);
}
