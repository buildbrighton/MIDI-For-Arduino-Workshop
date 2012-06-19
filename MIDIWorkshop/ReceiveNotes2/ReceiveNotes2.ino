#include <MIDI.h>

#define LED1PIN  13
#define LED2PIN  11
#define LED3PIN  9
#define LED4PIN  7
#define LED5PIN  12
#define LED6PIN  10
#define LED7PIN  8
#define LED8PIN  6


void setLED(byte note, byte value)
{
  switch(note)
  {
    case 48: digitalWrite(LED1PIN, value); break;
    case 49: digitalWrite(LED2PIN, value); break;
    case 50: digitalWrite(LED3PIN, value); break;
    case 51: digitalWrite(LED4PIN, value); break;
    case 52: digitalWrite(LED5PIN, value); break;
    case 53: digitalWrite(LED6PIN, value); break;
    case 54: digitalWrite(LED7PIN, value); break;
    case 55: digitalWrite(LED8PIN, value); break;
  }
}

void HandleNoteOn(byte channel, byte pitch, byte velocity) { 
  setLED(pitch, velocity);
}

void HandleNoteOff(byte channel, byte pitch, byte velocity) { 
  setLED(pitch, 0);
}

void setup(void)
{
  pinMode(LED1PIN, OUTPUT);
  pinMode(LED2PIN, OUTPUT);
  pinMode(LED3PIN, OUTPUT);
  pinMode(LED4PIN, OUTPUT);
  pinMode(LED5PIN, OUTPUT);
  pinMode(LED6PIN, OUTPUT);
  pinMode(LED7PIN, OUTPUT);
  pinMode(LED8PIN, OUTPUT);  
  
  MIDI.begin(MIDI_CHANNEL_OMNI);    
  MIDI.setHandleNoteOn(HandleNoteOn); 
  MIDI.setHandleNoteOff(HandleNoteOff); 
}

void loop()
{
  MIDI.read();
}
