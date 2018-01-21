#define trigPin 10
#define echoPin 9
#define vcc 4 

int Buzzer = 13; // Use the onboard Uno LED
int obstaclePin = 7;  // This is our input pin
int hasObstacle = HIGH;  // HIGH MEANS NO OBSTACLE
int flag = 0;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(obstaclePin, INPUT);  
}

void loop() {
  digitalWrite(vcc, HIGH);
//  hasObstacle = digitalRead(obstaclePin); //Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
//  if (hasObstacle == LOW) //LOW means something is ahead, so illuminates the 13th Port connected LED
//  {
//    //Serial.println("Path is clear");
//    digitalWrite(Buzzer, LOW);
//  }
//  else
//  {
//    //Serial.println("Stop something is ahead!!");
//    flag = 1;
//    digitalWrite(Buzzer, HIGH);//Illuminates the 13th Port LED
//    delay(30);
//    digitalWrite(Buzzer, LOW);
//  }
  if(flag == 0){
   float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if(distance <= 12){
    digitalWrite(Buzzer, HIGH);
    delay(20);
    digitalWrite(Buzzer, LOW);
    delay(200);
    digitalWrite(Buzzer, HIGH);
    delay(20);
    digitalWrite(Buzzer, LOW);
  }
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(760);
  delay(300);
  }
  flag = 0;
  delay(200);
}
