#include <ESP8266WiFi.h>    
#include <PubSubClient.h>
unsigned long previousMillis = 0;
unsigned long interval = 10000;
const char* mqttServer = "192.168.0.110";
const int mqttPort = 1883;
const char* ssid = "******";
const char* password = "******";
String tempc; //variable to store temperature in degree Celsius
float vout; 
const int sensor=A0; 
WiFiClient espClient;
PubSubClient client(mqttServer, mqttPort,espClient); 
void setup() {
  Serial.begin(115200);
  pinMode(sensor,INPUT);
  
  WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void loop() {
    client.loop();
unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    vout=(vout*330)/1024;
    tempc=vout; // Storing value in Degree Celsius
    String toSend = (tempc);
    client.publish("Temperature",toSend.c_str());
    }
 
 
}
