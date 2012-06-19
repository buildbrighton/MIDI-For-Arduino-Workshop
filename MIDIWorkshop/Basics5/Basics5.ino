
void setup()
{
  // set up the serial port to 9,600 bits per second
  Serial.begin(9600);
}

void loop()
{
  // write out the analog values from pot and LDR
  Serial.print("Pot reads : ");
  Serial.print(analogRead(0));
  Serial.print(", LDR reads : ");
  Serial.println(analogRead(1));
  
  delay(100);  
    
}
