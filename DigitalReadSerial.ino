const int buttonPin = 10;           
const int ledPin[3] = {7, 6, 5};     
bool lastButtonState = LOW;          
int ledIndex = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    digitalWrite(ledPin[ledIndex], LOW);
    ledIndex = (ledIndex + 1) % 3;
    digitalWrite(ledPin[ledIndex], HIGH);

    Serial.print("Button pressed. LED ");
    Serial.print(ledIndex + 1);
    Serial.println(" is now ON");
  }

  if (buttonState != lastButtonState) {
    Serial.print("Button state changed to: ");
    Serial.println(buttonState == HIGH ? "HIGH" : "LOW");
  }

  lastButtonState = buttonState;
  delay(1);        
}
