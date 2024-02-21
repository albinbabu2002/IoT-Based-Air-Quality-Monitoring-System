# IoT-Based-Air-Quality-Monitoring-System
In this project, IoT Cloud platform will be used to monitor environmental parameters like temperature, humidity, pressure, gas, IAQ value, i.e., index of air quality, CO2 reading, and also the percentage of volatile organic compounds. utilizing a BME680 sensor and ESP8266. 
The BME680 was created specifically for wearables and mobile applications where small size and low battery consumption are essential needs. The BME680's gas sensor is capable of detecting a wide variety of gases, including volatile organic compounds (VOC), to monitor the quality of the air.
The sensor has a voltage range of 1.7V to 3.6V. This module consumes between 0.29 and 0.8 uA of power in standby mode and between 0.15 and 1 uA in sleep mode. The BME680 Sensor has a temperature measurement range of -40~+85°C. The measuring range for humidity is also 0–100%. The Air Quality Index (IAQ) can be measured between 0 and 500 PPM.

Circuit diagram (https://github.com/albinbabu2002/IoT-Based-Air-Quality-Monitoring-System/assets/110345761/51c5d866-9019-4b99-81b4-4d538182e309)

I'm using a D1 Mini Board here. Moreover, NodeMCU Board is an option. The 32-bit ESP8266-12E chip is present in all of these boards. Using a WiFi network, the chip's integrated WiFi chip may upload data to a server or the internet. 

After connection upload the givan code BME680.ino to the ide, download needed librarys like BSEC,BME680,and Blynk library 
For the working of BSEC library we need to modify some files from (C:\Users\**name**\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\3.1.2 ) 
file name (platform.txt) replace givan lines :

( # These can be overridden in platform.local.txt
 compiler.c.extra_flags=
 compiler.c.elf.extra_flags=
 #compiler.c.elf.extra_flags=-v
 compiler.cpp.extra_flags=
 compiler.S.extra_flags=
 compiler.ar.extra_flags=
 compiler.elf2hex.extra_flags=
 compiler.libraries.ldflags= )
AND
( ## Combine gc-sections, archives, and objects
recipe.c.combine.pattern="{compiler.path}{compiler.c.elf.cmd}" {build.exception_flags} -Wl,-Map "-Wl,{build.path}/{build.project_name}.map" {compiler.c.elf.flags} {compiler.c.elf.extra_flags} -o "{build.path}/{build.project_name}.elf" -Wl,--start-group {object_files} "{archive_file_path}" {compiler.c.elf.libs} {compiler.libraries.ldflags} -Wl,--end-group  "-L{build.path}" )

 after modifying setup the blynk iot cloud 
 Make changes to the WiFi SSID, Password & Blynk Authentication Token in the code. and UPLOAD THE CODE.
 
The provided SSID and Password will be used by the ESP8266 Board to attempt a wifi network connection. Every three seconds, the BME680 data is transferred to the Blynk application. Both the Blynk application.
![output](https://github.com/albinbabu2002/IoT-Based-Air-Quality-Monitoring-System/assets/110345761/8e4d2575-dce9-4261-8c3a-5bc156c30f5e)
Every time the sensor pushes a certain value, the data is altered. This is where the pressure, temperature, humidity, IAQ, CO2, and VOC gauge will show up. This is how you can monitor both the indoor and outdoor air quality using BME680 and ESP8266.
 

