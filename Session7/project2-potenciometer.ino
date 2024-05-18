void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(A0);
  value = map(value, 0, 1023, 0, 5);
  Serial.print("voltage is = " );
  Serial.println(value);
  delay(1000);
}
