Automatic-double-doors
======================

Arduino project to control two doors.

Source code at `/Automatic_double_doors/Automatic_double_doors.ino`


###Description


This project is to create a robot through an Arduino to be able to control a system of automatic double doors. 

The first thing before you open the door is to unlock the lock, pushing the door to the opposite direction and opening the lock. One of the leaves is due to open before the other so that there are no problems. 

The closure system is similar to the opening, in this case the door started opening movement must first start it after it to close properly. For the closure should not activate the lock. 

End doors motion when their respective stroke end is reached, both the opening and closing 

If the button is pressed once the doors at rest (open or closed) the clip. If you press the button again stops having a certain time and if there are no obstacles when time runs continue normal movement. 

If you are moving while the button is pressed twice, the system will perform the movement against the current. 

The system also incorporates an output to add other functions, such as turning on the lights in the garage if there is not enough light.


###The Circuit 
![Alt text](https://github.com/garciparedes/Automatic-double-doors/blob/master/Automatic-double-doors.png "The Circuit")


###Components required
* 1 x Arduino Uno R3
* 7 x Relay 5v / AC 250V/10A
* 2 x Phase AC Motors to move de doors
* 1 x Electric Lock
* 1 x Station and wireless controllers
* 3 x Buttons
* 1 x Motion Sensor
* 4 x Limit Buttons
* Cables and board to connect everything
