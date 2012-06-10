#define LED1PIN  13
#define LED2PIN  11
#define LED3PIN  9
#define LED4PIN  7
#define LED5PIN  12
#define LED6PIN  10
#define LED7PIN  8
#define LED8PIN  6

#define SWITCHAPIN  5
#define SWITCHBPIN  2

void setup()
{
  pinMode(LED1PIN, OUTPUT);
  pinMode(LED2PIN, OUTPUT);
  pinMode(LED3PIN, OUTPUT);
  pinMode(LED4PIN, OUTPUT);
  pinMode(LED5PIN, OUTPUT);
  pinMode(LED6PIN, OUTPUT);
  pinMode(LED7PIN, OUTPUT);
  pinMode(LED8PIN, OUTPUT);
  
  pinMode(SWITCHAPIN, INPUT);
  pinMode(SWITCHBPIN, INPUT);

  digitalWrite(SWITCHAPIN, HIGH);
  digitalWrite(SWITCHBPIN, HIGH);

  Serial.begin(31250);  
}

void sendNote(byte note, byte velocity)
{
  Serial.write((byte)0x90);
  Serial.write(note);
  Serial.write(velocity);
}

void sendController(byte cc, byte value)
{
  Serial.write((byte)0xB0);
  Serial.write(cc);
  Serial.write(value);
}

void sendPitchBend(int value)
{  
  Serial.write((byte)0xE0);
  Serial.write(value % 128);
  Serial.write(value / 128);
}

byte notes[8] = {
  48,
  48,
  47,
  48,
  48,
  48,
  51,
  48
};


byte playIndex = 0;
byte lastNote = 0;
byte isRunning = 0;
int lastModWheel = 0;
int lastPitchBend = 0;

unsigned long nextNoteTime = 0;

void loop()
{
  if(isRunning)
  {
    unsigned long thisTime = millis();
    if(thisTime > nextNoteTime)
    {
      if(lastNote > 0)
        sendNote(lastNote, 0);
        
      byte thisNote = notes[playIndex];
      sendNote(thisNote, 127);        
      lastNote = thisNote;
      nextNoteTime = thisTime + 200;      
      
      digitalWrite(LED1PIN, (playIndex == 0) ? HIGH: LOW);
      digitalWrite(LED2PIN, (playIndex == 1) ? HIGH: LOW);
      digitalWrite(LED3PIN, (playIndex == 2) ? HIGH: LOW);
      digitalWrite(LED4PIN, (playIndex == 3) ? HIGH: LOW);
      digitalWrite(LED5PIN, (playIndex == 4) ? HIGH: LOW);
      digitalWrite(LED6PIN, (playIndex == 5) ? HIGH: LOW);
      digitalWrite(LED7PIN, (playIndex == 6) ? HIGH: LOW);
      digitalWrite(LED8PIN, (playIndex == 7) ? HIGH: LOW);
      
      playIndex = playIndex + 1;
      if(playIndex >= 8)
        playIndex = 0;
    }
  }
  
  if(digitalRead(SWITCHBPIN) == LOW)
  {
    isRunning= 1;    
  }
  else if(digitalRead(SWITCHAPIN) == LOW && isRunning == 1)
  {
    isRunning = 0;
    if(lastNote > 0)
      sendNote(lastNote, 0);
  }  
  
  int thisModWheel = analogRead(0)/8;
  if(thisModWheel < lastModWheel - 1 || thisModWheel > lastModWheel + 1)
  {
    sendController(1, thisModWheel) ;
    lastModWheel = thisModWheel;
  }

  int thisPitchBend = analogRead(1)*16;
  thisPitchBend = constrain(thisPitchBend, 0, 16383);
  if(thisPitchBend < lastPitchBend - 100 || thisPitchBend > lastPitchBend + 100)
  {
    sendPitchBend(thisPitchBend) ;
    lastPitchBend = thisPitchBend;
  }

}
