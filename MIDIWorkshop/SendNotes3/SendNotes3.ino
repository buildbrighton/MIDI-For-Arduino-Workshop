
#define LED1PIN  13
#define LED2PIN  11
#define LED3PIN  9
#define LED4PIN  7

#define SWITCHAPIN  5
#define SWITCHBPIN  2
#define SWITCHCPIN  4
#define SWITCHDPIN  3

void setup()
{
  pinMode(LED1PIN, OUTPUT);
  pinMode(LED2PIN, OUTPUT);
  pinMode(LED3PIN, OUTPUT);
  pinMode(LED4PIN, OUTPUT);
  
  pinMode(SWITCHAPIN, INPUT);
  pinMode(SWITCHBPIN, INPUT);
  pinMode(SWITCHCPIN, INPUT);
  pinMode(SWITCHDPIN, INPUT);

  digitalWrite(SWITCHAPIN, HIGH);
  digitalWrite(SWITCHBPIN, HIGH);
  digitalWrite(SWITCHCPIN, HIGH);
  digitalWrite(SWITCHDPIN, HIGH);

  Serial.begin(31250);  
}

void sendNote(byte note, byte velocity)
{
  Serial.write((byte)0x90);
  Serial.write(note);
  Serial.write(velocity);
}


byte wasPressed[4];

void handleButton(byte which, byte inputPin, byte outputPin, byte note)
{
  if(digitalRead(inputPin) == LOW) 
  {
    digitalWrite(outputPin, HIGH);
    if(wasPressed[which] == 0)
    {
      sendNote(note,127);
      wasPressed[which] = 1;
    }
  }
  else
  {
    digitalWrite(outputPin, LOW);
    if(wasPressed[which] == 1)
    {
      sendNote(note,0);
      wasPressed[which] = 0;
    }
  }  
  
}

void loop()
{
  handleButton(0, SWITCHAPIN, LED1PIN, 48);
  handleButton(1, SWITCHBPIN, LED2PIN, 50);
  handleButton(2, SWITCHCPIN, LED3PIN, 52);
  handleButton(3, SWITCHDPIN, LED4PIN, 53);
}
