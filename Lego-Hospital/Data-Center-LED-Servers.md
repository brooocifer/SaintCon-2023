# Data Center LED Servers

Essentially, each Arduino server is connecting via wi-fi to the Data Center Web Server, and reading a JSON file specific to it. The filename is based on the IP Address, so 192.168.1.9 is reading light9.json to determine if the LED string attached to it should be either on or off. That’s all it’s doing.

6
- Arduino ESP8266 NodeMCU 1.0 (ESP-12E Module)
- IP Address: 192.168.1.6
- Hostname: ESP-5F7ACB
- MAC Address: EC:FA:BC:5F:7A:CB

7
- Arduino ESP8266 NodeMCU 1.0 (ESP-12E Module)
- IP Address: 192.168.1.7
- Hostname: ESP-5F7B9A
- MAC Address: EC:FA:BC:5F:7B:9A

8
- Arduino ESP8266 NodeMCU 1.0 (ESP-12E Module)
- IP Address: 192.168.1.8
- Hostname: ESP-5F7542
- MAC Address: EC:FA:BC:5F:75:42

9
- Arduino ESP8266 NodeMCU 1.0 (ESP-12E Module)
- IP Address: 192.168.1.9
- Hostname: ESP-8E5BB7
- MAC Address: 84:F3:EB:8E:5B:B7

Source code in wifi_iot_led.ino
