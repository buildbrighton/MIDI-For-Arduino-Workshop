// ARPEGGIATOR
#include <MIDI.h>
byte noteOn[128] = {0};

void HandleNoteOn(byte channel, byte pitch, byte velocity) 
{ 
  noteOn[pitch] = velocity;
}

void HandleNoteOff(byte channel, byte pitch, byte velocity) 
{ 
  noteOn[pitch] = 0;
}

void setup(void)
{
  MIDI.begin(MIDI_CHANNEL_OMNI);    
  MIDI.turnThruOff();
  MIDI.setHandleNoteOn(HandleNoteOn); 
  MIDI.setHandleNoteOff(HandleNoteOff); 
}

unsigned long nextNoteTime = 0;
byte lastNotePlayed = 0;

void loop()
{
  MIDI.read();
  if(millis() > nextNoteTime)
  {
    nextNoteTime = millis() + 100;
    int thisNote = lastNotePlayed;
    if(lastNotePlayed > 0)
    {
      MIDI.sendNoteOff(lastNotePlayed, 0, 1);
      lastNotePlayed = 0;
    }
    for(int i=0; i<255; ++i)
    {
      thisNote = thisNote + 1;
      if(thisNote > 127)
        thisNote = 1;
      if(noteOn[thisNote] > 0)
      {          
        MIDI.sendNoteOn(thisNote, 127, 1);
        lastNotePlayed = thisNote;
        break;
      }
   }
  }
}
