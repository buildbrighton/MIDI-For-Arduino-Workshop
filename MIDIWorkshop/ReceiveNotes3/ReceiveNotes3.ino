// MAJOR TRIAD
#include <MIDI.h>

#define LED1PIN  13

void HandleNoteOn(byte channel, byte pitch, byte velocity) { 
  digitalWrite(LED1PIN,HIGH);
  MIDI.sendNoteOn(pitch, velocity, channel);
  MIDI.sendNoteOn(pitch + 4, velocity, channel);
  MIDI.sendNoteOn(pitch + 7, velocity, channel);  
  digitalWrite(LED1PIN,LOW);
}

void HandleNoteOff(byte channel, byte pitch, byte velocity) { 
  digitalWrite(LED1PIN,HIGH);
  MIDI.sendNoteOff(pitch, velocity, channel);
  MIDI.sendNoteOff(pitch + 4, velocity, channel);
  MIDI.sendNoteOff(pitch + 7, velocity, channel);  
  digitalWrite(LED1PIN,LOW);
}

void setup(void)
{
  pinMode(LED1PIN, OUTPUT);
  
  MIDI.begin(MIDI_CHANNEL_OMNI);    
  MIDI.setHandleNoteOn(HandleNoteOn); 
  MIDI.setHandleNoteOff(HandleNoteOff); 
}

void loop()
{
  MIDI.read();
}
