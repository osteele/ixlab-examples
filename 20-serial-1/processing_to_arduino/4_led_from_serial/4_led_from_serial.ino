// IMA NYU Shanghai
// Interaction Lab
// This code receives one value from Processing to Arduino


char valueFromProcessing;
int ledPin = 13;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


void loop() {
  // to receive a value from Processing
  while (Serial.available()) {
    valueFromProcessing = Serial.read();
  }

  if (valueFromProcessing == 'H') {
    digitalWrite(ledPin, HIGH);
  } else if (valueFromProcessing == 'L') {
    digitalWrite(ledPin, LOW);
  } else {
    // something else
  }


  // too fast communication might cause some latency in Processing
  // this delay resolves the issue.
  delay(10);
}
