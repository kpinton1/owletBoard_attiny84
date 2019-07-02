/*
  testBoard 

  Provides test code for oregonBoard and owlBoard
  
  modified 2.7.19 Kevin Pintong 

  Test disposition:
  1) The board should blink the portland metro or right owl eye at a rate of 1 second. 
  2) The RGB LED should cycle through Red, Blue, and Green
  3) When S1 is pressed, all lights should turn off except the left eye or right power indicator. 
  4) When S2 is pressed, all lights should turn on. 
  
  This example code is in the public domain.

*/
#define LED_BUILTIN 0
#define RED_LED 8 
#define BLUE_LED 7
#define GREEN_LED 6
#define BTN1 1
#define BTN2 2

int btn1State = 0;
int btn2State = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
}

// the loop function runs over and over again forever
void loop() {

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
  delay(500);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  delay(500);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  delay(500);
  btn1State = digitalRead(BTN1);
  btn2State = digitalRead(BTN2);

  if(btn1State == HIGH){            //Test S1- If pressed, should turn off everything for 3 seconds
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(LED_BUILTIN, LOW);
    delay(3000);
  }
  if(btn2State == HIGH){            //Test S2- If pressed, should turn on everything for 3 seconds
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(3000);
  }
}
