import processing.serial.*;

int readings[] = {0,0,0};
Serial myport;
int _colorR=255;
int _colorG=255;
int _colorB=255;
int temperature;

void setup(){
  size(800,800);
  noLoop();
  printArray(Serial.list());
  myport=new Serial(this,Serial.list()[3],9600);
  
  myport.bufferUntil('*');
}

void draw(){
  background(0);
  fill(_colorR,_colorG,_colorB);
  rect(30,75,readings[0]*2,500);
  
}

void serialEvent(Serial s){
  readings=int(trim(split(s.readString(),';')));
  redraw=true;
}