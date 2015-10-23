import processing.serial.*;

int readings[] = {0,0,0};
Serial myport;
int _colorR=255;
int _colorG=255;
int _colorB=255;
int temperature;

void setup(){
  size(200,200);
  noLoop();
  printArray(Serial.list());
  myport=new Serial(this,Serial.list()[3],9600);
  
  myport.bufferUntil('*');
}

void draw(){
  background(0);
  fill(_colorR,_colorG,_colorB);
  ellipse(readings[0],readings[1],30,40);
  temperature = readings[2];
  changeColorByTemperature(temperature);
}

void serialEvent(Serial s){
  readings=int(trim(split(s.readString(),';')));
  redraw=true;
}

void changeColorByTemperature(int temperature){
  int colored = convertTempToColor(temperature);
  _colorR=int(colored);
  _colorG=int(0);
  _colorB=int(255-colored);
}

int convertTempToColor(int temperature){
  if(temperature == 26)
    return 0;
  if(temperature == 27)
    return 63;
  if(temperature == 28)
    return 127;
  if(temperature == 29)
    return 190;
  if(temperature == 30)
    return 255;
  else
    return 0;
}