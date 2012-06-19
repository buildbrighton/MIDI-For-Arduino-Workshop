
#define LED1PIN  13
#define LED2PIN  11
#define LED3PIN  9
#define LED4PIN  7
#define LED5PIN  12
#define LED6PIN  10
#define LED7PIN  8
#define LED8PIN  6

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
  
  Serial.begin(31250);
  
}

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

byte command;
byte param1;
byte param2;
byte state = 0;
void loop()
{
  if(Serial.available())
  {
    byte ch = Serial.read();    
    if(ch >= 0x80)
    {
      command = ch;
      state = 1;
    }
    else if(state == 1)
    {
      param1 = ch;
      state = 2;
    }
    else if(state == 2)
    {
      param2 = ch;
      state = 1;
      
      if(command == 0x90 && param2 > 0)
        setLED(param1, HIGH);
      else if(command == 0x90 || command == 0x80)
        setLED(param1, LOW);
    }
  }    
}
