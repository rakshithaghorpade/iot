int ct=20;
long unsigned int lowin;
long unsigned int pause=5000;
boolean locklow=true;
boolean takelowtime;
int pirpin=2;
int ledpin=13;
void setup()
{
  Serial.begin(9600);
  pinMode(pirpin, INPUT);
 pinMode(ledpin, OUTPUT);
  digitalWrite(pirpin, LOW);
  Serial.print("calibrating sensor");
  for(int i=0;i<ct;i++)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("done");
  Serial.println("sensor active");
  delay(50);
}
void loop()
{
  if(digitalRead(pirpin)==HIGH)
  {
      digitalWrite(ledpin,HIGH);
      if(locklow)
      {
           locklow=false;
           Serial.print("------");
           Serial.print("motion detected at ");
           Serial.print(millis()/1000);
           Serial.println(" sec"); 
           delay(50);
      }         
           takelowtime = true;
   }

   if(digitalRead(pirpin) == LOW)
   {       
       digitalWrite(ledpin, LOW);  

       if(takelowtime)
       {
        lowin = millis();         
        takelowtime = false;    
         //LOW pause
       }
       if(!locklow && millis() - lowin > pause)
       {  
           
           locklow = true;                        
           Serial.print("motion ended at ");     
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
       }
       
   }
   
    
    
    
}
  
