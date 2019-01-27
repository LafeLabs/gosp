
int enablepin = 600;
int integratedenable = 0;
int bytepin = 600;
int integratedbyte = 0;
int bitpin = 600;
int integratedbit = 0;
int datapin = 600;
int integrateddata = 0;
String bitstring = "";
//when a pin goes to LOW, it means it's a 1 which is black pixels on a white screen


void setup() {
  Serial.begin(115200);
  enablepin = analogRead(A2);  
  bytepin = analogRead(A3);  
  bitpin = analogRead(A4);  
  datapin = analogRead(A5);  

}

void loop() {
  
  enablepin = analogRead(A2);  
  bytepin = analogRead(A3);  
  bitpin = analogRead(A4);  
  datapin = analogRead(A5);  

  if(bitpin < 20){  //are we in a bit? if so, add up bit and add up data if data is running(<20)
      integratedbit++;
      if(datapin < 20){//is data line enabled?
          integrateddata++;  //if it is, integrate up
      }
  }
  else{ //we are NOT in  a bit so...
      if(integratedbit > 25){  //were we in a bit a minute ago?
         //this means we've gone a whole bit but now ended the bit, so test for data
         if(integrateddata > 25){
            bitstring += "1";
        //    Serial.println("1");
         }
         else{
            bitstring += "0";
            //Serial.println("0");          
         }
         integratedbit = 0; 
         integrateddata = 0;

      }
      else{
        //this is just the dead zone, not in a bit, weren't in a bit
      }
  }

  if(bytepin < 20){//in a byte?
    integratedbyte++;
  }
  else{//not in a byte
    if(integratedbyte > 25){ //were we in a byte a minute ago?
        integratedbyte = 0;//we're not anymore, set that to be the case
    }
  }
  


  if(enablepin < 20){//is enable pin on ?  
    integratedenable++; //if it is add up integral of enable
  }
  else{//enable is now off
    if(integratedenable > 100){
        if(integratedbit > 25){  //were we in a bit a minute ago?
         //this means we've gone a whole bit but now ended the bit, so test for data
         if(integrateddata > 25){
            bitstring += "1";
        //    Serial.println("1");
         }
         else{
            bitstring += "0";
            //Serial.println("0");          
         }
         integratedbit = 0; 
         integrateddata = 0;

      }

      

       Serial.println(bitstring);
       integratedenable = 0;
       bitstring = "";
       integratedbit = 0;
       integrateddata = 0;
       
    }
  }

  delay(1);
}
