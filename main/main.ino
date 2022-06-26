// Includes...
#include "SR04.h"
#include "LiquidCrystal.h"

// Pin locations on the arduino board (for the sensor).
#define TRIG_PIN 2
#define ECHO_PIN 3

// Pin locations on the arduino board (for the display).
#define BS_PIN 7
#define E_PIN 8
#define D4_PIN 9
#define D5_PIN 10
#define D6_PIN 11
#define D7_PIN 12

// Sensor.
SR04 sensor = SR04(ECHO_PIN,TRIG_PIN);

// Current distance reading by the sensor.
long distance;
const long MAX_DISTANCE = 1185;

// The display.
LiquidCrystal lcd(BS_PIN, E_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

void setup() {
  // Initialise the display.
  lcd.begin(16, 2);
  delay(1000);
}

void loop() {
  // Read the current distance from the sensor.
  distance = sensor.Distance();

  outputReading();

  delay(800);
}

// Calls the respective function for outputting the reading to the display, 
// based on whether the measurement is within the maximum distance.
void outputReading() {
  lcd.clear();
  if (distance >= MAX_DISTANCE) { outOfRange(); return; }
  
  inRange();
}

// Outputs the reading to the display.
void inRange() {
  lcd.setCursor(0, 0);
  lcd.print("Distance to obj:");
  lcd.setCursor(0, 1);
  lcd.print("              cm");
  lcd.setCursor(0, 1);
  lcd.print(distance);
}

// Outputs a failure message to the display since an accurate distance reading wasn't retrieved.
void outOfRange() {
  lcd.setCursor(0, 0);
  lcd.print("Failed to detect");
  lcd.setCursor(0, 1);
  lcd.print("obj in range... ");
}
