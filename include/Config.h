#ifndef CONFIG_H
#define CONFIG_H

#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <WiFiClientSecure.h> // Required including because of ArduinoWebSockets
#include <HTTPClient.h>// Required including because of ArduinoWebSockets
#include <OneButton.h>

// OneButton
#define BUTTON_PIN 32                                                                                                                            
OneButton button(BUTTON_PIN, true, true);

// Buzzer
#define BUZZER_PIN 25

// Fingerprint sensor configuration
#define FINGERPRINT_BAUD_RATE 57600
#define FINGERPRINT_RX_PIN 16
#define FINGERPRINT_TX_PIN 17

// LCD
#define LCD_ADDRESS 0x27
#define LCD_WIDTH 16
#define LCD_HEIGHT 2

// RFID
#define RFID_SS_PIN 21
#define RFID_RST_PIN 33

// SD Card
#define SD_CS_PIN 5

// OLED
#define OLED_ADDRESS 0x3C
#define OLED_WIDTH 128
#define OLED_HEIGHT 64

// WiFi
#define WIFI_SSID "PLDT WIFI"
#define WIFI_PASSWORD "@PLDTWIFIkr39h"
#define RSSI_LOW_THRESHOLD -70

// REST API URL
#define REST_API_URL "https://api.example.com/v1"
#define ATTENDANCE_RECORDING_WEBSOCKET_URL "https://api.example.com/websockets/record-attendance"

// API Key
#define API_KEY "1234567890"

// Device ID
#define DEVICE_ID "1234567890"

// Device Name
#define DEVICE_NAME "ESP32-RFID-Attendance"

// Log Level
#define DEBUG

struct RFIDCard {
	String hash;
};

// * LCD Constants
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_WIDTH, LCD_HEIGHT);

// * RFID Constants
MFRC522 rfid(RFID_SS_PIN, RFID_RST_PIN);

// * Logging
#ifdef DEBUG
#define LOG_LEVEL LOG_LEVEL_VERBOSE
#else
#define LOG_LEVEL LOG_LEVEL_INFO
#endif

#endif // CONFIG_H
