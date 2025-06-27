// Communication pins
#define RP1 18
#define RP2 19
#define RP3 21
#define RP4 3

// Motor pins
#define ENA 15
#define IN1 2
#define IN2 4
#define IN3 16
#define IN4 17
#define ENB 5

// Ultrasound pins
#define ECHO 33 
#define TRIG 25

// Line sensor pins
#define D1 13
#define D2 12
#define D3 14
#define D4 27
#define D5 26

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

