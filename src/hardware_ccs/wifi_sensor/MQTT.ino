char ssid[] = "MySpectrumWiFi0D-2G";              // your network name also called SSID  
char password[] = "fluentobject612";         // your network password  
char server[] = "broker.emqx.io";     // MQTTServer to use  
WiFiClient wifiClient;
PubSubClient client(server, 1883, callback, wifiClient);
int pubCount = 0;  // Keep count of number of MQTT publishes we've sent


void callback(char* topic, byte* payload, unsigned int length) {
}
void setup() {
     wifiReady.begin(); // initialize wifiReady event.
     delay(100);
     // attempt to connect to Wifi network:
     Serial.print("\nAttempting to connect to Network named: ");
     Serial.println(ssid);
     WiFi.begin(ssid, password);
     while ( WiFi.status() != WL_CONNECTED) { // print dots while we wait to connect             Serial.print(".");
          delay(300);     
     }     
     Serial.println("\nYou're connected to the network");
     Serial.println("Waiting for an ip address");
     while (WiFi.localIP() == INADDR_NONE) { // print dots! Waiting for ip address
          Serial.print(".");
          delay(300);
     }
     Serial.print("\nIP Address obtained: ");
     Serial.println(WiFi.localIP());
     
     wifiReady.send();  // We're connected! Let the JSONify task know!

}
void loop() {
    //myEvent.waitFor(); // Wait for next JSON payload event to be triggered
     // Reconnect to MQTT Broker if not connected
     if (!client.connected()) {
          Serial.println("Disconnected. Reconnecting....");
          client.connect("MSP432_CC3100");
          Serial.println("Connected");
     }
     
     pubCount++; // Keep count of times we publish to the cloud  
     pubCount++;
     //client.publish("/mqtt/myLaunchPadData", jsonPayload); // PUBLISH!!! publish(topic, msg)
     client.publish("/mqtt/moisture", moisture_str); // PUBLISH!!! publish(topic, msg)
     client.publish("/mqtt/light", light_str);
    //  client.publish("/mqtt/moisture", moisture_str); // PUBLISH!!! publish(topic, msg)
    //  client.publish("/mqtt/light", light_str);
     //free(jsonPayload); // free the dynamic space allocated for this global variable
    //  Serial.print("MQTT published! ("); Serial.print(pubCount); Serial.println(")");
     //Serial.print("done MQTT");
     delay(100);
}