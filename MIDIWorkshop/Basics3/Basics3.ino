
// define names for the pins
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

void setup()
{
  
  // these pins, for the LEDs, are outputs
  pinMode(LED1PIN, OUTPUT);
  pinMode(LED2PIN, OUTPUT);
  pinMode(LED3PIN, OUTPUT);
  pinMode(LED4PIN, OUTPUT);
  pinMode(LED5PIN, OUTPUT);
  pinMode(LED6PIN, OUTPUT);
  pinMode(LED7PIN, OUTPUT);
  pinMode(LED8PIN, OUTPUT);
  
  // but these pins, for the switches, are inputs
  pinMode(SWITCHAPIN, INPUT);
  pinMode(SWITCHBPIN, INPUT);
  pinMode(SWITCHCPIN, INPUT);
  pinMode(SWITCHDPIN, INPUT);

  // these lines turn on the "internal pull-ups" for the switch inputs
  digitalWrite(SWITCHAPIN, HIGH);
  digitalWrite(SWITCHBPIN, HIGH);
  digitalWrite(SWITCHCPIN, HIGH);
  digitalWrite(SWITCHDPIN, HIGH);
  
}

void loop()
{
  // if switch A is pressed down right now
  if(digitalRead(SWITCHAPIN) == LOW) 
  {
    // turn leds 1+2 on 
    digitalWrite(LED1PIN, HIGH);
    digitalWrite(LED2PIN, HIGH);
  }
  else
  {
    // turn leds 1+2 off
    digitalWrite(LED1PIN, LOW);
    digitalWrite(LED2PIN, LOW);
  }
  
  // if switch B is pressed down right now
  if(digitalRead(SWITCHBPIN) == LOW) 
  {
    // turn leds 3+4 on     
    digitalWrite(LED3PIN, HIGH);
    digitalWrite(LED4PIN, HIGH);
  }
  else
  {
    // turn leds 3+4 off     
    digitalWrite(LED3PIN, LOW);
    digitalWrite(LED4PIN, LOW);
  }

  // if switch C is pressed down right now
  if(digitalRead(SWITCHCPIN) == LOW) 
  {
    // turn leds 5+6 on
    digitalWrite(LED5PIN, HIGH);
    digitalWrite(LED6PIN, HIGH);
  }
  else
  {
    // turn leds 5+6 off
    digitalWrite(LED5PIN, LOW);
    digitalWrite(LED6PIN, LOW);
  }

  // if switch D is pressed down right now
  if(digitalRead(SWITCHDPIN) == LOW) 
  {
    // turn leds 7+8 on
    digitalWrite(LED7PIN, HIGH);
    digitalWrite(LED8PIN, HIGH);
  }
  else
  {
    // turn leds 7+8 off
    digitalWrite(LED7PIN, LOW);
    digitalWrite(LED8PIN, LOW);
  }  
}
