import processing.serial.*; 
 
Serial myPort;
PFont typo;
String inString;
int lf = 10;

void setup() { 
  size(1200,800); 
  typo = loadFont("InputMono-Regular-16.vlw"); 
  textFont(typo, 16); 
  
  print(Serial.list()[0]);
  myPort = new Serial(this, Serial.list()[0], 9600); 
  myPort.bufferUntil(lf); 
} 
 
void draw() { 
  background(0); 
  textFont(typo);
  text("received: " + inString, 10,50); 
  
  for(int i=0;i<tabVal.length;i++){
    text("> AN"+i+"  "+tabVal[i],20, 100+i*40);
    fill(255);
    rect(150,80+i*40,tabVal[i],30);
  }
  
} 
 
int [] tabVal = new int[6];
 
void serialEvent(Serial p) { 
  inString = p.readString(); 
  String [] tab = split(inString,"|");
  
  if(tab.length>=6)
  for(int i=0;i<6;i++){
    tabVal[i] = int(float(tab[i]));
  }
  
} 