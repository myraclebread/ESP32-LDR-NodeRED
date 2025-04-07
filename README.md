# 📡 ESP32-LDR-NodeRED

This project integrates an **ESP32** with an **LDR (Light Dependent Resistor)** sensor to measure light intensity and publish the data to an **MQTT broker**. The data is then processed and visualized in **Node-RED**, with optional integrations including **Telegram bot alerts** and **MySQL database storage**.

---

## ✨ Features

- ✅ ESP32 reads LDR sensor data and converts it to a brightness percentage (0–100%)
- ✅ MQTT communication using EMQX Cloud (or your preferred broker)
- ✅ Node-RED flow for real-time data visualization and automation
- ✅ Telegram bot command support (`/brightness`, `/stop`)
- ✅ MySQL storage for historical logging
- ✅ Dynamic light condition labels (e.g., 🌑 Dark, 🌤 Bright, ☀️ Very Bright)

---

## 🧰 Components Used

- ESP32 DevKit V1  
- LDR Sensor (Light Dependent Resistor)  
- EMQX Cloud MQTT Broker *(or another MQTT service)*  
- Node-RED  
- Telegram Bot  
- MySQL Server  

---

## 🗂 Project Structure

```
📂 pw2.ino           → ESP32 firmware (reads LDR & publishes MQTT)  
📂 flows.json        → Node-RED flow (handles MQTT, Telegram, MySQL)  
📂 README.md         → Project documentation  
```

---

## 🚀 Setup Instructions

### 1️⃣ ESP32 Setup

- Open `pw2.ino` in Arduino IDE.
- Replace the following with **your own values**:

```cpp
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const char* mqtt_server = "broker.emqx.io"; // Change if using another broker
const char* mqtt_topic = "your/unique/topic"; // Set your own unique topic!
```

- Upload the sketch to your ESP32.

---

### 2️⃣ Node-RED Flow

- Import `flows.json` into Node-RED.
- Update the following:
  - 🟢 **MQTT Broker**  
    - If you're using **EMQX**, no changes are needed.  
    - Otherwise, update the broker address, port, and topic.
  - 🟢 **MQTT Topic**  
    - Use **your own unique topic** to avoid data mixups.
  - 🟢 **Telegram Bot**  
    - Add your **Telegram bot token**.  
    - Supports simple command messages like `/brightness` to start updates and `/stop` to end them.
  - 🟢 **MySQL**  
    - Set your **MySQL host**, **username**, **password**, and **database name**.  
    - The flow includes logic to insert brightness data into a `brightness_logs` table.

---

## 📦 MySQL Table Schema Example

```sql
CREATE TABLE brightness_logs (
  id INT AUTO_INCREMENT PRIMARY KEY,
  brightness INT NOT NULL,
  timestamp DATETIME DEFAULT CURRENT_TIMESTAMP
);
```

---

## 🧪 Test Your Setup

1. Power on the ESP32.  
2. Open Node-RED.  
3. Open Telegram and send `/brightness` to your bot.  
4. Watch live brightness values arrive via MQTT and Telegram.  
5. Use `/stop` to stop the updates.  
6. Verify that MySQL is logging your data.

---

## 📝 Notes

- Your MQTT topic **must be unique** to avoid receiving others' data.  
- You **must use your own Telegram bot token** and **MySQL credentials**.  
- Your WiFi SSID and password must be updated in the `.ino` file.  
- The included flow assumes EMQX Cloud as default MQTT, but is broker-agnostic.

---

## 🤝 Credits

- MQTT via [EMQX Cloud](https://www.emqx.com/en/cloud)  
- Telegram using [node-red-contrib-telegrambot](https://flows.nodered.org/node/node-red-contrib-telegrambot)  
- MySQL via [node-red-node-mysql](https://flows.nodered.org/node/node-red-node-mysql)  

---
