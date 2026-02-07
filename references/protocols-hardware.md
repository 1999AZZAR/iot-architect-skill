# IoT Architecture Reference

## Communication Protocols
- **MQTT**: Lightweight messaging (ideal for low bandwidth).
  - Use QoS 1 for critical commands.
  - Topics: `device/{id}/status`, `device/{id}/command`.
- **HTTP/REST**: Heavy, stateless (good for config sync).
- **WebSocket**: Real-time bidirectional (dashboard).
- **LoRaWAN**: Long range, low power (smart city).

## Hardware Standards (ESP32)
- **GPIO**: Use specific pins for safety (avoid strapping pins).
  - Safe Output: 4, 5, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33.
  - Input Only: 34, 35, 36, 39.
- **Power**: 3.3V Logic Level. Do not connect 5V directly to GPIO.
- **Deep Sleep**: Use RTC memory to persist state.

## Security
- **TLS/SSL**: Mandatory for all internet traffic.
- **OTA Updates**: Must be signed and versioned.
- **Hardcoded Secrets**: FORBIDDEN. Use SPIFFS/NVS or provisioning.
