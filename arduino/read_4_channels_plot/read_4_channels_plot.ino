
int enablepin = 600;
int bytepin = 600;
int bitpin = 600;
int datapin = 600;


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
  
  Serial.print(enablepin);
  Serial.print(",");
  Serial.print(bytepin);
  Serial.print(",");
  Serial.print(bitpin);
   Serial.print(",");
  Serial.println(datapin);
       
  delay(1);
}
