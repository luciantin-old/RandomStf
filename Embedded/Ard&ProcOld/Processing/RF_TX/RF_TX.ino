
void setup(){
  pinMode(2, OUTPUT);
}

void loop(){
  
 
  rf_send('T');
  rf_send('I');
  rf_send('N');
 
  rf_send('#');
  delay(5000);
  //v++;
}

void rf_send(byte input){
  int i;
  
  for(i=0; i<20; i++){
  digitalWrite(2, HIGH);
  delayMicroseconds(500);
  digitalWrite(2, LOW);
  delayMicroseconds(500);
}

  digitalWrite(2, HIGH);
  delayMicroseconds(3000);
  digitalWrite(2, LOW);
  delayMicroseconds(500);
  
    
  for(i=0; i<8; i++){
  if(bitRead(input,i)==1)
  digitalWrite(2, HIGH);
  else
  digitalWrite(2, LOW);
  delayMicroseconds(500);
  
  if(bitRead(input,i)==1)
  digitalWrite(2, LOW);
  else
  digitalWrite(2, HIGH);
  delayMicroseconds(500);
}//i

  
  digitalWrite(2, LOW);
}



