#define TRIG0 5
#define ECHO0 6
#define TRIG1 7
#define ECHO1 8
#define TRIG2 9
#define ECHO2 10
#define TRIG3 11
#define ECHO3 12

long readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2; 
  return distance;
}

void setup() {
  Serial.begin(9600);

  pinMode(TRIG0, OUTPUT); pinMode(ECHO0, INPUT);
  pinMode(TRIG1, OUTPUT); pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT); pinMode(ECHO2, INPUT);
  pinMode(TRIG3, OUTPUT); pinMode(ECHO3, INPUT);
}

void loop() {
  long d0 = readDistance(TRIG0, ECHO0);
  delay(100);
  long d1 = readDistance(TRIG1, ECHO1);
  delay(100);
  long d2 = readDistance(TRIG2, ECHO2);
  delay(100);
  long d3 = readDistance(TRIG3, ECHO3);

  long minDist = min(min(d0, d1), min(d2, d3));

  Serial.print("D:");
  Serial.println(minDist);

  delay(1000);
}
