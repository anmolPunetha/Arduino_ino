const int dirPin =2;
const int stepPin=3;
const int stepsPerRev=200;


void setup() {
  // put your setup code here, to run once:
pinMode(dirPin,OUTPUT);
pinMode(stepPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dirPin,HIGH);
  

  for(int x=0;x<stepsPerRev;x++)
  {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500);
       digitalWrite(stepPin,LOW);
      delayMicroseconds(500);
      

  }
  delay(250);
  
  digitalWrite(dirPin,LOW);
  

  for(int x=0;(x<stepsPerRev);x++)
  {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500);
       digitalWrite(stepPin,LOW);
      delayMicroseconds(500);
      

  }
  delay(250);
  

  
}
