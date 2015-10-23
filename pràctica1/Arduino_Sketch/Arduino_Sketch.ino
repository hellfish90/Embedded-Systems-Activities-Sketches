
int vertical = A1;      // select the input pin for the vert
int horizontal = A0;
int buttonPin = 2;

void setup(){
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, 1);
}

void loop(){
 int valX = analogRead(horizontal);
 int valY = analogRead(vertical);

 int cx = map(valX,0,1023,0,199);
 int cy = map(valY,0,1023,0,199);

 int button = digitalRead(buttonPin); 
 
 Serial.print(cx);Serial.print(';');
 Serial.print(cy);Serial.print(';');
 Serial.print(button);Serial.print(';');
 Serial.print("*");
 
 delay(100);
}
