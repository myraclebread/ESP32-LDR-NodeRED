# ESP32-LDR-NodeRED
This project integrates an ESP32 with an LDR (Light Dependent Resistor) sensor to measure light intensity and publish the data to an MQTT broker. The data is then processed and visualized in Node-RED

Features

✅ ESP32 reads LDR sensor data and converts it to a percentage (1-100%).
✅ MQTT communication using the EMQX Cloud broker.
✅ Node-RED flow for real-time data visualization and analysis.
✅ Dynamic lighting condition labels (e.g., Dark, Bright, Very Bright).

Components Used

    ESP32 DevKit V1
    LDR Sensor (Light Dependent Resistor)
    EMQX Cloud MQTT Broker
    Node-RED Dashboard

Project Structure

📂 pw2.ino → ESP32 firmware for reading the LDR sensor and publishing MQTT messages.
📂 flows.json → Node-RED flow for processing and visualizing the sensor data.
📂 README.md → Project documentation.

Setup Instructions

    Upload the ESP32 code to your board (modify WiFi & MQTT settings if needed).
    Import the Node-RED flow from node-red-flow.json.
    Connect to the MQTT broker and start receiving sensor data.
