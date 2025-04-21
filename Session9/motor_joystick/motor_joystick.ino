// Define motor driver pins for Motor 1
#define enableMotor1 5        // PWM pin to control speed of Motor 1
#define input1Motor1 6        // Control pin 1 for Motor 1
#define input2Motor1 7        // Control pin 2 for Motor 1

// Define motor driver pins for Motor 2
#define input1Motor2 8        // Control pin 1 for Motor 2
#define input2Motor2 9        // Control pin 2 for Motor 2
#define enableMotor2 10       // PWM pin to control speed of Motor 2

// Define joystick input pins
#define joystickX A0          // Analog input from joystick X-axis
#define joystickY A1          // Analog input from joystick Y-axis

void setup()
{
  // Set motor driver pins as OUTPUT
  pinMode(enableMotor1, OUTPUT);
  pinMode(enableMotor2, OUTPUT);
  pinMode(input1Motor1, OUTPUT);
  pinMode(input1Motor2, OUTPUT);
  pinMode(input2Motor1, OUTPUT);
  pinMode(input2Motor2, OUTPUT);

  // Set joystick pins as INPUT
  pinMode(joystickX, INPUT);
  pinMode(joystickY, INPUT);
}

// Function to drive Motor 1 forward with specified speed
void motor1ForwardDrive(int speed)
{
  analogWrite(enableMotor1, speed);     // Set PWM speed
  digitalWrite(input1Motor1, HIGH);     // Set direction forward
  digitalWrite(input2Motor1, LOW);
}

// Function to drive Motor 2 forward with specified speed
void motor2ForwardDrive(int speed)
{
  analogWrite(enableMotor2, speed);     
  digitalWrite(input1Motor2, HIGH);     
  digitalWrite(input2Motor2, LOW);
}

// Function to drive Motor 1 backward with specified speed
void motor1BackwardDrive(int speed)
{
  analogWrite(enableMotor1, speed);     
  digitalWrite(input1Motor1, LOW);      
  digitalWrite(input2Motor1, HIGH);
}

// Function to drive Motor 2 backward with specified speed
void motor2BackwardDrive(int speed)
{
  analogWrite(enableMotor2, speed);     
  digitalWrite(input1Motor2, LOW);      
  digitalWrite(input2Motor2, HIGH);
}

// Function to control motor direction and speed based on joystick input
void motionPlan(int speedMotor1, int speedMotor2)
{
  // Check X-axis joystick value to control Motor 1
  if (speedMotor1 > 550)  // Joystick pushed forward
  {
    // Map input range (550-1024) to motor speed (0-255)
    speedMotor1 = map(speedMotor1, 550, 1024, 0, 255);
    motor1ForwardDrive(speedMotor1);
  }
  else if (speedMotor1 < 460)  // Joystick pulled backward
  {
    // Map input range (460-0) to motor speed (0-255)
    speedMotor1 = map(speedMotor1, 460, 0, 0, 255);
    motor1BackwardDrive(speedMotor1);
  }

  // Check Y-axis joystick value to control Motor 2
  if (speedMotor2 > 550)
  {
    speedMotor2 = map(speedMotor2, 550, 1024, 0, 255);
    motor2ForwardDrive(speedMotor2);
  }
  else if (speedMotor2 < 460)
  {
    speedMotor2 = map(speedMotor2, 460, 0, 0, 255);
    motor2BackwardDrive(speedMotor2);
  }
}

void loop()
{
  // Read joystick positions continuously
  int speedMotor1 = analogRead(joystickX);
  int speedMotor2 = analogRead(joystickY);

  // Determine motor movement based on joystick input
  motionPlan(speedMotor1, speedMotor2);
}
