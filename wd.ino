const int relayPin = A5;  // Pino do relay acionado via transistor
const int ledPin = LED_BUILTIN;  // LED indicador
const unsigned long keepAliveTimeout = 5000; 

unsigned long lastKeepAlive = 0;

void setup() {
    pinMode(relayPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
    digitalWrite(relayPin, LOW);
    Serial.begin(9600);
    digitalWrite(ledPin, HIGH);}

void loop() {
    if (Serial.available()) {
        char c = Serial.read();
        if (c == 'K') {
            lastKeepAlive = millis();
            digitalWrite(ledPin, LOW);
        }
    }

    if (millis() - lastKeepAlive > keepAliveTimeout) {
        for (int i = 0; i < 6; i++) {
          digitalWrite(ledPin, LOW);
          delay(50);
          digitalWrite(ledPin, HIGH);
          delay(100);
        }

        digitalWrite(relayPin, HIGH);
        delay(500); 
        digitalWrite(relayPin, LOW);
        delay(180000); 
        lastKeepAlive = millis();
    }
}
