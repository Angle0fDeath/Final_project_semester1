# Final_project_semester_1___Frameless_Harp

DIY Laser Harp (exactly what it says)

The basic outline of the harp:
A laser beam is shone. A stepper motor with a mirror divides it into nine beams. When one or more of the beams are cut, the light sensor (Light Detecting Resistor, LDR) detects it. According to the corresponding motor positions, it sends signals to the Arduino, which in turn produces the respective notes through a computer or keyboard.

How the beam is created:
A mirror is attached to the motor. The laser beam is directed to the mirror. The motor rotates in steps, hence stepper motor. With every step the motor takes, the position of the mirror changes, deflecting the beam in a different direction every time. The steps take place fast enough for the beams to appear as if they are simultaneously present.

How the harp knows which beam has been cut:
Every beam has a corresponding motor position. When a beam is cut, it reflects onto the sensor, which detects an increase in light intensity. The light sensor then looks for the position of the motor at the instant the beam was cut, and thus identifies the beam in question.

Needed Materials:
- Stepper motor (used Nema 17)
- Stepper motor suport
- Driver for stepper  (used A4988)
- Audio amplifier (used PAM8403)
- LDR
- Buttons
- Potentiometer 10 K
- Stereo potentiometer 10 K (optional, volume control)
- 10uF electrolytic cap
- Green laser
- 2x breadboards
- 2x 5 Watts speakers
- 2x 5V charger
- Arduino uno
- Wires
- 12V power source
- Container box
- tranzistor (used 2n2222)

Downsides:
Current version didn't meet the expectations, but it isn't too far from it (lacks speed) and clarity due to used amplifier and sound creation (distortion). 

Cabling the motor:
https://www.pololu.com/product/1182
full step mode

Amplifier and speakers:
https://www.optimusdigital.ro/en/audio-amplifiers/614-modul-mini-amplificator-pam8403-in-clasa-d-stereo-3-w.html
+ power source/charger of 5 volts

Green laser:
plus of power source -> collector tranzistor
arduino uno -> base tranzistor
emitor tranzistor -> plus laser
minus laser -> minus of power source & ground arduino

LDR:
https://www.youtube.com/watch?v=4fN1aJMH9mM
standard configuration, just replaced the rezistor with a potentiometer

Button:
standard configuration

Volume control:
http://www.instructables.com/id/PAM8403-6W-STEREO-AMPLIFIER-TUTORIAL/
step 7

Arduino pins:

STEP (stepper driver) 2
DIRECTION (stepper driver) 3
Laser 7
Button -> 12   
LDR -> A0 
Left Sound (audio amplifier)10
Right Sound (audio amplifier)11
