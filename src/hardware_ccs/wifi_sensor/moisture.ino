
void setupMoisture() {
     // put your setup code here, to run once:
}
void loopMoisture() {
     // put your main code here, to run repeatedly:
     moisture = analogRead(25); // Moisture sensor is connected to pin 25
     sprintf(moisture_str, "%d", moisture);
     delay(100); // specifies how frequently we will read sensor
}