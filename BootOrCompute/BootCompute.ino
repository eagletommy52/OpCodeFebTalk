/*
  Boot/Compute Game

  Ref Arduino Debounce and Sweep Exmample Libraries

  Andrew Thompson 2019.

*/
#include <Servo.h>
Servo gameServo;
// constants
const int buttonPin = 5;    // the number of the pushbutton pin
const int buttonPullDownPin = 3;
const bool buttonPullDownState = LOW;

// Variables
int buttonState;             // the current reading from the input pin

int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 30;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buttonPullDownPin, OUTPUT);
  gameServo.attach(9);  //attach servo pwm to pin 9
  gameServo.write(170);
  Serial.begin(9600);
  // set initial LED state
  digitalWrite(buttonPullDownPin, buttonPullDownState); //use 220k resistor to pull button pin to low (this is completely unnecessary but I ran out of wire to jump off of the ground pin on the redboard, so I'm just using a GPIO to simulate ground) 
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        // so all the board swing stuff
        gameServo.write(120);
        delay(600);
        gameServo.write(70);
        delay(700);
        gameServo.write(140);
        delay(600);
        gameServo.write(60);
        delay(700); 
        gameServo.write(135);
        delay(600);
        gameServo.write(65);
        delay(700);
        gameServo.write(90);
        //pick left or right
        randomSeed(millis());
        for(int i =0; i<3; i++){
          if(round(random(0,101)/50)) {
            gameServo.write(20);
            delay(1200);
          } else {
            gameServo.write(170);
            delay(1200);
          }
        }
        delay(6000);
        gameServo.write(90);
      }
  
    }
  }
  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}
