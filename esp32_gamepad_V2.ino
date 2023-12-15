/*qqk
   This example turns the ESP32 into a Bluetooth LE gamepad that presses buttons and moves axis

   At the moment we are using the default settings, but they can be canged using a BleGamepadConfig instance as parameter for the begin function.

   Possible buttons are:
   BUTTON_1 through to BUTTON_16
   (16 buttons by default. Library can be configured to use up to 128)

   Possible DPAD/HAT switch position values are:
   DPAD_CENTERED, DPAD_UP, DPAD_UP_RIGHT, DPAD_RIGHT, DPAD_DOWN_RIGHT, DPAD_DOWN, DPAD_DOWN_LEFT, DPAD_LEFT, DPAD_UP_LEFT
   (or HAT_CENTERED, HAT_UP etc)

   bleGamepad.setAxes sets all axes at once. There are a few:
   (x axis, y axis, z axis, rx axis, ry axis, rz axis, slider 1, slider 2)

   Library can also be configured to support up to 5 simulation controls
   (rudder, throttle, accelerator, brake, steering), but they are not enabled by default.

   Library can also be configured to support different function buttons
   (start, select, menu, home, back, volume increase, volume decrease, volume mute)
   start and select are enabled by default
*/

#include <Arduino.h>
#include <BleGamepad.h>
uint16_t xpos = 16383;
uint16_t ypos = 16383;
BleGamepad bleGamepad;

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleGamepad.begin();
  // The default bleGamepad.begin() above enables 16 buttons, all axes, one hat, and no simulation controls or special buttons
}

void loop()
{
  char incomingChar = 0;   // for incoming serial data
  if (bleGamepad.isConnected())
  {
    if (Serial.available() > 0) {
      incomingChar = Serial.read();
      switch (incomingChar) {
          Serial.print(incomingChar);
        // case 1, 2, 3 &  4 represents UP, DOWN, LEFT, RIGHT arrow key on PC in that order
        // where letters are used case represents corresponding keyboard key
        // the difference is because of how the Esp32 ble gamepad library handles key codes

        // In the setup code, set 'xpos' and 'ypos' to center values (~16383)


        // ...

        // Then for each case, only change the 'xpos' and/or 'ypos' value according to the movement you want

        // Examples below (make sure to do similar changes to other cases)
        case '1':
          // Only move forward (y-position) with left thumb
          xpos = 16383;
          ypos = 0;
          bleGamepad.setLeftThumb(xpos, ypos); // Move joystick to new position
          break;
        case '2':
          // Only move backward (y-position) with left thumb
          xpos = 16383;
          ypos = 32767;
          bleGamepad.setLeftThumb(xpos, ypos);  // Move joystick to new position
          break;
        case '3':
          // Only move left (x-position) with left thumb
          xpos = 0;
          ypos = 16383;
          bleGamepad.setLeftThumb(xpos, ypos);  // Move joystick to new position
          break;
        case '4':
          // Only move right (x-position) with left thumb
          xpos = 32767;
          ypos = 16383;
          bleGamepad.setLeftThumb(xpos, ypos); // Move joystick to new
          break;
        case 'i':
          bleGamepad.setAxes(16383, 16383, 16383, 16383, 0, 16383, 16383, 16383); // Right stick forward x, y positions
          break;
        case 'k':
          bleGamepad.setAxes(16383, 16383, 16383, 16383, 32767, 16383, 16383, 16383); // Right stick backwards x, y position
          break;
        case 'j':
          bleGamepad.setAxes(16383, 16383, 0, 16383, 16383, 16383, 16383, 16383); // Right stick left x, y position
          break;
        case 'l':
          bleGamepad.setAxes(16383, 16383, 32767, 16383, 16383, 16383, 16383, 16383); // Right stick right x, y positio
          break;
        case 'w':
          bleGamepad.setHat1(HAT_UP); // D-pad UP
          break;
        case 's':
          bleGamepad.setHat1(HAT_DOWN); // D-pad DOWN
          break;
        case 'd':
          bleGamepad.setHat1(HAT_RIGHT); // D-pad RIGHT
          break;
        case 'a':
          bleGamepad.setHat1(HAT_LEFT); // D-pad LEFT
          break;
        case 'z':
          bleGamepad.press(BUTTON_1); // Button 'x' on PS4
          break;
        case 'v':
          bleGamepad.press(BUTTON_2); // Button A
          break;
        case 'r':
          bleGamepad.press(BUTTON_3); // Button
          break;
        case 'x':
          bleGamepad.press(BUTTON_4); // Button
          break;
        case 'c':
          bleGamepad.press(BUTTON_5); // Right bumper???
          break;
        case 't':
          bleGamepad.press(BUTTON_6); // Left bumper???
          break;
        case 'e':
          bleGamepad.press(BUTTON_7); // Right trigger???
          break;
        case 'q':
          bleGamepad.press(BUTTON_8); //Left trigger???
          break;
        case 'f':
          bleGamepad.press(BUTTON_9);
          break;
        case 'g':
          bleGamepad.press(BUTTON_10);
          break;
        case 'h':
          bleGamepad.press(BUTTON_11);
          break;
        case 'n':
          bleGamepad.press(BUTTON_12);
          break;
        case '0':
          xpos = 16383;
          ypos = 16383;
          bleGamepad.setLeftThumb(xpos, ypos);  // Move joystick to center position
          bleGamepad.setAxes(16383, 16383, 16383, 16383, 16383, 16383, 16383, 16383);
          bleGamepad.release(BUTTON_1);
          bleGamepad.release(BUTTON_2);
          bleGamepad.release(BUTTON_3);
          bleGamepad.release(BUTTON_4);
          bleGamepad.release(BUTTON_5);
          bleGamepad.release(BUTTON_6);
          bleGamepad.release(BUTTON_7);
          bleGamepad.release(BUTTON_8);
          bleGamepad.release(BUTTON_9);
          bleGamepad.release(BUTTON_10);
          bleGamepad.release(BUTTON_11);
          bleGamepad.release(BUTTON_12);
          bleGamepad.setHat1(HAT_CENTERED);
      }
    } else incomingChar = 0; //
  }
}
