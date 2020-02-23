#include "config.h"
#include "filters.h"
#include "wifi_functions.h"
#include <ArduinoJson.h>

StaticJsonDocument<700> doc;
char params[200];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Initializing");
  setup_wifi();

}

void loop() {
  // put your main code here, to run repeatedly:
  sprintf(params, "id=%s&appid=%s", id, api);
  http_get(params, requestBuffer, responseBuffer);

  // Deserialize the weather data
  DeserializationError error = deserializeJson(doc, responseBuffer);
  // Test if parsing succeeds.
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }
  char[] weather = doc["weather"]["main"];
  if (strstr(weather, "rain") != NULL || strstr(weather, "Rain") != NULL) {
    // Send notification for umbrella
    // Sends message to online server
    sprintf(body, "Rain predicted. Take umbrella off the shelf");
    http_post(body, requestBuffer, responseBuffer);
  }

  
  delay(10000);
}
