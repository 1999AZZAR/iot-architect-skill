#include <WiFi.h>
#include <PubSubClient.h>
#include "secrets.h"

// MQTT topic config (device-specific; override or set from secrets if needed)
const char* mqtt_topic_sub = "device/command";
const char* mqtt_topic_pub = "device/status";

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastReconnectAttempt = 0;
const unsigned long reconnectIntervalMs = 5000;

void setup_wifi() {
    delay(10);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
}

boolean tryReconnect() {
    if (client.connect("ESP32Client", MQTT_USER, MQTT_PASS)) {
        client.subscribe(mqtt_topic_sub);
        return true;
    }
    return false;
}

void setup() {
    Serial.begin(115200);
    setup_wifi();
    client.setServer(MQTT_SERVER, MQTT_PORT);
}

void loop() {
    if (!client.connected()) {
        unsigned long now = millis();
        if (now - lastReconnectAttempt >= reconnectIntervalMs) {
            lastReconnectAttempt = now;
            tryReconnect();
        }
    } else {
        client.loop();
    }
}
