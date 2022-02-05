CyberTruck using Arduino

The CyberTruck is controlled through Bluetooth controller app
(Bluetooth RC Controller) on an Android smartphone, CyberTruck has
Bluetooth Module (HC-05) to receive the signal and transfer it to
Arduino. The logic is burned to Arduino, which on signal reception
outputs the respective signal to Motor Driver Module(L298N). All 4
geared motors are connected to Motor Driver Module.
The whole truck is powered by 2x Lithium-ion 3.7v 5000mah batteries
connected in series to Output 7.4v giving it about 4hours of runtime.
The power is received by Motor Driver. Arduino is powered by the 5v
output from the motor driver and all the components have common
ground.
Ultrasonic Sensor HC-SR04 is placed in the front grill of the truck to
detect obstacles in the front, Ultrasonic sensor sends out a pulse and
receives it back and gives Arduino the time taken for pulse to be
received, Arduino Logic calculated the distance of the reflector object
from CyberTruck’s front and once the distance reaches proximity of
19cm the Truck Stops and reverses 30cm from its current position.
CyberTruck is programmed not to move if no Bluetooth Connection is
Available, once Bluetooth controller is connected the vehicle moves
based on signal and starts detecting obstacles on the front.