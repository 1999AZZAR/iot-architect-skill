---
name: iot-architect
description: Comprehensive IoT system design skill for hardware selection, network architecture, and firmware/backend orchestration.
---

# IoT Architect Skill

Precision engineering for distributed hardware networks. This skill focuses on the structural integrity and scalability of IoT ecosystems.

## Core Capabilities

### 1. Network Topology Design
Plan how your devices talk to the brain.
- **Protocols:** MQTT (standard), HTTP/REST, WebSockets.
- **Security:** TLS implementation, Scoped API Tokens, Network Isolation.
- **Topology:** Star (Standard Hub/Spoke), Mesh (LoRa/Zigbee).

### 2. Hardware Selection & Pinout
Optimize component choice for efficiency and cost.
- **MCUs:** ESP32, ESP8266, Arduino, Raspberry Pi.
- **Sensors:** Power consumption analysis and bus selection (I2C, SPI, UART).
- **Pinout Planning:** Preventing conflict and ensuring PWM/Analog availability.

### 3. Firmware & Backend Boilerplate
Generate high-quality, production-ready starting points.
- **C++ (Arduino/ESP-IDF):** Robust MQTT clients with auto-reconnect.
- **Python (FastAPI):** High-performance orchestration layers.
- **Docker:** Deployment-ready containerization.

### 4. System Visualization
Generate Mermaid.js diagrams for architecture overview.

## Automation: Architecture Tool

Run the helper script to generate blueprints.

```bash
python3 scripts/architect.py --project "Smart Farm" --nodes "esp32-node-1,esp32-node-2" --sensors "dht22,moisture"
```

## Best Practices
- **Idempotency:** Ensure devices can recover state after power loss.
- **Efficiency:** "Just enough engineering to get it done well." (Azzar's Rule).
- **Security:** Never hardcode Wi-Fi or MQTT credentials in firmware.
