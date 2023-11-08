#include <TinyGPS++.h>
#include <HardwareSerial.h>

TinyGPSPlus gps;
HardwareSerial GPS(2); // Use Serial2 (RX2=GPIO16, TX2=GPIO17) on ESP32 DevKit

void setup() {
  Serial.begin(115200);
  GPS.begin(9600);
  Serial.println("Starting GPS");
}

void loop() {
  if (GPS.available()) {
    if (gps.encode(GPS.read())) {
      if (gps.location.isValid()) {
        Serial.print("Latitude: ");
        Serial.println(gps.location.lat(), 6);
        Serial.print("Longitude: ");
        Serial.println(gps.location.lng(), 6);
        Serial.print("Altitude (meters): ");
        Serial.println(gps.altitude.meters());
        Serial.print("Speed (km/h): ");
        Serial.println(gps.speed.kmph());
        Serial.print("Date: ");
        Serial.print(gps.date.year());
        Serial.print("-");
        Serial.print(gps.date.month());
        Serial.print("-");
        Serial.print(gps.date.day());
        Serial.print("  Time: ");
        Serial.print(gps.time.hour());
        Serial.print(":");
        Serial.print(gps.time.minute());
        Serial.print(":");
        Serial.println(gps.time.second());
        delay(500);
      }
    } 
 }
}
