# Final_project_semester1

The basic outline of the harp:
A laser beam is shone. A stepper motor with a mirror divides it into nine beams. When one or more of the beams are cut, the light sensor (Light Detecting Resistor, LDR) detects it. According to the corresponding motor positions, it sends signals to the Arduino, which in turn produces the respective notes through a computer or keyboard.

How the beam is created:
A mirror is attached to the motor. The laser beam is directed to the mirror. The motor rotates in steps, hence stepper motor. With every step the motor takes, the position of the mirror changes, deflecting the beam in a different direction every time. The steps take place fast enough for the beams to appear as if they are simultaneously present.

How the harp knows which beam has been cut:
Every beam has a corresponding motor position. When a beam is cut, it reflects onto the sensor, which detects an increase in light intensity. The light sensor then looks for the position of the motor at the instant the beam was cut, and thus identifies the beam in question.

Also connection to PC:
There are two options that you can take:
Option 1:
  Plug your harp directly into a MIDI keyboard and you are good to go.
  But if you want more control then go for Option 2.

Option 2: 
For this option you need a MIDI to USB converter, like in the first picture.
This works with any software that deals with MIDI, Here we show you how to go about it using FL Studio:

3rd Picture: First open FL Studio up, then click the OPTIONS button on the upper left corner and navigate to the MIDI settings. then select your MIDI device.

4th picture: The next step reveals the magic of MIDI, Right click on one of the tabs, in the Insert tab you will see a whole bunch of different sounds available to you, ranging from the classic sounds to the most modern sounding synths. Feel free to experiment with these sounds until you find your favourite one.  

Materiale: https://docs.google.com/spreadsheets/d/1WGp8LJNheEEPTvfJexgfyGNyoK_Kcl4Zfi_gMkAJmkE/edit?usp=sharing
