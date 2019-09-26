int CT=30;
long unsigned int lowin;
long unsigned int pause=5000;
boolean locklow=true;
boolean takelowtime;
int pirpin=4;
int ledpin=13;
void setup()
{
  Serial.begin(9600);
 pinMode(ledpin,OUTPUT);
pinMode(pirpin,INPUT); 
digitalWrite(pirpin,LOW);
Serial.print("Calibrating the sensor");
for(int i=0;i<CT;i++)
{
  Serial.print('.');
  delay(100);
}
Serial.println("DONE");
Serial.println("sensor active");
delay(10);
}
void loop()
{
     if(digitalRead(pirpin)==HIGH)
     {
      digitalWrite(ledpin,HIGH);
        if(locklow)
        {
          locklow=false;
          Serial.println("___");
          Serial.println("Motion detected at");
          Serial.println((millis()/1000));
          Serial.println("Sec");
          delay(50);
        }
        takelowtime=true;
      }
      if(digitalRead(pirpin)==LOW)
      {
          digitalWrite(ledpin,LOW);
          if(takelowtime)
          {
            lowin=millis();
            takelowtime=false;
          }
          if(!locklow&&millis()-lowin>pause)
          {
            locklow=true;
         
          Serial.println("Motion detected at");
          Serial.println((millis()-pause)/1000);
          Serial.println("Sec");
          delay(50);
          }
      }
     }
  
  
  

    

  
