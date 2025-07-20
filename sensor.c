For esp-2 with sensor 3 and sensor 4 


#include <WiFi.h>
#include <PubSubClient.h>

#define SENSOR3_PIN 34
#define SENSOR4_PIN 35

const char* ssid = "pi7";
const char* password = "1234567890";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32Client-B";  // Different from the first ESP
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.publish("test/esp32", "ESP32-B connected!");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  int sensor3Value = analogRead(SENSOR3_PIN);
  int sensor4Value = analogRead(SENSOR4_PIN);

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  String payload = "Sensor3: " + String(sensor3Value) + ", Sensor4: " + String(sensor4Value);
  client.publish("test/esp32", payload.c_str());
  Serial.println(payload.c_str());
  delay(500);
}