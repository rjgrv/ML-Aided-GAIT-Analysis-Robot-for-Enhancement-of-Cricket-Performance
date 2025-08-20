# ML-Aided-GAIT-Analysis-Robot-for-Enhancement-of-Cricket-Performance

# CrickGait: Live Feed & Piezo Data (Frontend)

This is the **Streamlit dashboard** that shows:
- Live camera feed from Raspberry Pi
- Shot classification (via ML model)
- Real-time Piezo sensor data from ESP32 devices

---

## 🚀 Features
- **Camera Feed**: Displays live video from Raspberry Pi (`/video_feed` endpoint).
- **Shot Classification**: Uses ML model running on Raspberry Pi to classify cricket shots.
- **Piezo Sensor Data**: Plots real-time data from ESP32 sensors via MQTT → Flask → Streamlit.

---

## 🛠️ Installation
1. Clone this repo:
   ```bash
   git clone https://github.com/your-repo/crickgait.git
   cd crickgait/frontend
