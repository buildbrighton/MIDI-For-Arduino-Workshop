
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
  pinMode(SWITCHCPIN, INPUT);
  pinMode(SWITCHDPIN, INPUT);

  digitalWrite(SWITCHAPIN, HIGH);
  digitalWrite(SWITCHBPIN, HIGH);
  digitalWrite(SWITCHCPIN, HIGH);
  digitalWrite(SWITCHDPIN, HIGH);
  
}

void loop()
{
  if(digitalRead(SWITCHAPIN) == LOW) 
  {
    digitalWrite(LED1PIN, HIGH);
    digitalWrite(LED2PIN, HIGH);
  }
  else
  {
    digitalWrite(LED1PIN, LOW);
    digitalWrite(LED2PIN, LOW);
  }
  
  if(digitalRead(SWITCHBPIN) == LOW) 
  {
    digitalWrite(LED3PIN, HIGH);
    digitalWrite(LED4PIN, HIGH);
  }
  else
  {
    digitalWrite(LED3PIN, LOW);
    digitalWrite(LED4PIN, LOW);
  }

  if(digitalRead(SWITCHCPIN) == LOW) 
  {
    digitalWrite(LED5PIN, HIGH);
    digitalWrite(LED6PIN, HIGH);
  }
  else
  {
    digitalWrite(LED5PIN, LOW);
    digitalWrite(LED6PIN, LOW);
  }

  if(digitalRead(SWITCHDPIN) == LOW) 
  {
    digitalWrite(LED7PIN, HIGH);
    digitalWrite(LED8PIN, HIGH);
  }
  else
  {
    digitalWrite(LED7PIN, LOW);
    digitalWrite(LED8PIN, LOW);
  }
  
}
