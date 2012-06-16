
#define LED1PIN  13
#define LED2PIN  11
#define LED3PIN  9
#define LED4PIN  7
#define LED5PIN  12
#define LED6PIN  10
#define LED7PIN  8
#define LED8PIN  6

/**
  Turns on the LEDs depending on the LDR
**/
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

void indicate(int value)
{
  digitalWrite(LED1PIN, (value > 128 * 7)? HIGH: LOW);
  digitalWrite(LED2PIN, (value > 128 * 6)? HIGH: LOW);
  digitalWrite(LED3PIN, (value > 128 * 5)? HIGH: LOW);
  digitalWrite(LED4PIN, (value > 128 * 4)? HIGH: LOW);
  digitalWrite(LED5PIN, (value > 128 * 3)? HIGH: LOW);
  digitalWrite(LED6PIN, (value > 128 * 2)? HIGH: LOW);
  digitalWrite(LED7PIN, (value > 128 * 1)? HIGH: LOW);
  digitalWrite(LED8PIN, (value > 128 * 0)? HIGH: LOW);
}
void loop()
{
 indicate(analogRead(1) * 2);
}
