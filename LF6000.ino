#include <Servo.h>
Servo myservo;            // create servo object to control a servo
Servo myservo1;           // create servo object to control valve servo
int Change = 2;
int Change1 = 2;          //blinds start closed

void setup()
{
  myservo1.attach(3);      // attaches the valve servo to pin 3
  myservo.attach(4);       // attaches the blinds servo to pin 4
  Serial.begin(9600);
}

void loop()
{
  int bright = analogRead(A0);
  Serial.println(bright); //troubleshooting readout
  delay(250);             //just a small buffer to keep the code running smoothly

  if (bright > 500) {
    Change = 1;
  }

  else if (bright < 500) {
    Change = 2;
  }


  if (Change == Change1) {
    myservo1.write(75);     //valve still closed
    myservo.write(90);      //blinds not moving
    delay(100);             //just a small buffer to keep the code running smoothly
  }

  else {

    if (bright > 500) {
      myservo.write(135);     //opening the blinds full speed
      delay(5000);            //amount of time to fully open blinds
      myservo.write(90);      // stop the blind power
      myservo1.write(180);    //valve watering the plant
      delay(300);             //amount of water stream time
      Change1 = Change;
    }

    else if (bright < 500) {
      myservo.write(45);      //45 is counterclockwise at full speed
      delay(5000);            //amount of time to fully close blinds
      myservo.write(90);      // stop the blind power
      myservo1.write(75);     //valve still closed
      delay(100);
      Change1 = Change;
    }
  }

}
