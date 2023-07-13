#include <SoftwareSerial.h>
// PMW PINS
#define m1a 3
#define m1b 5 
#define m2a 6
#define m2b 11


char val;
SoftwareSerial bluetoothSerial(9, 10); // RX, TX

void setup() 
{  
pinMode(m1a, OUTPUT);  
pinMode(m1b, OUTPUT);  
pinMode(m2a, OUTPUT); 
pinMode(m2b, OUTPUT); 
bluetoothSerial.begin(9600);
}

void loop()
{
  while (bluetoothSerial.available() > 0)
  {
  val = bluetoothSerial.read();
  }
   switch (val) {
// Forward
case 'F':
      FORWARD();     
      break;
       
// Backward     
case 'B':
      BACKWARD();
      break;

//left done
case 'L':
      LEFT();
      break;

//right done 
case 'R':
    RIGHT();
    break;

//Stop 
case 'S':
    STOP();
    break;

//Forward Right 
case 'I':
    FORWARDRIGHT();
    break;

//Backward Right 
case 'J':
    BACKWARDRIGHT();
    break;

//Forward Left 
case 'G':
    FORWARDLEFT();
    break;

//Backward Left 
case 'H':
    BACKWARDLEFT();
    break;

}
}
void FORWARD()
  {
     digitalWrite(m1b, LOW);
     digitalWrite(m1a, HIGH);
     digitalWrite(m2b, LOW);
     digitalWrite(m2a, HIGH); 
  }
void BACKWARD()
  {
      digitalWrite(m1b, HIGH);
      digitalWrite(m1a, LOW);
      digitalWrite(m2b, HIGH);
      digitalWrite(m2a, LOW); 
  }
  

void LEFT()
{
    digitalWrite(m1b, LOW);
    digitalWrite(m1a, HIGH);
    digitalWrite(m2b, HIGH);    
    digitalWrite(m2a, LOW);      
}
void RIGHT()
{
    digitalWrite(m1b, HIGH);
    digitalWrite(m1a, LOW);
    digitalWrite(m2b, LOW);
    digitalWrite(m2a, HIGH);
}

void STOP()
{
    digitalWrite(m1b, LOW);
    digitalWrite(m1a, LOW);
    digitalWrite(m2b, LOW);
    digitalWrite(m2a, LOW); 
}

void FORWARDLEFT()
{
    analogWrite(m1b, 0);
    analogWrite(m1a, 255);
    analogWrite(m2b, 0);
    analogWrite(m2a, 80);
 }

void BACKWARDRIGHT()
{
    analogWrite(m1b, 80);
    analogWrite(m1a, 0);
    analogWrite(m2b, 255);
    analogWrite(m2a, 0);
}

void BACKWARDLEFT()
{
   analogWrite(m1b, 255);
    analogWrite(m1a, 0);
    analogWrite(m2b, 80);
    analogWrite(m2a, 0);
}

void FORWARDRIGHT()
{
    analogWrite(m1b, 0);
    analogWrite(m1a, 80);
    analogWrite(m2b, 0);
    analogWrite(m2a, 255);
}