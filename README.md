# IoT Soil Moisture Sensor Data Collection

This is a basic project / starter project for retrieving soil moisture sensor data from a NodeMCU and a soil moisture sensor. The data from the NodeMCU is sent to an API which is updated and shown on a web application. This is a starter template and can be adapted for various use cases with multiple sensors and endpoints to capture data and show live data with in a web application.

## Components Used

Standard NodeMCU with a ESP8266 controller

<img src="https://raw.githubusercontent.com/donovanm21/soil_sensor_data/main/files/nodemcu.png" />

BMT Soil Moisture Sensor Kit

<img src="https://raw.githubusercontent.com/donovanm21/soil_sensor_data/main/files/soil_sensor.png" />

## Pre-Setup

Ensure you have Arduino IDE download and installed onto your machine

* https://www.arduino.cc/en/software

Once installed, make sure you have the ESP8266 board manager library installed to communicate with the NodeMCU using the Arduino IDE

* https://github.com/esp8266/Arduino

Download the repo to your machine. You can grab the latest release as well which contains all the files need.

* https://codeload.github.com/donovanm21/soil_sensor_data/zip/refs/tags/v1.0

Once downloaded and unzipped, please ensure you have a .env file in the root directory with the below included for the application to work if you plan on running it in a development environment locally. You will also need to install the dependencies to run the local instance.

``` php
# Ensure this matches your IP or URL where the API will be hosted.
API_URL=https://your.api.com:3000/
```
## Wiring

Use the below table to connect the sensor to the nodemcu / esp8266 controller. Same for the WeMos D1 Mini or Pro

<img src="https://raw.githubusercontent.com/donovanm21/soil_sensor_data/main/files/wiring.png" />

## NodeMCU flashing

Using the Arduino IDE you can open up the Soil_Sensor_Data.ino sketch included in the repo files. Update the wireless detail in the sketch with your wireless SSID (Name of wireless, need to be exactly the same) and the password for your wireless. 

The API details need to be updated to match your API url including the port and /update/ 

``` bash
################ WiFi Details #################
/* Set Wireless Credentials. */
const char *ssid = "My_WiFi";
const char *password = "mypassword";

################# API Details ####################
String URL = "http://my.api.com:3000/update/";
```

Once updated with your details, verify the sketch and upload it to the NodeMCU. Once done, open up the the Serial monitor and confirm the you see the confirmation that it connected to the wireless and successfully received an IP. After that you will start seeing the sensor values being logged out in the serial console. If you see values in the serial monitor you know everything is working fine and can continue with the API deployment.

<img src="https://raw.githubusercontent.com/donovanm21/soil_sensor_data/main/files/wifi.png" />

## Setup - Docker Image

The simplest way to deploy the API is via the below docker command. This will pull the latest image from docker hub and deploy the API on the host you run the command on. Ensure that docker is install, for this you can follow the docker setup instructions online.

NOTE: ensure no other service is using port 3000 on the same host. If so, adjust the 300X:3000 to another port number to avoid conflicts. Make sure you pass the API_URL variable when deploying the container. This is how the web app index receives the current value. URL have to include the port and /soildata/ as part of the url

``` bash
docker run -d --name my_soil_api -p 3000:3000 -e API_URL=http://my.api.com:3000/soildata/ donovanm21/iotsoilsensorapi
```
Once deployed, you can should be able to access the main index page using the http://ipaddress:3000 or http://hostname.com:3000 you will specify the port used when deploying the docker container, if you changes the port, use this port in the URL and .env file for the application accordingly.

## Setup - Building the Docker Image

If you prefer building the docker image and deploying it yourself you can use the below commands. Allows for tweaks and changes to the codebase and deployment of these custom changes to your container environment.

``` bash
# Clone the project files to your host.
git clone https://github.com/donovanm21/soil_sensor_data.git
# Change to the newly create directory
cd soil_sensor_data
# Build the docker image
docker build -t mydockerimage .
# Deploy the docker image
docker run -d --name my_soil_api -p 3000:3000 mydockerimage:latest
```

## Successful API Deployment

If all went well and the NodeMCU is sending the sensor data to the API you will see the below view when you access the web application. The sensor value will update every 2 seconds automatically.

<img src="https://raw.githubusercontent.com/donovanm21/soil_sensor_data/main/files/index.png" />

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)