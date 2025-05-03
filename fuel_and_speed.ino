int fuelPin = A0;
int speedPin = A1;
float fuelLevel = 100.0;  // Start with 100% fuel

void setup() {
  Serial.begin(9600);
}

void loop() {
  int speedRaw = analogRead(speedPin);
  int speed = map(speedRaw, 0, 1023, 0, 120); // km/h

  // Simulate fuel consumption: higher speed => faster consumption
  float fuelConsumptionRate = speed * 0.01;  // 1% per 100 km/h per interval
  fuelLevel -= fuelConsumptionRate;

  // Prevent negative fuel
  if (fuelLevel < 0) fuelLevel = 0;

  Serial.print("Speed: ");
  Serial.print(speed);
  Serial.print(" km/h\t");

  Serial.print("Fuel Level: ");
  Serial.print(fuelLevel, 2);
  Serial.println(" %");

  delay(1000);  // Regular interval: 1 second
}
