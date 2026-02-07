#define BLYNK_TEMPLATE_ID "TMPL3BNNzz-XS"
#define BLYNK_TEMPLATE_NAME "Smart Agriculture IoT System "

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "hule0hh4YRMqvurv9cKC5zNmKS9PKdi2";

char ssid[] = "VITC-EVENT";
char pass[] = "Eve@07&08#$";

// DHT11 sensor
#define DHTPIN D3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (!isnan(temp) && !isnan(hum)) {
    Blynk.virtualWrite(V5, temp);  
    Blynk.virtualWrite(V6, hum);   
    Blynk.virtualWrite(V7, 0);
  }
  else{
    Blynk.virtualWrite(V7, 1);
  }

  Blynk.run();  
  delay(2000);
}

