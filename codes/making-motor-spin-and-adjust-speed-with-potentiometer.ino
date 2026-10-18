const int potPin = A0;   // Reads the 10k potentiometer knob position
const int motorPin = 3;  // Sends the speed control signal (PWM) to the transistor

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  int potValue = analogRead(potPin);              // Read knob (0 to 1023)
  
  // If the knob is turned completely off, shut the motor off completely
  if (potValue < 10) {
    analogWrite(motorPin, 0);
  } 
  // Otherwise, start the motor's power at 80 (enough to start spinning) instead of 0
  else {
    int pwmOutput = map(potValue, 10, 1023, 80, 255); 
    analogWrite(motorPin, pwmOutput);
  }
}
