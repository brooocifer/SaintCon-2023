#define BLINKLED D0

#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

const char* ssid = "STCONHOSPITAL";
const char* password = "SooperSecre7!";

const char* host = "192.168.1.2"; // Your domain
String path = "/light6.json"; // Path to lightn.json on website - change "n" to server number before compile/upload
const int pin = 13;     

void setup() {
  pinMode(BLINKLED, OUTPUT);
  pinMode(pin, OUTPUT);
  pinMode(pin, HIGH);
  Serial.begin(115200);

  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  digitalWrite(BLINKLED, HIGH);
  
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(host);
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  client.print(String("GET ") + path + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: keep-alive\r\n\r\n");

  digitalWrite(BLINKLED, LOW);
  delay(500); // wait for server to respond

  // read response
  String section="header";
  while(client.available()) {
    String line = client.readStringUntil('\r');
    // Serial.print(line);
    // we'll parse the HTML body here
    if (section=="header") { // headers..
      Serial.print(".");
      if (line=="\n") { // skips the empty space at the beginning
        section="json";
      }
    }
    else if (section=="json") { // print the good stuff
      section="ignore";
      String result = line.substring(1);

      // Parse JSON
      int size = result.length() + 1;
      char json[size];
      result.toCharArray(json, size);
      StaticJsonDocument<200> jsonBuffer;
      DeserializationError error = deserializeJson(jsonBuffer, json);
      if (error) {
        Serial.println("Deserialization failed");
        return;
      }

      // Make the decision to turn off or on the LED
      if (strcmp(jsonBuffer["light"], "on") == 0) {
        digitalWrite(pin, HIGH);
        Serial.println("LED ON");
      }
      else {
        digitalWrite(pin, LOW);
        Serial.println("led off");
      }
    }
  }
  Serial.print("closing connection. ");
}
