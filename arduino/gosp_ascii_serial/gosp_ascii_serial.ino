
int enablepin = 600;
int enablebit = 0;
int bytepin = 600;
int bytebit = 0;
int bitpin = 600;
int bitbit = 0;
int datapin = 600;
int databit = 0;

int prevenablebit = 0;
int prevbytebit = 0;
int prevbitbit = 0;
int integrateddata = 0;

String bitstring = "";
String outputstring = "";

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
    integrateddata++;
  }
  else{
    databit = 0;
  }

  if(enablebit == 1 && prevenablebit ==0){
   // Serial.println("BEGIN ENABLE"); 
  }
  if(enablebit == 0 && prevenablebit == 1){
 //    Serial.println("END ENABLE");
//    Serial.println("");
 //   Serial.println(bitstring);
  //  bitstring = "";
  
//      Serial.println(bitstring);
      bitstring = "";
      Serial.println(outputstring);
      outputstring = "";
  }
  if(bytebit == 1 && prevbytebit ==0){
    //Serial.println("            BEGIN BYTE"); 
  //  Serial.println("");
  //  Serial.println(bitstring);
  //  bitstring = "";
  }
  if(bytebit == 0 && prevbytebit == 1){
    // Serial.println("            END BYTE");
    Serial.println(bitstring);
    outputstring += bits2string(bitstring);
    bitstring = "";
  }
  if(bitbit == 1 && prevbitbit ==0){
//    Serial.println("                        BEGIN BIT"); 
    integrateddata = 0;
  }
  if(bitbit == 0 && prevbitbit == 1){
  //  Serial.println("                        END BIT");
    if(integrateddata > 2){
     // Serial.print("1");
      bitstring += "1";
    }
    else{
     // Serial.print("0");
      bitstring += "0";
    }
  }

  prevenablebit = enablebit;  
  prevbytebit = bytebit;
  prevbitbit = bitbit;
       
  delay(1);
}


String bits2string(String bitsinput){
    String outputstring = "";
    int bitslength = bitsinput.length();
    if(bitslength%7 ==0){
     // Serial.println("bit length divisible by 7");
      int numbytes = bitslength/7;
      for(int byteindex = 0;byteindex < numbytes;byteindex++){
           float foo = 0.0;
           for(int bitindex = 0;bitindex < 7;bitindex++){
              if(bitsinput.charAt(byteindex*7 + bitindex) == '1'){
                  foo += pow(2,6 - bitindex);
              }
           }
           int bar = int(round(foo));
          // Serial.println(bar);
           char zeep = char(bar);
           outputstring.concat(zeep);
           
      }
    }
    else{
      Serial.println("ERROR: bit length not divisible by 7");
    }

      return outputstring;
}
