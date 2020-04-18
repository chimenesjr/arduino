
const int analogInPin = A0;
int sensorValue = 0;
int leds[6] = {11,10,9,6,5,3};

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);

  int quant = sensorValue / 112;
  Serial.println(quant);

  for (int i = 0; i < quant; i++)
  {
    turnon(leds[i]);
  }
  
  for (int i = 6-1; i >= quant; i--)
  {
    turnoff(leds[i]);
  }
}

void turnon(int pin) {
  if (false && pin == 3) {
    Serial.print("on: ");
    Serial.print(pin);
    Serial.println();
  }
  analogWrite(pin, 20);
}

void turnoff(int pin) {
  if (false && pin == 3) {
    Serial.print("off: ");
    Serial.print(pin);
    Serial.println();
  }
  analogWrite(pin, 0);
}
