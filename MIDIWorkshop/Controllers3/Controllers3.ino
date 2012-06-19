#define SWITCHAPIN  5
#define SWITCHBPIN  2
#define SWITCHCPIN  4
#define SWITCHDPIN  3

void setup()
{
  Serial.begin(31250);  
  
  pinMode(SWITCHAPIN, INPUT);
  pinMode(SWITCHBPIN, INPUT);
  pinMode(SWITCHCPIN, INPUT);
  pinMode(SWITCHDPIN, INPUT);

  digitalWrite(SWITCHAPIN, HIGH);
  digitalWrite(SWITCHBPIN, HIGH);
  digitalWrite(SWITCHCPIN, HIGH);
  digitalWrite(SWITCHDPIN, HIGH);  
}

void sendController(byte cc, byte value)
{
  Serial.write((byte)0xB0);
  Serial.write(cc);
  Serial.write(value);
}

int lastValue[5] = {0};
void checkController(byte index, byte cc, int value)
{
  value = constrain(value,0,127);
  if(value < lastValue[index] - 1 || value > lastValue[index] + 1)
  {
    sendController(cc, value) ;
    lastValue[index] = value;
  }  
}


void loop()
{
  checkController(0, 71, analogRead(0)/8);
  checkController(1, 75, digitalRead(SWITCHAPIN) == LOW ? 127 : 0);
  checkController(2, 76, digitalRead(SWITCHBPIN) == LOW ? 127 : 0);
  checkController(3, 77, digitalRead(SWITCHCPIN) == LOW ? 127 : 0);
  checkController(4, 78, digitalRead(SWITCHDPIN) == LOW ? 127 : 0);
  
}
