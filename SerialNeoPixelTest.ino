  #include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>
int incomingByte;      // a variable to read incoming serial data into
int prevUsage=0;
int Contrast = 60;
#define PIN      6
#define NUMPIXELS 36
#define Row1 12
#define Row2 24
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/*
void LightUp(int PassedVar){
  pixels.clear();
  for (int i=PassedVar;i>=0;i--){
    pixels.setPixelColor(i,255,0,255);
  }
  pixels.show();
}*/
void FillerInner(int x){
  //scale so that at the first redraw it's halfway to the designated value, then at half-duration its placed at the real designated value.
  //Halfway between the old and the new.*
  for (int i=0;i<x;i++){
    //TODO: ADD IN A SLIDING SCALE, NOT HARD-CODED COLORS..
    /*if (i<4){
      pixels.setPixelColor(i,100,100,0);
    }
    if (i>=4 && i<7){
      pixels.setPixelColor(i,100,64.7,0);
    }
    if (i>7){
      pixels.setPixelColor(i,255,255,0);
    }
    */
    if (i<2){
      pixels.setPixelColor(i,100,100,0);
    }
    if (i>=2 && i<4){
      pixels.setPixelColor(i,100,64.7,0);
    }
    if (i>=4){
      pixels.setPixelColor(i,255,0,0);
    }
    
  } 
  pixels.show();
}
void FillerInnerMemory(int p){
  //scale so that at the first redraw it's halfway to the designated value, then at half-duration its placed at the real designated value.
  //Halfway between the old and the new.*
  for (int i=13;i<p;i++){
    //TODO: ADD IN A SLIDING SCALE, NOT HARD-CODED COLORS..
    /*if (i<4){
      pixels.setPixelColor(i,100,100,0);
    }
    if (i>=4 && i<7){
      pixels.setPixelColor(i,100,64.7,0);
    }
    if (i>7){
      pixels.setPixelColor(i,255,255,0);
    }
    */
    if (i<2){
      pixels.setPixelColor(i,100,100,0);
    }
    if (i>=2 && i<4){
      pixels.setPixelColor(i,100,64.7,0);
    }
    if (i>=4){
      pixels.setPixelColor(i,255,0,0);
    }
    
  } 
  pixels.show();
} //END OF OUTER CIRCLE FILLER

void Looper(int RotationSpeed) { //INITIALIZATION COLOR SEQUENCE
    pixels.clear(); //COMMENTED OUT TO HAVE WHITE ONE, THIS IS COLOR
    for (int i=0;i<35;i++){ /////THIS LOOKS COOL BY ITSELF
      pixels.setPixelColor(i,255,255,255);
      pixels.setPixelColor(((i-1)+12)%12,255,255,255);
      pixels.setPixelColor(((i-2)+12)%12,255,255,255);
      pixels.setPixelColor(((i-3)+12)%12,255,255,255);
      pixels.setPixelColor(((i-4)+12)%12,255,255,255);
      pixels.setPixelColor(((i-5)+12)%12,0,0,0);    
    pixels.show();
    delay(RotationSpeed);
    /*
    for (int i=0;i<35;i++){ /////THIS LOOKS COOL BY ITSELF
      pixels.setPixelColor(i,255,255,255);
      pixels.setPixelColor(((i-1)+36)%36,255,0,255);
      pixels.setPixelColor(((i-2)+36)%36,255,0,255);
      pixels.setPixelColor(((i-3)+36)%36,255,0,255);
      pixels.setPixelColor(((i-4)+36)%36,255,0,255);
      pixels.setPixelColor(((i-5)+36)%36,0,0,0);    
    pixels.show();
    delay(RotationSpeed);
    */
  }
}
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pixels.begin();
  pixels.clear();
  int incomingByte=0;
 /* analogWrite(7, Contrast);
  lcd.begin(16, 2);
  lcd.setCursor(0,0); //init process
  lcd.print("Loading...");*/
  Looper(50);
  Looper(50);
  Looper(50);
  pixels.clear();
  pixels.show();
  
}

void loop() {
  // see if there's incoming serial data:
  lcd.setCursor(0, 0); 

  lcd.print(incomingByte);//if I have the incoming byte available, print it to the lcd.
  
  lcd.setCursor(0, 1);
  lcd.print("Celsius");
  pixels.clear();
  while (Serial.available() < 0) {
    pixels.setPixelColor(0,255,255,255);
    pixels.show();
  }
  //if (Serial.available() > 0) {
  // read the oldest byte in the serial buffer:
  incomingByte = Serial.read();

  //if (incomingByte='H'){
    //pixels.setPixelColor(0,255,255,255);
  //}
  switch (incomingByte){
    case 'A':
    FillerInner(1);
    break;
    case 'B':
    FillerInner(2);
    break;
    case 'C':
    FillerInner(3);
    break;
    case 'D':
    FillerInner(4);
    break;
    case 'E':
    FillerInner(5);
    break;
    case 'F':
    FillerInner(6);
    break;
    case 'G':
    FillerInner(7);
    break;
    case 'H':
    FillerInner(8);
    break;
    case 'I':
    FillerInner(9);
    break;
    case 'J':
    FillerInner(10);
    break;
    prevUsage=incomingByte;
    case 'Z':
    FillerInner(30); //test not used exce
    break;

}
}
