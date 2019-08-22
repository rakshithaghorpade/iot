const int aIn=A0;
const int aOut=11;
int sensorValue=0;
int outputValue=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(aIn);
  outputValue=map(sensorValue,0,1023,0,255);
  analogWrite(aOut,outputValue);
  Serial.print("sensor= ");
  Serial.print(sensorValue);
  Serial.print("Output: ");
  Serial.print(outputValue);
  delay(5);
}
