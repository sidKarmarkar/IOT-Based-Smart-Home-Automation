# Smart Home Automation System

This project introduces a comprehensive smart home automation solution, encompassing fan and light automation, as well as gas and flame detection. Utilizing advanced sensors and algorithms, the system monitors environmental changes and responds to ensure occupant safety and convenience. The fan and light automation feature enables remote control, optimizing comfort and energy efficiency by adjusting fan speed and light brightness based on ambient light and temperature. The gas and flame detection capabilities employ sophisticated sensors to identify hazardous gas levels and alert occupants of potential leaks. Additionally, flame detection triggers alerts to prevent fire hazards.

## Components and Features

### NodeMCU v1.0 Board
The NodeMCU v1.0 is a versatile microcontroller board with built-in WiFi, facilitating remote control via the internet. It interacts seamlessly with sensors like the DHT11 and PIR sensors. The DHT11 sensor measures temperature and humidity, while the PIR sensor detects motion, enabling the system to determine room occupancy and environmental conditions.

### Sensors and Relays
- **DHT11 Sensor**: Monitors temperature and humidity.
- **PIR Sensor**: Detects human presence.
- **5V Relays**: Control the AC and fan based on sensor inputs.

### Automation Logic
The system aims to enhance energy efficiency by activating the AC or fan only when necessary:
- If room temperature exceeds 22°C, the AC turns on.
- If room temperature is below 22°C, the fan activates.
- The PIR sensor ensures the AC or fan operates only when the room is occupied.

### System Integration
- **Hardware Setup**: The NodeMCU v1.0 board, DHT11, and PIR sensors are mounted on a breadboard and connected through their respective pins. The 5V relays are linked to the AC and fan, enabling on/off control.
- **Software Setup**: The NodeMCU is programmed via the Arduino IDE. The code continuously reads sensor data, processes it, and controls the relays. Internet connectivity allows for remote management through a web interface.

### Remote Control
The built-in WiFi module of the NodeMCU facilitates internet communication, allowing users to control the system remotely through a web-based interface.

## Getting Started

### Prerequisites
- NodeMCU v1.0 board
- DHT11 temperature and humidity sensor
- PIR motion sensor
- Two 5V relays
- Breadboard and jumper wires
- Arduino IDE

### Installation and Setup
1. **Hardware Assembly**: Connect the NodeMCU, DHT11, PIR sensors, and relays on the breadboard.
2. **Programming**: Write and upload the Arduino code to the NodeMCU using the Arduino IDE.
3. **Internet Connectivity**: Connect the NodeMCU to a WiFi network for remote control.
4. **Web Interface**: Set up a web interface to manage the system remotely.

## Conclusion
This smart home automation system integrates fan and light control with gas and flame detection, leveraging the NodeMCU v1.0 board and various sensors. The system ensures a comfortable, energy-efficient, and safe living environment, with the added benefit of remote control via the internet.
