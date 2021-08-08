# IoT Soil Moisture Sensor Data Collection

This is a basic project / starter project for retrieving soil moisture sensor data from a NodeMCU and a soil moisture sensor. The data from the NodeMCU is sent to an API which is updated and shown on a web application. This is a starter template and can be adapted for varios use cases with multiple sensors and endpoints to capture data and show live data with in a web application.

## Components Used

Standard NodeMCU with a ESP8266 controller

<img src="https://raw.githubusercontent.com/donovanm21/soil_sensor_data/main/files/nodemcu.png" />

BMT Soil Moister Sensor Kit

<img src="https://raw.githubusercontent.com/donovanm21/soil_sensor_data/main/files/soil_sensor.png" />

## Pre-Setup

Please ensure you have a .env file in the root directory with the below included for the application to work.

``` php
# Ensure this matches your IP or URL where the API will be hosted.
API_URL=https://your.api.com:3000/
```

## Setup - Docker Image

The simplest way to deploy the API is via the below docker command. This will pull the latest image from docker hub and deploy the API on the host you run the command on. Ensure that docker is install, for this you can follow the docker setup instructions online.

NOTE: ensure no other service is using port 3000 on the same host. If so, adjust the 300X:3000 to another port number to avoid conflicts.

``` bash
docker run -d --name my_soil_api -p 3000:3000 donovanm21/soilapi
```
Once deployed, you can should be able to access the main index page using the http://ipaddress:3000 or http://hostname.com:3000 you will specify the port use when deploying the docker image, if you changes the port, use this port in the URL and .env file for the application.

## Setup - Building the Docker Image

If you prefer building the docker image and deploying it yourself you can use the below commands.

``` bash
# Clone the project files to your host.
git clone https://github.com/donovanm21/soil_sensor_data.git
# Change to the newly create directory
cd soil_sensor_data
# Build the docker image
docker build -t mydockerimage:latest .
# Deploy the docker image
docker run -d --name my_soil_api -p 3000:3000 mydockerimage:latest
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)