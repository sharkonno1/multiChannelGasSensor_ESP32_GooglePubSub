/******************************************************************************
 * Copyright 2018 Google
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#define ESP32
#include <Wire.h>
#include "MultichannelGasSensor.h"
#include <Arduino.h>
#include <CloudIoTCore.h>
#include <CloudIoTCoreMQTTClient.h>
#include <WiFi.h>
#include "ciotc_config.h"  // Configure with your settings
#include <time.h>

CloudIoTCoreDevice device(project_id, location, registry_id, device_id,
                          private_key_str);
CloudIoTCoreMQTTClient client(device);

long lastMsg = 0;
char msg[20];
int counter = 0;
bool first = true; 
const int LED_PIN = 5;
  float nh3,co,no2,c3h8,c4h10,ch4,h2,c2h50h;

void callback(uint8_t *payload, unsigned int length) {
  Serial.print("payload: ");
  char val[length];
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    val[i] = (char)payload[i];
  }
  Serial.println();

  // int ret = rbase64.decode(val);
  int ret = 0;
  if (ret == 0) {
    // we got '1' -> on
    if (val[0] == '1') {
      Serial.println("High");
      digitalWrite(LED_PIN, HIGH);
    } else {
      // we got '0' -> on
      Serial.println("Low");
      digitalWrite(LED_PIN, LOW);
    }
  } else {
    Serial.println("Error decoding");
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);

  // put your setup code here, to run once:
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }

  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
  Serial.println("Waiting on time sync...");
  while (time(nullptr) < 1510644967) {
    delay(10);
  }

  Serial.println("Connecting to mqtt.googleapis.com");
  client.connect();
  gas.begin(0x04);
  gas.powerOn();
}

void loop() {
  client.loop();
    if(first){
      nh3 = gas.measure_NH3();
      c3h8 = gas.measure_C3H8();
      snprintf(msg, 30, "{\"NH3\": %.2f,\"C3H8\": %.2f}", nh3,c3h8);
      first = false;
    }else{
      c4h10 = gas.measure_C4H10();
      ch4 = gas.measure_CH4();
      snprintf(msg,30,"{\"C4H10\": %.2f,\"CH4\": %.2f}",c4h10,ch4);
      first = true; 
     }
      Serial.println("Publish message");
      /* publish the message */
      client.publishState(msg);
      delay(10000);
}
