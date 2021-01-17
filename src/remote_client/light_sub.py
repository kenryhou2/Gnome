# Test Subscribe code
# Reference: https://github.com/pholur/180D_sample

import random
from paho.mqtt import client as mqtt
import math
import time

# The address of the subscriber to get the message from the publisher
broker = 'broker.emqx.io'
port = 1883
topic_moisture = "/mqtt/moisture"
topic_light = "/mqtt/light"
# generate client ID with pub prefix randomly
client_id = f'python-mqtt-{random.randint(0, 100)}'
light_text = None
moisture_text = None
light_val = 0
moisture_val = 0


def connect_mqtt() -> mqtt:
    global text
    def on_connect(client, userdata, flags, rc):
        print(f"Connection return code: {rc}")
        subscribe(client)

    def on_disconnect(client, userdata, rc):
        print(f"Disconnected with return code: {rc}") 
    
    def on_message(client, userdata, message, light_text=light_text, moisture_text=moisture_text):
        f_light = open("light_notification.txt", "w+")
        #f_moisture = open("moisture.txt","w+")

        if (message.topic == "/mqtt/light"):
            light_message = message.payload.decode()
            # if(light_text != light_message and light_message != None):
            #     light_text = light_message
            light_val = int(light_message)
            if light_val < 300:
                light_val = 300
            if light_val > 645:
                light_val = 645
            light_val = light_val - 300
            light_percent = math.trunc(light_val/3.45)
            light_text = str(light_percent) + "%"
            #light_text = light_message
            f_light.write(light_text)
            #time.sleep(0.1)
            print("light: " + light_message)

        # if (message.topic == "/mqtt/moisture"):
        #     moisture_message = message.payload.decode()
        #     moisture_val = int(moisture_message)
        #     #print("moisture: " + moisture_message)
        #     if (moisture_val < 50):
        #         moisture_text = "Too Dry!"
        #     elif (moisture_val > 49 and moisture_val < 300):
        #         moisture_text = "Just Right"
        #     else:
        #         moisture_text = "Too Wet!"
        #     f_moisture.write(moisture_text)
        #     print("moisture: " + moisture_message)
        #print("light: " + str(light_val) + "moisture: " + str(moisture_val))
                

        #new_message = message.payload.decode()
        # if(text != new_message and new_message != None):
        #     text = new_message
        #print(f"Received message: {text} on topic {message.topic} with QoS {message.qos})")
        
        #f.write(text)

    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_disconnect = on_disconnect
    client.on_message = on_message
    client.connect(broker, port)

    return client

def subscribe(client: mqtt):
    #client.subscribe(topic_moisture)
    client.subscribe(topic_light)
    
    print("subscribed to topic")

def run():
    client = connect_mqtt()
    client.loop_forever()



if __name__ == '__main__':
    run()