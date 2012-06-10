
#define LED1PIN  13
#define LED2PIN  11
#define LED3PIN  9
#define LED4PIN  7
#define LED5PIN  12
#define LED6PIN  10
#define LED7PIN  8
#define LED8PIN  6

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
}

void loop()
{
  digitalWrite(LED1PIN, HIGH);
  delay(100);  
  digitalWrite(LED1PIN, LOW);
  
  digitalWrite(LED2PIN, HIGH);
  delay(100);  
  digitalWrite(LED2PIN, LOW);
  
  digitalWrite(LED3PIN, HIGH);
  delay(100);  
  digitalWrite(LED3PIN, LOW);

  digitalWrite(LED4PIN, HIGH);
  delay(100);  
  digitalWrite(LED4PIN, LOW);

  digitalWrite(LED5PIN, HIGH);
  delay(100);  
  digitalWrite(LED5PIN, LOW);

  digitalWrite(LED6PIN, HIGH);
  delay(100);  
  digitalWrite(LED6PIN, LOW);

  digitalWrite(LED7PIN, HIGH);
  delay(100);  
  digitalWrite(LED7PIN, LOW);

  digitalWrite(LED8PIN, HIGH);
  delay(100);  
  digitalWrite(LED8PIN, LOW);  
}
