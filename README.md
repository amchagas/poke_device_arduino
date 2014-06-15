poke_device_arduino
===================


These are the instructions to setup a 3d printed nose poke device using arduino and a couple of
cheap electronic elements.
In case one doesn't have a 3D printer available, a small trip to a hardware shop 
should provide all necessary parts to build a poke device.

The files for printing the part and the wiring diagram can be found in this repository as well.
One of the is *.scad and the other *.fzz


Elements needed:
IR Led
IR photodiode 
Optional:
Color LED
Piezo Buzzer

The arduino code is very simple. It should turn off all of the components in the device, wait for a second, than turn on the nose poke light and the IR LED. Once a object/nose is inserted in between the IR LED and IR receiver, the nose poke light turns off and a buzzer starts to buzz. The program counts how much time it spent in each situation

if you ever use this instructions, please cite the project as
Chagas, Andre Maia (2014): Nose poke device using 3d printed parts and Arduino. figshare.
http://dx.doi.org/10.6084/m9.figshare.1057762
