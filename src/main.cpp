#include <WiFi.h>
#include <HardwareSerial.h>
#include <Wire.h>
#include <Config.h>
#include <ArduinoLog.h>
#include <LCDMenuController.h>

void printToLCD(String message)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);
}

void setup()
{
  Serial.begin(115200);
  Log.begin(LOG_LEVEL, &Serial);
  digitalWrite(BUZZER_PIN, LOW);

  Log.noticeln("Initializing LCD...");
  lcd.init();
  Log.noticeln("Turning LCD Backlights...");
  lcd.backlight();
  Log.noticeln("Setting up...");
  printToLCD("Setting up...");
  delay(500);

  // WiFi
  Log.noticeln("Trying to connect to the wifi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Log.noticeln("Finding Connection...");
    delay(500);
  }
  Log.noticeln("\nConnected to the WiFi!");
  printToLCD("Connected to WiFi");

  // Display Connection Details
  Log.infoln("Local IP: %s", WiFi.localIP().toString().c_str());
  Log.infoln("MAC Address: %s", WiFi.macAddress().c_str());
  Log.infoln("RSSI: %d dBm", WiFi.RSSI());
  Log.infoln("Subnet Mask: %s", WiFi.subnetMask().toString().c_str());
  Log.infoln("Gateway IP: %s", WiFi.gatewayIP().toString().c_str());
  Log.infoln("DNS IP: %s", WiFi.dnsIP().toString().c_str());
  if (WiFi.RSSI() < RSSI_LOW_THRESHOLD)
  {
    Log.error("RSSI is too low! (%d dBm)", WiFi.RSSI());
    printToLCD("RSSI is too low!");
  }

  // Buzzer
  Log.noticeln("Initializing Buzzer...");
  pinMode(BUZZER_PIN, OUTPUT);
  delay(1000);
}

void loop()
{
  button.tick();
}
