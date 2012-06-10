
void setup()
{
  Serial.begin(31250);
}

void loop()
{
  Serial.write((byte)0x90); 
  Serial.write((byte)0x30); 
  Serial.write((byte)0x7f); 

  delay(200);
  
  Serial.write((byte)0x90); 
  Serial.write((byte)0x30); 
  Serial.write((byte)0x00); 

  delay(200);
  
}
