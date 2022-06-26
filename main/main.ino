// Includes...
#include "SR04.h"
#include "LiquidCrystal.h"

// Pin locations on the arduino board & sensor.
#define TRIG_PIN 2
#define ECHO_PIN 3

// Sensor.
SR04 sensor = SR04(ECHO_PIN,TRIG_PIN);

// Current distance reading by the sensor.
long distance;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // Read the current distance from the sensor.
  distance = sensor.Distance();
}
