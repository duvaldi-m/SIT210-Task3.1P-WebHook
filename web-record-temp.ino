
// This #include statement was automatically added by the Particle IDE.
#include <Grove_Temperature_And_Humidity_Sensor.h>

#define DHTPIN 	D3     // set pin

DHT dht(DHTPIN);


void setup() {
    dht.begin();
    pinMode(DHTPIN, OUTPUT);
    Serial.begin(9600);
	Serial.println("DHT22 Begin!!!");

}

void loop() {
    // Read temperature as Celsius
    float t = dht.getTempCelcius();
	
	if (isnan(t))
	{
		Serial.println("Failed to read from DHT11 sensor!");
		return;
	}
	else
	{
    	Serial.print("Temp: ");
    	Serial.print(t);
    	Serial.println("*C ");
    	Serial.println();Serial.println();
    	
    	//Sending atual temperature reading to thingspeak
    	//uncomment if testing code is not used 
    	//String temp = String::format("{\"temp\": %d}", t);
    	//Particle.publish("temp", temp, PRIVATE);
    	//delay(30000);
	}
	//3 lines below is sending a fake value for testing purpose
	//if sensor is not working proparly 
	//if sensor works these can be removed 
	String temp = String::format("{\"temp\": %d}", random(0, 45));
    Particle.publish("temp", temp, PRIVATE);
    delay(3000);
}