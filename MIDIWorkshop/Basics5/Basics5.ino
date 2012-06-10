
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Pot reads : ");
  Serial.print(analogRead(0));
  Serial.print(", LDR reads : ");
  Serial.println(analogRead(1));
  
  delay(100);  
    
}
