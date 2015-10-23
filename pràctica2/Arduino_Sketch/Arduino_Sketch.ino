
#include  "DHT.h"           //Library Import  
    
#define DHTPIN  4         // DHT Pin 
#define DHTTYPE DHT11     //  DHT 11    
DHT dht(DHTPIN, DHTTYPE); //Object

int vertical = A1;      // select the input pin for the vert
int horizontal = A0;

void setup(){
  Serial.begin(9600);
  dht.begin(); 
}

void loop(){
 int valX = analogRead(horizontal);
 int valY = analogRead(vertical);

 int cx = map(valX,0,1023,0,199);
 int cy = map(valY,0,1023,0,199);

 int temperature = dht.readTemperature();  //Temperature read
 
 Serial.print(cx);Serial.print(';');
 Serial.print(cy);Serial.print(';');
 Serial.print(temperature);Serial.print(';');
 Serial.print("*");
 
 delay(100);
}
