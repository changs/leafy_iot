void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(7, OUTPUT); 
    Serial.begin(9600);
    while(!Serial);    // time to get serial running
    Serial.println(F("BME280 test"));
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(7, HIGH);
    delay(3000);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(7, LOW);
    delay(3000);
}
