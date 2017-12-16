/* SPIFFS filesystem example.
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <WiFi.h>
#include <HardwareSerial.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_spiffs.h"
#include "SPIFFS.h"
#include "nvs_flash.h"

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASS";

static const char *TAG = "example";

void setup()
{
  Serial.begin(115200);

  if(!SPIFFS.begin(true, "/spiffs", 5)){
    Serial.println("SPIFFS Mount Failed");
    return;
  }

  nvs_flash_init();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

extern "C" void app_main(void)
{
    setup();
}
