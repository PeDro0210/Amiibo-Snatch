#include "webServer.h"
#include "blockReader/blockReader.h"

AsyncWebServer server(80);

void endpoints() {
  server.on("/getid", HTTP_GET, [](AsyncWebServerRequest *request) {
    StaticJsonDocument<200> jsonDoc; // fuck this shit
    jsonDoc["data"] = getModelId();

    // Serialize JSON to string
    String jsonResponse;
    serializeJson(jsonDoc, jsonResponse);

    // Send JSON response
    request->send(200, "application/json", jsonResponse);
  });
}
