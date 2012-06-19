#include <MIDI.h>

#define KNOB 0
#define LIGHT_SENSOR 1

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
#define SWITCHCPIN  4
#define SWITCHDPIN  3

/**

* Flashes all LEDs separately on startup.
* Turns two LEDs on when each button is pressed
* Listens for MIDI input, repeats notes from any channel on channel 1 with velocity controlled by knob/pot.
* Sends pitch bend for LDR value

**/

int lastVelocity = 0;
int lastPitchBend = 0;

void HandleNoteOn(byte channel, byte pitch, byte velocity) { 
  // Resend note with velocity set by knob.
  MIDI.sendNoteOn(pitch, lastVelocity, 1);
  flash(LED1PIN);
}

void toggleLeds(int switchPin, int ledPin1, int ledPin2){
  boolean pressed = digitalRead(switchPin);
  digitalWrite(ledPin1, !pressed);
  digitalWrite(ledPin2, !pressed);
}

void flash(int led){
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
}

void setup() {
  // Initiate MIDI communications, listen to all channels
  MIDI.begin(MIDI_CHANNEL_OMNI);    

  // Connect the HandleNoteOn function to the library, so it is called upon reception of a NoteOn.
  MIDI.setHandleNoteOn(HandleNoteOn);  // Put only the name of the function

    //init LEDs to output mode
  for(int i = 6; i <=13; i++){
    pinMode(i, OUTPUT);
    flash(i);
  }

  //init buttons to input mode with pullup resistor
  for(int i = 2; i <=5; i++){
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }

}

void loop() {
  // Call MIDI.read the fastest you can for real-time performance.
  MIDI.read();

  int thisVelocity = analogRead(KNOB)/8;
  if(thisVelocity < lastVelocity - 1 || thisVelocity > lastVelocity + 1)
  {
    lastVelocity = thisVelocity;
  }

  int thisPitchBend = analogRead(LIGHT_SENSOR)*16;
  thisPitchBend = constrain(thisPitchBend, 0, 16383);
  if(thisPitchBend < lastPitchBend - 100 || thisPitchBend > lastPitchBend + 100)
  {
    MIDI.sendPitchBend(thisPitchBend, 1);
    lastPitchBend = thisPitchBend;
  }

  toggleLeds(SWITCHAPIN, LED1PIN, LED2PIN);
  toggleLeds(SWITCHBPIN, LED3PIN, LED4PIN);
  toggleLeds(SWITCHCPIN, LED5PIN, LED6PIN);
  toggleLeds(SWITCHDPIN, LED7PIN, LED8PIN);
}


