int S2= 11;
int S3= 12;
int outPin = 4; 

int rColorStrength;
int gColorStrength;  
int bColorStrength;


unsigned int pulseWidth;


void setup() {
  Serial.begin(9600);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(outPin,INPUT);
  pinMode(13,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  
}

void loop() {
   digitalWrite(13,HIGH);
  //RED- S2: low, S3: low
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  pulseWidth = pulseIn(outPin, LOW);

  rColorStrength = pulseWidth;///400. -1;
  //rColorStrength = (255- rColorStrength);
  //


  //GREEN- S2: High, S3: High
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  pulseWidth = pulseIn(outPin, LOW);

  gColorStrength = pulseWidth;///400. -1;
  //gColorStrength = (255- gColorStrength);
  //


  //BLUE- S2: Low, S3: High
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  pulseWidth = pulseIn(outPin, LOW);

   bColorStrength = pulseWidth;///400. -1;
  //bColorStrength = (255- bColorStrength);
  //


 if(rColorStrength>=1200 && gColorStrength>=1200 && bColorStrength>=1200){
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(9,40);  
  delay(250);
  analogWrite(9,0);
  }
 else{
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  analogWrite(9,0);
  }
 if(rColorStrength<=1000 && gColorStrength>=1200 && bColorStrength>=1200)
 {
  digitalWrite(2,HIGH);
  delay(2000);
  digitalWrite(2,LOW);
  delay(2000);
  
 }else{
  digitalWrite(2,LOW);
 }



 
 Serial.print(rColorStrength);
 Serial.print(" , ");
 Serial.print(gColorStrength);
 Serial.print(" , ");
 Serial.print(bColorStrength);
 Serial.println("");
 delay(100);
}
