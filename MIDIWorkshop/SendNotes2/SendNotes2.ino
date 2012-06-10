
#define LED1PIN  13

#define SWITCHAPIN  5

int wasPressed = 0;

void setup()
{
  pinMode(LED1PIN, OUTPUT);

  pinMode(SWITCHAPIN, INPUT);

  digitalWrite(SWITCHAPIN, HIGH);

  Serial.begin(31250);  
}

void sendNote(byte note, byte velocity)
{
  Serial.write((byte)0x90);
  Serial.write(note);
  Serial.write(velocity);
}

void loop()
{
  if(digitalRead(SWITCHAPIN) == LOW) 
  {
    digitalWrite(LED1PIN, HIGH);
    if(wasPressed == 0)
    {
      sendNote(48,127);
      wasPressed = 1;
    }
  }
  else
  {
    digitalWrite(LED1PIN, LOW);
    if(wasPressed == 1)
    {
      sendNote(48,0);
      wasPressed = 0;
    }
  }  
}
