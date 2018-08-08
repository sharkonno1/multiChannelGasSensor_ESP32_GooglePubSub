# multiChannelGasSensor_ESP32_GooglePubSub
Intro: 
This project is capable of getting Gas sensor data to Google Cloud in real-time, and this has the convenient to support Google Pub-sub iot
integration with google firebase and cloud funtions:
  https://firebase.google.com/docs/functions/pubsub-events?hl=en
Step 1: Download google-cloud-iot-arduino-master: https://github.com/GoogleCloudPlatform/google-cloud-iot-arduino/tree/master/examples
                 pubsubclient-master: https://github.com/knolleary/pubsubclient
        push these libraries into your Arduino Library
        
Step 2: Connect your GasSensor to your ESP32 through I2c and make sure the i2c address is default 0x04
Step 3: Modify the file ciotc_config.h, change your wifi, password, google project id, google iot device name and private key accordingly
Step 4: Your should be able to publish your Gas Sensor data to Google Pub Sub Every 10 seconds. 
