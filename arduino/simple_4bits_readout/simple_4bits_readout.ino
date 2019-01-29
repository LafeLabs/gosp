
int enablepin = 600;
int enablebit = 0;
int bytepin = 600;
int bytebit = 0;
int bitpin = 600;
int bitbit = 0;
int datapin = 600;
int databit = 0;


void setup() {
  Serial.begin(115200);
  enablepin = analogRead(A5);  //top rectangle in the browser
  bytepin = analogRead(A4);  //does nothing in this version of code, is for verification
  bitpin = analogRead(A3);  // this is essentially a clock
  datapin = analogRead(A2); //bottom rectangle in the browser 

}

void loop() {
  
  enablepin = analogRead(A5);  
  bytepin = analogRead(A4);  
  bitpin = analogRead(A3);  
  datapin = analogRead(A2);  

  if(enablepin < 500){
    enablebit = 1;
  }
  else{
    enablebit = 0;
  }
  
  if(bytepin < 500){
    bytebit = 1;
  }
  else{
    bytebit = 0;
  }
  
  if(bitpin < 500){
    bitbit = 1;
  }
  else{
    bitbit = 0;
  }
  
  if(datapin < 500){
    databit = 1;
  }
  else{
    databit = 0;
  }

  Serial.print(enablebit);
  Serial.print(bytebit);  
  Serial.print(bitbit);
  Serial.println(databit);

       
  delay(1);
}
