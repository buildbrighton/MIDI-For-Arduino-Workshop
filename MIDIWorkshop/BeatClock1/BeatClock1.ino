// METRONOME
#include <MIDI.h>

#define LED1PIN  13
#define LED4PIN  7

#define SWITCHAPIN  5
#define SWITCHBPIN  2

void setup()
{  
  pinMode(LED1PIN, OUTPUT);
  pinMode(LED4PIN, OUTPUT);
  
  pinMode(SWITCHAPIN, INPUT);
  pinMode(SWITCHBPIN, INPUT);

  digitalWrite(SWITCHAPIN, HIGH);
  digitalWrite(SWITCHBPIN, HIGH);  
  
  MIDI.begin(MIDI_CHANNEL_OMNI);    
}

unsigned long nextClockTime = 0;
int clockDelay = 20;
int tickCount = 0;
byte running = 0;
void loop()
{
  MIDI.read();
  unsigned long milliseconds = millis();
  if(milliseconds > nextClockTime)
  {
    if(running)
      MIDI.sendRealTime(Clock);
    
    nextClockTime = milliseconds + clockDelay;
    tickCount = tickCount + 1;
    if(tickCount > 23)
    {
      tickCount = 0;
      digitalWrite(LED1PIN,HIGH);
    }
    else
    {
      digitalWrite(LED1PIN,LOW);
    }
  }      
  else if(digitalRead(SWITCHAPIN) == LOW)
  {
      if(!running)
      {
        MIDI.sendRealTime(Start);
        tickCount = 0;
        running = 1;
        digitalWrite(LED4PIN,HIGH);
      }
  }
  else if(digitalRead(SWITCHBPIN) == LOW)
  {
      if(running)
      {
        MIDI.sendRealTime(Stop);
        running = 0;
        digitalWrite(LED4PIN,LOW);
      }
  }
  else
  {
    clockDelay = analogRead(0) / 10;
  }
}
