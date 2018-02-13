
/*  arduinoMain.ino
 *  Title: EE175ABC - Senior Design Project: Variable Brightness RGB Persistence of Vision Display
 *
 *  Name & E-mail: Calvin Nguyen - cnguy072@ucr.edu
 *  Partner(s) Name & E-mail: Christopher Dube - cdube001@ucr.edu
 *  Partner(s) Name & E-mail: Benson Ninh - bninh001@ucr.edu
 */


int analogSet = 232; //91%
int analogOut = 0;
int ledPin = 9; // D9 
int magPin = 2; // D2 
int getNum = 0;
int delayVar = 100;
int mag = 0;

/*void getMag() {
  mag = digitalRead(magPin);
  Serial.print("Mag: ");
  Serial.println(mag);
} */

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(magPin, INPUT);
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Ready,");
  analogWrite(ledPin, analogOut);
}

void loop() {
  /*while(1) {
    getMag();
  }*/
  // put your main code here, to run repeatedly:
  while(getNum == 1) {
    Serial.print("Enter analog # (0-255): ");
    while(!Serial.available()) {}
    if(Serial.available()) {
      analogSet = Serial.parseInt();
      Serial.print(">> ");
      Serial.println(analogSet);
      getNum = 0;
    }
    if (analogSet > 255) analogSet = 255;
    if (analogSet < 0) analogSet = 0;
  }
  
  Serial.print("Speed: ");
  Serial.println(analogOut);
  analogWrite(ledPin, analogOut);
  
  if(analogOut < analogSet) {
    analogOut++;
  }
  else if (analogOut > analogSet) {
    analogOut--;
  }
  else if (analogOut == analogSet) getNum = 1;
 
  if (analogOut < 125) delayVar = 50;
  else delayVar = 100;
  delay(delayVar);
}
