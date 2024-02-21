# IoT-Based-Air-Quality-Monitoring-System
In this project, IoT Cloud platform will be used to monitor environmental parameters like temperature, humidity, pressure, gas, IAQ value, i.e., index of air quality, CO2 reading, and also the percentage of volatile organic compounds. utilizing a BME680 sensor and ESP8266. 
The BME680 was created specifically for wearables and mobile applications where small size and low battery consumption are essential needs. The BME680's gas sensor is capable of detecting a wide variety of gases, including volatile organic compounds (VOC), to monitor the quality of the air.
The sensor has a voltage range of 1.7V to 3.6V. This module consumes between 0.29 and 0.8 uA of power in standby mode and between 0.15 and 1 uA in sleep mode. The BME680 Sensor has a temperature measurement range of -40~+85°C. The measuring range for humidity is also 0–100%. The Air Quality Index (IAQ) can be measured between 0 and 500 PPM.
Circuit diagram (https://github.com/albinbabu2002/IoT-Based-Air-Quality-Monitoring-System/assets/110345761/51c5d866-9019-4b99-81b4-4d538182e309)
I'm using a D1 Mini Board here. Moreover, NodeMCU Board is an option. The 32-bit ESP8266-12E chip is present in all of these boards. Using a WiFi network, the chip's integrated WiFi chip may upload data to a server or the internet. 
After connection upload the givan code BME680 to the ide download needed librarys like BSEC,BME680,and Blynk library 
For the working of BME680 library we need to modify some files

