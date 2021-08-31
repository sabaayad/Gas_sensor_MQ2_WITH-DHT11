
#include <DHT.h>
#define DHTpin D2    //D1 of NodeMCU 
#define DHTTYPE DHT11     // DHT 11
DHT dht(DHTpin, DHT11);
int smokeA0 = D1;
// Your threshold value. You might need to change it.
int sensorThres = 600;

void setup() {
// pinMode(buzzer, OUTPUT);
 pinMode(smokeA0, INPUT);
 Serial.begin(115200);
Serial.println();
Serial.println("Status\tHumidity (%)\tTemperature (C)\t\t Gas_value \t\t ");
delay(10);
dht.begin();
}

void loop() {
 float humidity = dht.readHumidity();
 float temperature = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit
 int gasSensor = digitalRead(smokeA0);
if (isnan(humidity) || isnan(temperature)|| isnan(gasSensor)) 
  {
    Serial.println("Failed to read from DHT sensor or from gas_sensor!");
    return;
  }

  Serial.print("humidity= \t");
  Serial.print(humidity);
  Serial.print("\t\t temperature=     ");
  Serial.print(temperature);
    Serial.print("\t\t Gas_value=     ");
    Serial.print(gasSensor);
  Serial.println("\t\t");
    delay(1000);
 
}
