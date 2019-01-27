
String bitstring = "10000011000010100001111111101010101";
String stringout = "";

void setup() {
  Serial.begin(115200);


  Serial.println(bits2string(bitstring));

//  Serial.println(stringout);
}

void loop() {
}

String bits2string(String bitsinput){
    String outputstring = "";
    int bitslength = bitsinput.length();
    if(bitslength%7 ==0){
      Serial.println("bit length divisible by 7");
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
