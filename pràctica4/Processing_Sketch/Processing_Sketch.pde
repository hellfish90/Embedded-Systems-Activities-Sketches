import processing.serial.*;

int readings[] = {0,0};
Serial myport;
int _colorR=255;
int _colorG=255;
int _colorB=255;

void setup(){
  size(200,200);
  noLoop();
  printArray(Serial.list());
  myport=new Serial(this,Serial.list()[1],9600);
  myport.bufferUntil('*');
}

void draw(){
  background(0);
  fill(_colorR,_colorG,_colorB);
  ellipse(readings[1],readings[0],30,40);
  printArray(readings);
}

void serialEvent(Serial s){
  readings=int(trim(split(s.readString(),';')));
  redraw=true;
}

void mouseClicked(){
  _colorR=int(random(255));
  _colorG=int(random(255));
  _colorB=int(random(255));
}