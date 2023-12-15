# Remotepad32
PC controlled remote gamepad (Xbox Controller) for assistive access to consoles. It fills the gap on consoles that lack the Remote Play features of PS5/Xbox. With this + a Blueretro adapter you can control all the famous retro consoles from Nintendo, Sega and Sony with the assistive softwares on your pc! https://www.blue-retro.com/products/

# Instructions
1. You need an ESP32 microcontroller and I would recommend the Adafruit Feather ESP32 and to follow the Adafruit tutorial on how to set it up with the Arduino IDE Software that will make it possible to upload my code to your board.
2. The Arduino code needs the Esp32-Ble-Gamepad-HID library installed. Get it from the Github link (usually you need to place it in your Arduino libraries folder normally in C:\Users\[INSERT YOUR USERNAME]\Documents\Arduino\libraries) HERE: https://github.com/lemmingDev/ESP32-BLE-Gamepad
3. Now upload the code to your Adafruit Feather ESP32. There's a lot of Arduino documentation available and forums on Facebook, Reddit, Arduino to check if you're having difficulties with this step. 
4. Download the Serious Serial software zip file from this link: https://drive.google.com/file/d/1ZMwm6Fttu6kRDn6vDzRZ9flgi_J2rTc8/view?usp=sharing
5. Unzip the Serious Serial folder and I suggest you place it on your C: drive but this doesn't matter at all really.
6. Start the software exe file and you will be asked to choose the COM port your Esp32 is connected to. At this point you should already have chosen a COM port in Arduino IDE when you uploaded the code and you should select the same COM port here. If you have forgotten what COM port it was then you can figure this out by closing down the software and unplug the Esp32. When you start the software the correct COM port will be invisible and if you close the software, plug in the Esp32 and start the software again then the correct COM port will be seen again. Another way to figure out the correct COM port is by going into Device Manager on your pc and unplug the ESP32 and reconnect it while keeping an eye out for changes under the list of COM ports. The COM port appearing when you connect it is the right one (or the one disappearing when disconnected).
7. When the correct COM port is connected and the Serious Serial software window is in focus then pressing the arrow keys will change "Up/Down/Left/Right = false" to "... = true" (try WASD keys otherwise).
8. While powered and connected the Esp32 gamepad will be discoverable under the list of Bluetooth devices on your other device (of course also on your pc if you want to test that it's working with an online gamepad tester). Pair it with the device you wanna use it with.
9. The Serious Serial software window must be in focus at all times and pressing the relevant keyboard keys now will trigger actions on your console.  Arrow keys are left Joystick movements, IJKL keys are right Joystick movements and WASD is D-pad and ZVRX are the ABXY gamepad buttons. You will find the documentation for all keys within the Arduino code and of course you can easily remap everything by swapping the letter keys with other letter keys (1_2_3_4 numbers represent arrow keys and they're reserved for Left Joystick movements so you can't use those number keys, probably avoid numbers completely). Copy the code before any edits so you can revert if anything breaks..

# Use cases
The Serious Serial software also recognize key presses from Project Iris, VoiceAttack, Mill Mouse, Alt Controller and other assistive software thus making these available for console gaming. Xbox and PS4/5 users have Remote Play which can do the same thing and also offers display mirroring. But my solution can be used with almost any retro console thanks to the Blueretro Adapter which you can buy online. 
https://www.blue-retro.com/products/
I'm yet to get this to pair with Nintendo Switch though, it needs an adapter for connecting Xbox Controllers but without the large Xbox button it's difficult to get it to pair. To get your console content displayed on your pc monitor you need an HDMI USB Capture Card for your PC and the free software OBS Studio. 

# Further development 
This is open source so any new versions that can better work with Nintendo Switch is highly welcome. Feel free to edit and Improve. On the Serious Serial software side it would also be nice to get it to capture keys even while not in focus. The Processing java code is available on the Github page for serious serial so anyone wanting to have a go with improvements can edit it. 
