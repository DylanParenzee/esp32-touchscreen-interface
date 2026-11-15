// ESP32-S3 serial smoke test
// Guided introductory sketch, uploaded and verified on the physical board.
// Arduino IDE: ESP32S3 Dev Module, USB CDC On Boot enabled.
// Serial Monitor: 115200 baud.

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("ESP32-S3 connected!");
}

void loop() {
  Serial.println("Program running...");
  delay(1000);
}
