# IDD – Internet Down Detector

## What is this 
A simple ESP01 based circuit to detect internet (wifi) status. It can connect to any Wi-Fi network and check its status pinging www.google.com and blink a status led.
There is a reset button and a wifi manager available, so you can connect to any wifi network without any changes in the code. The wifi manager provides a wifi access point and a interface to manage wifi connections.

## How it works

### Simple explanation
Pinging google.com and blinking a led once every 10 seconds. In case of internet connection outage, the led will blink twice until the connection is restored.

This device can also monitoring google status, so if your connection is ok and google is off, you can call these guys and alert they and, who knows, ask for a discount on google products. But I’m sure google has another method to avoid servers down than this project 

### Complete explanation
- Power on the device with 3.0v – 3,3v (the maximum voltage ESP01 can handle) 
- LED will blink 5 times – it means the wifi manager is waiting for you to choose a network to monitoring
- Using any wifi device, connect to a SSID called ‘IDDAP’

![image2](/images/tela1p.jpg)


- Attention – Android phones will try to avoid networks without internet access. You need to choose ‘always connect’  **

![image2](/images/tela2p.jpg)
- Using a browser (ex. Chrome mobile), go to URL 192.168.4.1 – this is the default wifi manager URL. 

![image3](/images/tela3p.jpg)
- Click in ‘Configure Wifi’

![image4](/images/tela4p.jpg)
- A list of available networks will be display. Click in network’s name you want to be monitoring, type password and click ‘save’.

![image5](/images/tela5p.jpg)
- After this, ESP01 will disconnect from IDDAP and try to connect to desired network. 

If the connection is established, device will blink 3 times and the IDDAP network will disappear, then network monitoring will start, and device will ** blink once every 10 seconds **. If the connections do not work, ex. wrong password, the device will not blink and the IDDAP network will appear again. 

In case of failed internet connection, the device will ** blink twice every 10 seconds ** until internet connection is established.

Reset network’s credential to connect to another network
If you wish to connect to another network, or need to chance credentials, press the reset button for a while (10 seconds) and the device will reset all network connections. The wifi manager will run again and the entire process to connect to a new network will happen again.

List of components
- 1 ESP01 (ESP8226) – you can use a NodeMCU ESP12 or another ESP8266 device
- 1 330R resistor
- 1 1K resistor
- 1 LED
- 1 push button
- 3.0v – 3.3V power supply (batteries, AC converter, etc.)

Also, you will need a ** USB to UART Bridge **, like CP210x. You can use an NodeMCU ESP12 (this device already had a USB to UART, a voltage regulator and lot of features. But to use only to GPIO ports ESP01 is low cost and had a small form factor.

You can see a complete explanation on how to flash ESP01 using CP2102 here, in the complete guide by Boseji’s Lab (link bellow)

** Attention here  **– if you want to use the device with CP210x at the same time, (for testing purposes, for example), don’t  forget to remove the some GPIO connections while you are flashing ESP01 or you won’t connect. With a few pins, ESP01 share some like GPIO1 with TX or GPIO3 with RX. In my case, with the GPIO2 (button pin and the only one not shared  ) connected, Arduino IDE cannot flash and always show a connection error. 

### Hardware
Hardware connections is very simple, and you can connect all components in a wired way, does not need to create a PCB. Take a look at fritzing using a breadboard and a picture of a wired no-pcb mounting.

### Software
The software is self-explained and had a few lines. First, lets wifi manager do the job, and after that a simple loop with button read (to reset network credentials) and blinking led if PING is successful or not and the magic is done.

## Thanks to 
Tzapu’s WifiManager - https://github.com/tzapu/WiFiManager

Daniele Colabardi’s ESP8266PING - https://github.com/dancol90/ESP8266Ping

Boseji’s Lab – Flashing ESP01 with CP2102 - https://boseji.com/posts/esp8266-flashing-in-linux/


**My English isn't very good yet, but I'm learning. Sorry about that**

