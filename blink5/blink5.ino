const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);


  turnon(9);
  delay(5*100);
  turnoff(9);
  delay(5*100);

}

void turnon(int pin) {
  analogWrite(pin, 255);
}

void turnoff(int pin) {
  analogWrite(pin, 0);
}
