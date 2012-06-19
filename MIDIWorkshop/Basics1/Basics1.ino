//
// BLINK THE LED ON DIGITAL PIN 13
//

void setup()
{
  // set pin 13 to be a digital output
  pinMode(13, OUTPUT);
}

void loop()
{
  // turn the LED on
  digitalWrite(13,HIGH);
  
  // wait half a second
  delay(500);
  
  // turn the LED off again
  digitalWrite(13,LOW);
  
  // turn the LED on
  delay(500);
}
