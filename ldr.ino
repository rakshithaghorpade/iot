int sensorPin = A0; // select the input pin for LDR

int sensorValue = 0; 
int led=10;
int ledb=0;
int thv=800;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin); // read the value from the sensor
Serial.println(sensorValue); //prints the values coming from the sensor on the screen
if(sensorValue>thv)
{
  ledb=map(sensorValue,0,1023,0,255);
  analogWrite(led,ledb);
}
else{
  analogWrite(led,0);
}
delay(300);
}
