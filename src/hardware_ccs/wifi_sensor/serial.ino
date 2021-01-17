void setupSerial(){
     Serial.begin(115200); // initialize serial port @115200 baud
}
void loopSerial(){
          /*Comment these out when not needed. This will clutter your terminal*/
    //  Serial.print("Pot: "); Serial.print(pot);
     Serial.print(" / Light: "); Serial.print(light_val);
      Serial.print(" / Moisture: "); Serial.print(moisture);
    //  Serial.print(" / Sound: "); Serial.println(sound);
     delay(100);
}