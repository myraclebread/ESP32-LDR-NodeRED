#include <WiFi.h>
#include <PubSubClient.h>

#define LDR_PIN 32          // GPIO pin connected to the LDR sensor

// Wi-Fi Credentials
const char* ssid = ""; //your wifi ssid
const char* password = ""; //your wifi password

// MQTT Broker Settings (non-TLS)
const char* mqtt_server = "broker.emqx.io";
const int mqtt_port = 1883;  // Non-SSL MQTT port

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");

  // Connect to MQTT Broker
  client.setServer(mqtt_server, mqtt_port);
  reconnect();
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP32_LDR_Client")) {
      Serial.println("Connected to EMQX Broker!");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Retrying in 5 seconds...");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int ldr_value = analogRead(LDR_PIN);  // Read LDR sensor data

  // Calculate brightness percentage (inverted scale, assuming max 4000)
  int brightness_percent = ((4000 - ldr_value) * 100) / 4000;

  Serial.print("Brightness: ");
  Serial.print(brightness_percent);
  Serial.println("%");

  // Send brightness value via MQTT
  String brightnessPayload = String(brightness_percent);
  client.publish("uwu/sensor/brightness", brightnessPayload.c_str());

  delay(2000);  // Send every 2 seconds
}
