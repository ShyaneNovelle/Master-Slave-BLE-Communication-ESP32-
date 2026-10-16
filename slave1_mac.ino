#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define LED_PIN 4

#define SERVICE_UUID        "2b92513e-afed-40ac-afa6-e54c63acdceb"
#define CHARACTERISTIC_UUID "ea3d7c32-0013-4447-8f7b-47b959b5cddc"

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *pServer) {
    Serial.println("Master connected");
  }
  void onDisconnect(BLEServer *pServer) {
    Serial.println("Master disconnected, restarting advertising...");
    BLEDevice::startAdvertising();
  }
};

class MyCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    auto value = pCharacteristic->getValue();   // works with String or std::string
    if (value.length() > 0) {
      char c = value[0];
      Serial.print("Received Value: ");
      Serial.println(c);
      digitalWrite(LED_PIN, c == '1' ? HIGH : LOW);
      Serial.println(c == '1' ? "LED ON" : "LED OFF");
    }
  }
};

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  BLEDevice::init("BCA188 Slave 1");
  Serial.print("Slave 1 MAC: ");
  Serial.println(BLEDevice::getAddress().toString().c_str());

  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE);
  pCharacteristic->setCallbacks(new MyCallbacks());
  pService->start();

  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMaxPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Slave 1 advertising...");
}

void loop() {
  delay(2000);
}
