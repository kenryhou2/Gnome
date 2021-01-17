/* Macro Define */
#define CLK               39                  /* 4-Digit Display clock pin */
#define DIO               38                 /* 4-Digit Display data pin */
#define LIGHT_SENSOR      24                 /* pin connected to the Light Sensor */

/* Global Variables */

void setupLight(){
     
}
void loopLight(){
    light_val = analogRead(LIGHT_SENSOR);        /* read the value from the sensor */    

    sprintf(light_str, "%d", light_val);
    delay(100); // specifies how frequently we will read sensor
    
}