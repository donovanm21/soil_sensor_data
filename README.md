# IoT Soil Moisture Sensor Data Collection

This is a basic project / starter project for retrieving soil moisture sensor data from a NodeMCU and a soil moisture sensor. The data from the NodeMCU is sent to an API which is updated and shown on a web application. This is a starter template and can be adapted for varios use cases with multiple sensors and endpoints to capture data and show live data with in a web application.

# Components Used


# Pre-Setup

Please ensure you have a .env file in the root directory with the below included for the application to work.

``` php
API_URL=https://your.api.com:3000/ #Ensure this matches your IP or URL where the API will be hosted.

```

# Setup - Docker Image

``` bash
docker run -d --name my_soil_api -p 3000:3000 donovanm21/soilapi
```

# Setup - Building the Docker Image

