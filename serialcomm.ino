#define led 13
int br;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("start serial monitor");
  Serial.println("type in box above");
  Serial.println("Control ledon off");
  Serial.println();
  }

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    br=Serial.read();
  }
  if(br=='1')
  {
    digitalWrite(led,HIGH);
    Serial.print("led on");
  }
  if(br=='0')
  {
    digitalWrite(led,LOW);
    Serial.print("led off");
  }
}
