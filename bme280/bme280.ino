
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 13 // SCL
#define BME_MISO 12 // SDO
#define BME_MOSI 11 // SDA
#define BME_CS 10 // CSB

#define SEALEVELPRESSURE_HPA (1013.25)

//Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

unsigned long delayTime;

void setup() {
    Serial.begin(9600);
    while(!Serial);    // time to get serial running
    Serial.println(F("BME280 test"));

    unsigned status;
    
    status = bme.begin();  
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        while (1) delay(10);
    }
    
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(7, OUTPUT); 
    Serial.println("-- Default Test --");
    delayTime = 3000;

    Serial.println();
}


void loop() { 
    printValues();
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(7, HIGH);
    Serial.println("-- HIGH");
    delay(3000);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(7, LOW);
    Serial.println("-- LOW");
    delay(delayTime);
}


void printValues() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" °C");

    Serial.print("Pressure = ");

    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
}
