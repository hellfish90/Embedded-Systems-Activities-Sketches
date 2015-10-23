import processing.serial.*;

float readings[] = {0,0,0};
Serial myport;
int _colorR=255;
int _colorG=255;
int _colorB=255;

void setup(){
  size(300,300,P3D);
  noLoop();
  printArray(Serial.list());
  myport=new Serial(this,Serial.list()[3],9600);
  
  myport.bufferUntil('*');
}

void draw(){
  background(0);
  fill(_colorR,_colorG,_colorB);
  noStroke();
  pushMatrix();
  translate(130, height/2, 0);
  rotateY(readings[0]);
  rotateX(readings[1]);
  box(readings[2]);
  popMatrix();
  //ellipse(readings[0],readings[1],30,40);
}

void serialEvent(Serial s){
  readings=float(trim(split(s.readString(),';')));
  redraw=true;
}