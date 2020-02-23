#include "config.h"
#include "filters.h"
#include "wifi_functions.h"
#include <ArduinoJson.h>

StaticJsonDocument<500> doc;
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
  String weather = doc["weather"]["main"];
  Serial.println(weather);
  delay(10000);
}
