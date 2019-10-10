#include <LiquidCrystal.h>

const int trigPin = 3;
const int echoPin = 2;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // select the pins used on the LCD panel
void setup() {
lcd.begin(16, 2); // start the library
lcd.setCursor(0,0); // set the LCD cursor position
}
void loop()
{
// establish variables for duration of the ping,
// and the distance result in inches and centimeters:
long duration, inches, cm;
lcd.setCursor(0,1); // move cursor to second line &quot;1&quot; and 0 spaces over

// The sensor is triggered by a HIGH pulse of 10 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
pinMode(trigPin, OUTPUT);

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Read the signal from the sensor: a HIGH pulse whose
// duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
// convert the time into a distance
inches = microsecondsToInches(duration);
cm = microsecondsToCentimeters(duration);

lcd.print(inches);
lcd.print(" in ");
lcd.print(cm);
lcd.print("cm");
delay(1000);
}
long microsecondsToInches(long microseconds)
{
return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{ return microseconds / 29 / 2;
}
