#ifndef AMIIBO_DETECTOR
#define AMIIBO_DETECTOR

#include <Arduino.h>

#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

// TODO: need the values for the pins
extern int trigPin;
extern int echoPin;

bool soundDetection();

#endif // !AMIIBO_DETECTOR
