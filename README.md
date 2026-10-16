# Master-Slave BLE Communication (ESP32)

A Bluetooth Low Energy (BLE) master-slave communication system built on ESP32 boards. The Master device sends commands over BLE, and each Slave device receives the command and sends back a response. Results are observed through the Serial Monitor of each board.

---

## Group Information

**Group Name:** `Team BSCA_IoT`

| Role    | Student Name                     |
| ------- | -------------------------------- |
| Master  | Miche Louie B. Acompanado        |
| Slave 1 | Emmery Kelsey V. Mendoza         |
| Slave 2 | Shyane Novelle R. Canayan        |

---

## Members' Roles and Contributions

### Master: Miche Louie Acompanado
- Designed and assembled the circuit for the Master ESP32, following the wiring plan and checking each connection.
- Wrote and configured the Master code so the ESP32 acts as the BLE central device: scanning for, connecting to, and communicating with the Slave devices.
- Programmed the Master to send commands to Slave 1 and Slave 2.
- Uploaded the code, ran the Master, and verified through the Serial Monitor that commands were sent and that the Slaves' responses were received.
- Tested the full system together with the Slaves, troubleshot connection issues, and recorded the Serial Monitor output and demonstration video.

### Slave 1: Emmery Kelsey V. Mendoza
- Designed and assembled the circuit for Slave 1, and checked the wiring before powering the board.
- Set up the Slave 1 code so the ESP32 acts as a BLE peripheral that advertises itself and waits for the Master to connect.
- Programmed Slave 1 to receive commands from the Master and respond accordingly.
- Uploaded and ran the code, then tested it by confirming in the Serial Monitor that Slave 1 received the Master's commands and sent back the correct responses.
- Debugged connection and response problems and helped test Slave 1 together with the Master and Slave 2.

### Slave 2: Shyane Novelle R. Canayan
- Designed and assembled the circuit for Slave 2, and verified each connection against the wiring plan.
- Set up the Slave 2 code so the ESP32 acts as a BLE peripheral with its own identity, distinct from Slave 1, so the Master can tell the two apart.
- Programmed Slave 2 to receive commands from the Master and respond accordingly.
- Uploaded and ran the code, then tested it by confirming in the Serial Monitor that Slave 2 received the Master's commands and responded correctly.
- Debugged connection and response problems and helped test Slave 2 together with the Master and Slave 1.

### Team Workflow
Each member individually built their own wiring, uploaded and ran their own code, and tested their own board. Afterward, the three boards were tested together as one system to confirm that the Master could send commands and both Slaves could respond reliably.

---

## Circuit Interface

### Master
<img width="2048" height="1536" alt="1" src="https://github.com/user-attachments/assets/236620d2-2969-4897-a7f2-1e3fc54a2490" />

### Slave 1 and Slave 2
<img width="2048" height="1536" alt="2" src="https://github.com/user-attachments/assets/a963ebc3-16ab-4ac8-baa2-b92fd32e1e9b" />

<img width="2048" height="1536" alt="844000591_1156119526770264_2581449025088546058_n" src="https://github.com/user-attachments/assets/bc465e98-f671-4cf6-9c24-763544047bc9" />

---

## Serial Monitor Screenshots

### Master (sending commands)
<img width="1919" height="1079" alt="845902077_1644869734036692_8862839773468555666_n" src="https://github.com/user-attachments/assets/a63dd20f-9f85-4f60-8c70-4eb4dd30f983" />

### Slave 1 (responding)
<img width="1919" height="1000" alt="844068087_2559902004513005_1167909391716447835_n" src="https://github.com/user-attachments/assets/a563e3a5-0ea6-45ba-b9cc-0515a7c59376" />

### Slave 2 (responding)
<img width="1276" height="751" alt="843410135_1871841297513117_6047440135930355258_n" src="https://github.com/user-attachments/assets/78b3d836-d3bf-4e56-8603-67b9ee92c0b8" />


---

## Video Demonstration

Video recording of the system in operation:

**[Watch the demo video]

https://github.com/user-attachments/assets/7c250565-8a7e-44be-b83c-debe7a789787


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
