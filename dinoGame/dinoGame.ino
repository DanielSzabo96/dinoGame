#include <Servo.h>

#define SERVO 50 //change the values acorrding to the connected pins
#define LED 15 //change the values acorrding to the connected pins

Servo myservo;
int pos = 0;
int analogVal = 0;


void setup() {
  pinMode(SERVO, OUTPUT);
  pinMode(LED, INPUT);
  myservo.attach(SERVO);
  Serial.begin(19200); //you can also do 9600 baud
  

}

void loop() {
  analogVal = analogRead(LED);
  Serial.println(analogVal);

  if(analogVal <= 60 && analogVal >= 30){  //you can change the grey thesehold acorrding to your screen
    for (pos = 0; pos <= 130; pos += 10) { // goes from 0 degrees to 130 degrees

    // in steps of 1 degree

    myservo.write(pos);              // tell servo to go to position in variable 'pos'

    delay(15);                       // waits 15ms for the servo to reach the position

  }

  for (pos = 130; pos >= 0; pos -= 10) { // goes from 130 degrees to 0 degrees

    myservo.write(pos);              // tell servo to go to position in variable 'pos'

    delay(15);                       // waits 15ms for the servo to reach the position

    }
  }
  else{
    
    pos = 0;

    myservo.write(pos);
  }
}
