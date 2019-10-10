#include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
int count=0;
char input[12];
int g=2;
int r=3;
char check[12]={'5','3','0','0','2','9','1','3','C','4','A','D'};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean flag=0;
  if(mySerial.available())
  {
    count=0;
    while(mySerial.available() && count<12)
 
    {
        input[count]=mySerial.read();
        count++;
        delay(5);
    }
    Serial.println(input);
    for(int i=0;i<12;i++)
    {
      if(input[i]!=check[i])
      {
        flag=1;
        break;
        
      }
    }
    if(flag==1)
    {
      digitalWrite(r,HIGH);
      digitalWrite(g,LOW);
      Serial.println("Access Denied");
    }
    else
    {
      digitalWrite(g,HIGH);
      digitalWrite(r,LOW);
      Serial.println("Access Granted");
    }
    //digitalWrite(r,HIGH);
    delay(1000);
  }
}
