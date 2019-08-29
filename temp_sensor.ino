int op=0;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int rV=analogRead(op);
  float mv=(rV/1024.0);
  float c=mv/10;
  Serial.print(c);
  Serial.print("degree Farenheit  ");
  Serial.print((c*9)/5+32);
  Serial.println("Degree Celcius");
  delay(1000);
}
