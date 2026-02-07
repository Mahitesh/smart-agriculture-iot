void setup() {
  Serial.begin(9600);
  Serial.println("ESP8266 alive");
}

void loop() {
  Serial.println("Loop running");
  delay(2000);
}
