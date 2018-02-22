int led[5];

int val[5];

int motor1Pin1 = 3;
int motor1Pin2 = 5;
int motor2Pin1 = 10;
int motor2Pin2 = 9;

int maxSpeed = 1200;
int minSpeed = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  led[0] = A0;
  led[1] = A1;
  led[2] = A2;
  led[3] = A3;
  led[4] = A4;

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  for(int i = 0; i < 5; i++)
    pinMode(led[i], INPUT);
}

void turn90Left() {
  analogWrite(motor1Pin1, maxSpeed);
  analogWrite(motor1Pin2, 0);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, maxSpeed);
}

void turn45Left() {
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, minSpeed);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, maxSpeed);
}

void turn90Right() {
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, maxSpeed);
  analogWrite(motor2Pin1, maxSpeed);
  analogWrite(motor2Pin2, 0); 
}

void turn45Right() {
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, maxSpeed);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, minSpeed);
}

void moveForward() {
  analogWrite(motor1Pin1, 0);
  analogWrite(motor1Pin2, maxSpeed);
  analogWrite(motor2Pin1, 0);
  analogWrite(motor2Pin2, maxSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 5; i++) {
    val[i] = digitalRead(led[i]);
    if(val[i] == 1) {
      if(i == 4)
        turn90Left();
      if(i == 3)
        turn45Left();
      if(i == 2)
        moveForward();
      if(i == 1)
        turn45Right();
      if(i == 0)
        turn90Right();
    }
  }
}
