/*
  
 The circuit:
 * vert pin of the joystick attached to analog input 0
 * vert pin of the joystick attached to analog input 0
 * GND pin of the joystick to ground
 * VCC pin of the joystick to +5V

 Created by Marc Solé Farré
 on 22 October 2015

 */

int vertical = A0;      // select the input pin for the vert
int horizontal = A1;    // select the input pin for the hort
int buttonPin = 2;
int x = 0;              // variable for store the value of the input of the vertical input
int y = 0;              // variable for store the value of the input of the horizontal input
int button = 0;
int TOPMARGIN=700;      // margin to determine the zone of no movement
int BOTTOMMARGIN = 200; // margin to determine the zone of no movement

void setup() {
  Serial.begin(9600);
  //pinMode(buttonPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, 1);
}

void loop() {
  // read the value from the vertical and horizontal inputs
  x = analogRead(vertical);
  y = analogRead(horizontal);
  button = digitalRead(buttonPin);   // read the input pin
  Serial.println("");
  Serial.print(button);
  Serial.println("");
  delay(50);

  if(x > TOPMARGIN && y > TOPMARGIN){
    if(x>y){
      Serial.println("right");
    }else{
      Serial.println("down");
    }
  }else if(x > TOPMARGIN && y < TOPMARGIN){
    if(x>y && y>125){
      Serial.println("right");
    }else{
      Serial.println("up");
    }
  }else if(x < BOTTOMMARGIN && y < BOTTOMMARGIN){
    if(x<y && y>125){
      Serial.println("left");
    }else{
      Serial.println("up");
    }
  }else if(x < BOTTOMMARGIN && y < BOTTOMMARGIN){
    if(x>y && x>125){
      Serial.println("down");
    }else{
      Serial.println("left");
    }
  }else if(x>TOPMARGIN){
    Serial.println("right");
  }else if(x<BOTTOMMARGIN){
    Serial.println("left");
  }else if(y>TOPMARGIN){
    Serial.println("down");
  }else if(y<BOTTOMMARGIN){
    Serial.println("up");
  }else{
    Serial.println("stop");
  }
}
