# Master-Slave BLE Communication (ESP32)

A Bluetooth Low Energy (BLE) master-slave communication system built on ESP32 boards. The Master device sends commands over BLE, and each Slave device receives the command and sends back a response. Results are observed through the Serial Monitor of each board.

---

## Group Information

**Group Name:** `<Your Group Name Here>`

| Role    | Student Name                  |
| ------- | ----------------------------- |
| Master  | Miche Louie Acompanado        |
| Slave 1 | Emmery Kelsey V. Mendoza      |
| Slave 2 | Shyane Novelle R. Canayan     |

---

## Members' Roles and Contributions

### Master: Miche Louie Acompanado
- Designed and assembled the circuit for the Master ESP32 on their own, following the wiring plan and checking each connection.
- Wrote and configured the Master code so the ESP32 acts as the BLE central device: scanning for, connecting to, and communicating with the Slave devices.
- Programmed the Master to send commands to Slave 1 and Slave 2.
- Uploaded the code, ran the Master, and verified through the Serial Monitor that commands were sent and that the Slaves' responses were received.
- Tested the full system together with the Slaves, troubleshot connection issues, and recorded the Serial Monitor output and demonstration video.

### Slave 1: Emmery Kelsey V. Mendoza
- Designed and assembled the circuit for Slave 1 on their own, and checked the wiring before powering the board.
- Set up the Slave 1 code so the ESP32 acts as a BLE peripheral that advertises itself and waits for the Master to connect.
- Programmed Slave 1 to receive commands from the Master and respond accordingly.
- Uploaded and ran the code, then tested it by confirming in the Serial Monitor that Slave 1 received the Master's commands and sent back the correct responses.
- Debugged connection and response problems and helped test Slave 1 together with the Master and Slave 2.

### Slave 2: Shyane Novelle R. Canayan
- Designed and assembled the circuit for Slave 2 on their own, and verified each connection against the wiring plan.
- Set up the Slave 2 code so the ESP32 acts as a BLE peripheral with its own identity, distinct from Slave 1, so the Master can tell the two apart.
- Programmed Slave 2 to receive commands from the Master and respond accordingly.
- Uploaded and ran the code, then tested it by confirming in the Serial Monitor that Slave 2 received the Master's commands and responded correctly.
- Debugged connection and response problems and helped test Slave 2 together with the Master and Slave 1.

### Team Workflow
Each member individually built their own wiring, uploaded and ran their own code, and tested their own board. Afterward, the three boards were tested together as one system to confirm that the Master could send commands and both Slaves could respond reliably.

---

## Repository Contents

```
├── master/        # Source code for the Master ESP32
├── slave1/        # Source code for Slave 1 ESP32
├── slave2/        # Source code for Slave 2 ESP32
├── images/        # Circuit interface photos and Serial Monitor screenshots
└── README.md
```

> Update the folder names above if they differ in your repository.

---

## Circuit Interface

### Master
![Master Circuit](images/master_circuit.jpg)

### Slave 1
![Slave 1 Circuit](images/slave1_circuit.jpg)

### Slave 2
![Slave 2 Circuit](images/slave2_circuit.jpg)

---

## Serial Monitor Screenshots

### Master (sending commands)
![Master Serial Monitor](images/master_serial.png)

### Slave 1 (responding)
![Slave 1 Serial Monitor](images/slave1_serial.png)

### Slave 2 (responding)
![Slave 2 Serial Monitor](images/slave2_serial.png)

---

## Video Demonstration

Video recording of the system in operation:

**[Watch the demo video](PASTE_YOUR_VIDEO_LINK_HERE)**

> If the video file is included in this repository instead, replace the link with its file path, e.g. `[Watch the demo video](video/demo.mp4)`.

---

## How the System Works

1. The Slaves power on and begin advertising over BLE.
2. The Master scans for and connects to the Slaves.
3. The Master sends commands to the Slaves.
4. Each Slave receives the command and sends a response back to the Master.
5. The Master and Slaves display the commands and responses in their Serial Monitors.

---

## Hardware Used

- 3 × ESP32 development boards (1 Master, 2 Slaves)
- Jumper wires, breadboards, and other components used in each member's circuit
- USB cables for power and serial communication
