
int enablepin = 600;
int enablebit = 0;
int bytepin = 600;
int bytebit = 0;
int bitpin = 600;
int bitbit = 0;
int datapin = 600;
int databit = 0;

int endbit = 0;
int prevbitbit = 0;
int integratedData = 0;

int endenable = 0;
int prevenablebit = 0;

String bitString = "";

void setup() {
  Serial.begin(115200);
  enablepin = analogRead(A5);  //top rectangle in the browser
  bytepin = analogRead(A4);  //does nothing in this version of code, is for verification
  bitpin = analogRead(A3);  // this is essentially a clock
  datapin = analogRead(A2); //bottom rectangle in the browser 
}

void loop() {


  //later this whole thing should go in an if statement based on another digital input pin that's pulled high, 
  //switch to ground

  //one digital input is this, one digital output is the drive enable for vibrational or rotational tool, and 
  //12 are the 3 steppers for xyz fro a total of 12 + 2 = 14
  
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

  if(bitbit == 0 && prevbitbit == 1){
      endbit = 1;
  }
  else{
      endbit = 0;
  }

  if(bitbit == 1){
     if(databit == 1){
        integratedData += 1;
      }
   }
   if(endbit == 1){
      if(integratedData > 4){
          bitString.concat("1");
      }
      else{
          bitString.concat("0");
      }
      integratedData = 0;
   }

  prevbitbit = bitbit;

  if(enablebit == 0 && prevenablebit == 1){
    endenable = 1;
  }
  else{
    endenable = 0;
  }

  
  prevenablebit = enablebit;

  if(endenable == 1){
      Serial.println(bitString);
      Serial.println("end string");
      bitString = "";
  }
  
  delay(1);

}
