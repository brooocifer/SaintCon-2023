# Lego Data Center

This was a custom build entirely out of black lego parts from a variety of Lego kits. 

# Servers

The servers in the data center were 4 Arduino-based Wi-Fi development boards
- https://www.amazon.com/dp/B0BBFXQ1G8/ - 3 for $9.99 - ESP8266 NodeMCU V3

Each ESP8266 was socketed in an expansion PCB with screw terminals, to make it easier to connect LED light strings to them:
- https://www.amazon.com/dp/B08HYYR9WX/ - 2 for $9.99 - KeeYees Expansion PCB with Screw Terminal Block Pin Header for ESP8266

Each ESP8266 had a single LED inserted into the block header with the anode (positive) lead in the D7 header, and the cathode (negative) lead in the ground (GND) header. The light strings themselves were connected to the same D7 and GND screw terminals. Having both the independent LED and the light string connected to the same pins on the ESP8266 helped with troubleshooting both software and circuit connectivity issues.

Each ESP8266 was powered by a USB 2.0 Micro-B power cable.

# Lights
LED lights were looped in and out of holes in the data center bricks. These were purchased at a local CVS for a few dollars (< $10). I am not able to find them online, but they are similar to these: https://www.lowes.com/pd/Haunted-Living/5014058889.
