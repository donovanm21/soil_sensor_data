/* -----------------------------------------------------------------------------
  - Project: IoT Soil Data Capture to API
  - Author:  Donovan Muskett-Yetts
  - Github: https://github.com/donovanm21/soil_sensor_data
  - Date:  08/09/2021
   -----------------------------------------------------------------------------
  This code was created to capture sensor data for a soil moisture level sensor
  but can be adapted to monitor or measure any analog sensor data.
   ---------------------------------------------------------------------------*/
//#################### Libraries ###################
// NodeMCU Specific
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

WiFiClient wifiClient;

//################ Define Pin to Use ###############
#define SensorPin A0

//################ WiFi Details #################
/* Set Wireless Credentials. */
const char *ssid = "My_WiFi";
const char *password = "mypassword";

//################# API Details ####################
String URL = "http://my.api.com:3000/update/"; // IP or Hostname for API Example: https://api.mydomain.com:3000/
String getData, Link; // Set up vars for Link and getData
int sensorValue = 0; // Initial sensor value

//################# Initial Setup #####################
void setup() {
  delay(1000);
  Serial.begin(9600);
  //---------------------------------------------
  connectToWiFi();
}
//##################################################
void loop() {
  //check if there's a connection to Wi-Fi or not
  if(!WiFi.isConnected()){
    connectToWiFi();    //Retry to connect to Wi-Fi
  }
  //---------------------------------------------
  for (int i = 0; i <= 100; i++) 
  { 
   sensorValue = sensorValue + analogRead(SensorPin); 
   delay(1); 
  } 
   sensorValue = sensorValue/100.0; 
   Serial.println(sensorValue); 
   delay(2000); // Delay on 
   SendSensorData(sensorValue);
}
//########## Send Soil Sensor Value to API ##########
void SendSensorData( int sensorValue ){
  if(WiFi.isConnected()){
    HTTPClient http;    // Declare object class HTTPClient
    //GET Data
    getData = String(sensorValue);
    //GET method
    Link = URL + getData;
    http.begin(wifiClient, Link); // Initiate HTTP request
    
    int httpCode = http.GET();   // Send the request

    Serial.println(String(sensorValue)); // Print current sensor value out to serial monitor
    delay(2500);
    http.end();  //Close connection
  }
}
//########## Connect ESP to WiFi ##########
void connectToWiFi(){
    WiFi.mode(WIFI_OFF);        // Prevents reconnection loop
    delay(1000);
    WiFi.mode(WIFI_STA);
    Serial.print("Connecting to ->");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print("-");
    }
    Serial.println(">");
    Serial.println("ESP Connected");
  
    Serial.print("ESP IP address: ");
    Serial.println(WiFi.localIP());  //IP address assigned to your device
    
    delay(1000);
}
//=======================================================================
