

int ENA = 3; 
int IN1 = 1; 
int IN2 = 2;

int ENB = 6; 
int IN3 = 4;
int IN4 = 5;

//Speed of the Motors
#define ENASpeed 250
#define ENBSpeed 150

int Sensor1 = 0;
int Sensor2 = 0;
int Sensor3 = 0;
int Sensor4 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  pinMode(Sensor4, INPUT);
  
}

void loop(){

  analogWrite(ENA, ENASpeed);
  analogWrite(ENB, ENBSpeed);
  
  Sensor1 = digitalRead(8);
  Sensor2 = digitalRead(9);
  Sensor3 = digitalRead(10);
  Sensor4 = digitalRead(11);
  Serial.print(Sensor1);Serial.print("  ");
  Serial.print(Sensor2);Serial.print("  ");
  Serial.print(Sensor3);Serial.print(" ");
  Serial.println(Sensor4);
  


 if (Sensor4 == HIGH && Sensor3 == HIGH && Sensor2 == LOW && Sensor1 == LOW){

 
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    //motor B Forward
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
 }

  
 if (Sensor4 == LOW && Sensor3 == LOW && Sensor2 == HIGH && Sensor1 == HIGH){
    //Turn Left
    
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  if(Sensor4 == LOW && Sensor3 == HIGH && Sensor2 == HIGH && Sensor1 == LOW){

    //FORWARD
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  

}
