int buzzer=13;
int analog=0;
int flamepin=2;
int threshold=800;
int flame=HIGH;

void setup() {
pinMode(buzzer,OUTPUT);
pinMode(analog,INPUT);

Serial.begin(9600);


}

void loop() {
  int analogval=analogRead(analog);
  Serial.println(analogval);
  
  if(analogval<threshold)
  {
    digitalWrite(buzzer,HIGH);
    Serial.print("high flame");
    Serial.print(analogval);
    
    //delay(1000);
  }
  else
  {
    digitalWrite(buzzer,LOW);
    Serial.print("low flame");
    delay(400);
  }
  delay(1000);
}
