
int vertical = A1;      // select the input pin for the vert
int horizontal = A0;

const int pingPin = 7;
const int pingEcho = 8;

void setup(){
  Serial.begin(9600);
}

void loop(){
 int valX = analogRead(horizontal);
 int valY = analogRead(vertical);

 float cx = map(valX,0,1023,0,TWO_PI);
 float cy = map(valY,0,1023,0,TWO_PI);

 long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingEcho, INPUT);
  duration = pulseIn(pingEcho, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

 Serial.print(cx);Serial.print(';');
 Serial.print(cy);Serial.print(';');
 Serial.print(cm);Serial.print(";");
 Serial.print("*");
 
 delay(100);
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
