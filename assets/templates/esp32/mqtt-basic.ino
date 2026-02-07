#include <WiFi.h>
#include <PubSubClient.h>

// WiFi Config
const char* ssid = "SSID_NAME";
const char* password = "SSID_PASS";

// MQTT Config
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic_sub = "device/command";
const char* mqtt_topic_pub = "device/status";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
    delay(10);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
}

void reconnect() {
    while (!client.connected()) {
        if (client.connect("ESP32Client")) {
            client.subscribe(mqtt_topic_sub);
        } else {
            delay(5000);
        }
    }
}

void setup() {
    Serial.begin(115200);
    setup_wifi();
    client.setServer(mqtt_server, mqtt_port);
}

void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
}
