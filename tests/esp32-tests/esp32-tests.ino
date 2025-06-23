
// Ultrasound pins
#define ECHO 15 
#define TRIG 2

void ultrasoundSensorTest() {
  // Set pin to low
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  // Set pin to high
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(2);

  // Set pin to low
  digitalWrite(TRIG, LOW);

  // Read data
  float duration = pulseIn(ECHO, HIGH);
  float distance = (duration * .0343) / 2;

  // Skip trash output from sensor
  if (distance == 0) return;

  // Print out data
  Serial.print("Distance:" );
  Serial.print(distance);
  Serial.println();
}

void setup() {
  // Set up Serial Communication
  Serial.begin(9600);

  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

void loop() {
  ultrasoundSensorTest();
}
