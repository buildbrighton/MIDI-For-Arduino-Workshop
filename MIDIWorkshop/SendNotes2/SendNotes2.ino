// SEND NOTE WHEN A BUTTON IS PRESSED
#define LED1PIN  13
#define SWITCHAPIN  5

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

int wasPressed = 0;

void loop()
{
  // is switch A currently held down?
  if(digitalRead(SWITCHAPIN) == LOW) 
  {    
    // has it just been pressed?
    if(wasPressed == 0)
    {
      sendNote(48,127);
      digitalWrite(LED1PIN, HIGH);
      wasPressed = 1;
    }
  }
  else
  {
    // has it just been released?
    if(wasPressed == 1)
    {
      sendNote(48,0);
      digitalWrite(LED1PIN, LOW);
      wasPressed = 0;
    }
  }  
}
