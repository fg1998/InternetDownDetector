# IDD – Internet Down Detector

## What is this 
A simple ESP8266 (WeMos d1 mini board) based circuit to detect internet (wifi) status. It can connect to any Wi-Fi network and check its status pinging www.google.com and blink a status led.
There is a reset button and a wifi manager available, so you can connect to any wifi network without changes in the code. The wifi manager provides a wifi access point and a interface to manage wifi connections.

## How it works

### Simple explanation
Pinging www.google.com and blinking a led once every 10 seconds. In case of internet connection outage, the led will blink twice until the connection is restored.

This device can also monitoring google status, so if your connection is ok and google is off, you can call these guys and alert they and, who knows, ask for a discount on youtube premium. But I’m sure google has another method to avoid servers down than this project 😄

### Complete explanation
- Power on the device with 4v – 6v (the voltage range WeMos d1 can handle) 
- LED will blink 5 times – it means the wifi manager is waiting for you to choose a network to monitoring
- Using any wifi device, connect to a SSID called ‘IDDAP’

![image2](/images/tela1p.jpg)


- Attention – Android phones will try to avoid networks without internet access. You need to choose ‘always connect’  **

![image2](/images/tela2p.jpg)
- Using a browser (ex. Chrome mobile), go to URL 192.168.4.1 – this is the default wifi manager URL. 
- Click in ‘Configure Wifi’

![image3](/images/tela3p.jpg)

- A list of available networks will be display. Click in network’s name you want to be monitoring, type password and click ‘save’.

![image4](/images/tela4p.jpg)

- After this, ESP8266 will disconnect from IDDAP and try to connect to desired network. 

![image5](/images/tela5p.jpg)


If the connection is established, the IDDAP network will disappear, then network monitoring will start, and device will **blink once every 10 seconds**. If the connections do not work, ex. wrong password, the device will not blink and the IDDAP network will appear again. 

In case of failed internet connection, the device will **blink twice every 10 seconds until internet connection is established.**

### Reset network’s credential to connect to another network
If you wish to connect to another network, or need to chance credentials, press the reset button for a while and the device will reset all network connections. The wifi manager will run again and the entire process to connect to a new network will happen again.

List of components
- 1 WeMos D1 Mini (ESP8226) – you can use a NodeMCU ESP12 or another ESP8266 device
- 1 330R resistor
- 1 1K resistor
- 1 LED
- 1 push button
- 4V - 6V power supply (batteries, AC converter, etc.)

### Hardware
Hardware connections is very simple, and you can connect all components in protoboard or just wired all componentes, does not need to create a PCB. Take a look at fritzing using a breadboard and a picture of a wired no-pcb mounting.

![image](/images/proto.png)

![image](/images/wired.png)

### Software
The software is self-explained and had a few lines. First, lets wifi manager do the job, and after that a simple loop with button read (to reset network credentials) and blinking led if PING is successful or not and the magic is done.

Use Arduino IDE to flash WeMos D1. There is a lot of information on internet on how to use ESP8266 with Arduino IDE, please google it.

### Libraries needed
Be careful to add all this libraries from Arduino IDE Library manager

tzapu - Wifi Manager - https://github.com/tzapu/WiFiManager

Daniele Colanardi -  ESP8266PING - https://github.com/dancol90/ESP8266Ping

Michael Sims - BlockNot - https://github.com/EasyG0ing1/BlockNot



### WeMos D1 Mini instead ESP01
I'm moving my ESP8266 projects from ESP01 to WeMos D1 Mini for a lot of reasons.  First, WeMos had a more pins than ESP01 and costs almost the same in various China ecommerce sites (ex. Aliexpress). Also, they had USB to UART connections, and you don’t need CP210x USB-TO-UART dongle (with was a little nightmare to run on my old Catalina MacBook)

The cons are ESP01 uses minimum room instead of double-size WeMos but I can handle this easily in this project. 


## Thanks to 
Tzapu’s WifiManager - https://github.com/tzapu/WiFiManager

Daniele Colabardi’s ESP8266PING - https://github.com/dancol90/ESP8266Ping

Michael Sims - BlockNot - https://github.com/EasyG0ing1/BlockNot


**My English isn't very good yet, but I'm learning. Sorry about that**

