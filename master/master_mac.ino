#include <Arduino.h>
#include <BLEDevice.h>

const int BUTTON_PIN = 18;

const char *SLAVE_MACS[] = { "aa:bb:cc:dd:ee:01", "aa:bb:cc:dd:ee:02" };

const char *SERVICE_UUIDS[] = {
  "2b92513e-afed-40ac-afa6-e54c63acdceb", // Slave 1
  "2b92513e-afed-40ac-afa6-e54c63acdcec"  // Slave 2
};
const char *CHAR_UUID = "ea3d7c32-0013-4447-8f7b-47b959b5cddc";

BLEClient *clients[2];
BLERemoteCharacteristic *leds[2] = {nullptr, nullptr};
int sentState[2] = {-1, -1};
unsigned long lastTry[2] = {0, 0};

bool lastReading = false, pressed = false;
unsigned long changedAt = 0;

bool connectSlave(int n) {
  Serial.printf("Connecting slave %d...\n", n + 1);
  leds[n] = nullptr;
  if (!clients[n]->connect(BLEAddress(SLAVE_MACS[n]), BLE_ADDR_TYPE_PUBLIC, 5000)) {
    Serial.printf("Slave %d connection failed\n", n + 1);
    return false;
  }
  BLERemoteService *svc = clients[n]->getService(SERVICE_UUIDS[n]);
  if (svc) leds[n] = svc->getCharacteristic(BLEUUID(CHAR_UUID));
  if (leds[n] && leds[n]->canWrite()) {
    sentState[n] = -1;
    Serial.printf("Slave %d connected\n", n + 1);
    return true;
  }
  Serial.printf("Slave %d characteristic not found\n", n + 1);
  leds[n] = nullptr;
  clients[n]->disconnect();
  return false;
}

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lastReading = pressed = digitalRead(BUTTON_PIN) == LOW;
  BLEDevice::init("BCA188 Master");
  Serial.print("Master MAC: ");
  Serial.println(BLEDevice::getAddress().toString().c_str());
  for (int n = 0; n < 2; n++) clients[n] = BLEDevice::createClient();
}

void loop() {
  // Debounced button (pressed = LOW because of INPUT_PULLUP)
  bool reading = digitalRead(BUTTON_PIN) == LOW;
  if (reading != lastReading) { lastReading = reading; changedAt = millis(); }
  if (millis() - changedAt >= 30) pressed = reading;

  for (int n = 0; n < 2; n++) {
    if (!clients[n]->isConnected()) {
      if (leds[n]) Serial.printf("Slave %d disconnected\n", n + 1);
      leds[n] = nullptr;
      if (millis() - lastTry[n] >= 3000) {   // retry every 3 s
        lastTry[n] = millis();
        connectSlave(n);
      }
      continue;
    }
    if (leds[n] && sentState[n] != (int)pressed) {
      uint8_t v = pressed ? '1' : '0';
      if (leds[n]->writeValue(&v, 1, true)) {
        sentState[n] = pressed;
        Serial.printf("Slave %d LED %s\n", n + 1, pressed ? "ON" : "OFF");
      } else {
        Serial.printf("Slave %d write failed\n", n + 1);
        leds[n] = nullptr;
        clients[n]->disconnect();
      }
    }
  }
  delay(5);
}
