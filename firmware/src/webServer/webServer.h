#ifndef WEB_SERVER
#define WEB_SERVER

#include <ArduinoJson.h>
#include <ESPAsyncWebServer.h>
#include <WiFi.h>

extern AsyncWebServer server;

void endpoints();

#endif // !WEB_SERVER
