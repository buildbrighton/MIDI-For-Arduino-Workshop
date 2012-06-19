
// Define some symbols to use in place of the actual
// pin numbers (this makes our program easier to read)
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
  // set all the pins connected to the LEDs to work
  // as digital outputs
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
  // first led on for 0.1 seconds
  digitalWrite(LED1PIN, HIGH);
  delay(100);   
  digitalWrite(LED1PIN, LOW);
  
  // led #2 on for 0.1 seconds
  digitalWrite(LED2PIN, HIGH);
  delay(100);  
  digitalWrite(LED2PIN, LOW);
  
  // led #3 on for 0.1 seconds
  digitalWrite(LED3PIN, HIGH);
  delay(100);  
  digitalWrite(LED3PIN, LOW);

  // led #4 on for 0.1 seconds
  digitalWrite(LED4PIN, HIGH);
  delay(100);  
  digitalWrite(LED4PIN, LOW);

  // led #5 on for 0.1 seconds
  digitalWrite(LED5PIN, HIGH);
  delay(100);  
  digitalWrite(LED5PIN, LOW);

  // led #6 on for 0.1 seconds
  digitalWrite(LED6PIN, HIGH);
  delay(100);  
  digitalWrite(LED6PIN, LOW);

  // led #7 on for 0.1 seconds
  digitalWrite(LED7PIN, HIGH);
  delay(100);  
  digitalWrite(LED7PIN, LOW);

  // led #8 on for 0.1 seconds
  digitalWrite(LED8PIN, HIGH);
  delay(100);  
  digitalWrite(LED8PIN, LOW);  
}
