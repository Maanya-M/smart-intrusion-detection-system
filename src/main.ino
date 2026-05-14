#include <SoftwareSerial.h>


SoftwareSerial esp(2, 3); // Arduino RX, TX

// Sensor pin
int fsrPin = A0;
int threshold = 500;

// WiFi + server details (replace with your values later)
String ssid = "Maanya's iphone";
String password = "maanya22";

void setup() {
  Serial.begin(9600);
  esp.begin(9600);

  Serial.println("System Starting...");

  connectWiFi();
}

void loop() {
  int sensorValue = analogRead(fsrPin);

  Serial.print("FSR Value: ");
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    Serial.println("INTRUDER DETECTED!");

    sendAlert();

    delay(5000); // avoid multiple alerts
  }

  delay(500);
}

void connectWiFi() {
  Serial.println("Connecting to WiFi...");

  esp.println("AT");
  delay(1000);

  esp.println("AT+CWMODE=1");
  delay(1000);

  esp.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");
  delay(5000);

  Serial.println("WiFi Connected (if credentials are correct)");
}

void sendAlert() {
  Serial.println("Sending Alert to Phone...");

  // Simple simulation (you can upgrade to Blynk/Firebase later)
  esp.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80");
  delay(2000);

  String alert = "GET /update?api_key=YOUR_API_KEY&field1=1 HTTP/1.1\r\nHost: api.thingspeak.com\r\n\r\n";

  esp.print("AT+CIPSEND=");
  esp.println(alert.length());
  delay(1000);

  esp.print(alert);
  delay(1000);

  Serial.println("Alert Sent!");
}
