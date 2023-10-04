
//#include "DHT.h"

// Uncomment one of the lines below for whatever DHT sensor type you're using!
//#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
//#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321

#include <DHT.h>

#define DHTPIN 4  // Define the GPIO pin where the DHT11 data pin is connected
#define DHTTYPE DHT11  // Define the type of DHT sensor (DHT11, DHT22, or DHT21)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 Sensor Test");
  dht.begin();
}

void loop() {
  delay(5000);  // Delay for 2 seconds between measurements

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
}
