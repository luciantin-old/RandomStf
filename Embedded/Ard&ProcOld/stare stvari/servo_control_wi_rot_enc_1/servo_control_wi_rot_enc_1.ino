
int brightness = 90;   
int fadeAmount = 10;   
unsigned long currentTime;
unsigned long loopTime;
const int pin_A = 12;  
const int pin_B = 11;  
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev=0;
#include <Servo.h> 
Servo myservo;  
void setup()  {
  myservo.attach(9);
  
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);
  currentTime = millis();
  loopTime = currentTime; 
 Serial.begin (9600);
} 

void loop()  {
  // get the current elapsed time
  currentTime = millis();
  if(currentTime >= (loopTime + 5)){
    // 5ms since last check of encoder = 200Hz  
    encoder_A = digitalRead(pin_A);    // Read encoder pins
    encoder_B = digitalRead(pin_B);   
    if((!encoder_A) && (encoder_A_prev)){
      // A has gone from high to low 
      if(encoder_B) {
        // B is high so clockwise
        // increase the brightness, dont go over 255
        if(brightness + fadeAmount <= 180) brightness += fadeAmount;               
      }   
      else {
        // B is low so counter-clockwise      
        // decrease the brightness, dont go below 0
        if(brightness - fadeAmount >= -9) brightness -= fadeAmount;               
      }   

    }   
    encoder_A_prev = encoder_A;     // Store value of A for next time    
   
  
    loopTime = currentTime;  // Updates loopTime
  }
  // Other processing can be done here
   Serial.println (brightness);
   myservo.write(brightness);                          
}

