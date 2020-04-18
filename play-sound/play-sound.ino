/*
  http://www.arduino.cc/en/Tutorial/Tone
  https://www.arduino.cc/en/Tutorial/Button
*/

bool doit = false;
const int buttonPin = 2;
int buttonState = 0;
const int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(led, OUTPUT);
}


void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  
  if (buttonState == HIGH) {
    doit = true;
  }
  
  digitalWrite(led,buttonState);  
 
  // if need to repeat the melody.
  if(doit)
  {
    doit = false;
    play();    
  }
}



// notes in the melody:
int melody[] = {
  262, 196, 196, 220, 193, 0, 247, 262
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void play() {
    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
