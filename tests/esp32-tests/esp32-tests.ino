
// Ultrasound pins
#define ECHO 15 
#define TRIG 2

// Line sensor pins
#define D1 16
#define D2 17
#define D3 5
#define D4 18
#define D5 19

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

void lineSensorTest() {
  int i1 = digitalRead(D1);
  int i2 = digitalRead(D2);
  int i3 = digitalRead(D3);
  int i4 = digitalRead(D4);
  int i5 = digitalRead(D5);

  Serial.print(i1); Serial.print(' ');
  Serial.print(i2); Serial.print(' ');
  Serial.print(i3); Serial.print(' ');
  Serial.print(i4); Serial.print(' ');
  Serial.print(i5); Serial.print('\n');
}

void setup() {
  // Set up Serial Communication
  Serial.begin(9600);

  // Ultrasonic sensor
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);

  // Line sensor 
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);
}

void loop() {
  ultrasoundSensorTest();
  lineSensorTest();
}
