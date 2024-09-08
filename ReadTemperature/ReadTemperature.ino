#include <DHT11.h>

#define DHTPIN 7 // what pin we're connected to

// Initialize DHT sensor
DHT11 dht(DHTPIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
// Wait a few seconds between measurements.
  delay(5000);

    int temperature = 0;
    int humidity = 0;

    // Attempt to read the temperature and humidity values from the DHT11 sensor.
    int result = dht.readTemperatureHumidity(temperature, humidity);

  if(result == 0)
  {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C\tRelative Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }
  else
  {
    Serial.println(DHT11::getErrorString(result));
  }
}