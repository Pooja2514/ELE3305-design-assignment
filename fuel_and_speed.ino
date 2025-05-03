int fuelPin = A0;
int speedPin = A1;
float fuelLevel = 100.0;  
void setup() {
  Serial.begin(9600);
}

void loop() {
  int speedRaw = analogRead(speedPin);
  int speed = map(speedRaw, 0, 1023, 0, 120); 

  float fuelConsumptionRate = speed * 0.01;  
  fuelLevel -= fuelConsumptionRate;

  if (fuelLevel < 0) fuelLevel = 0;

  Serial.print("Speed: ");
  Serial.print(speed);
  Serial.print(" km/h\t");

  Serial.print("Fuel Level: ");
  Serial.print(fuelLevel, 2);
  Serial.println(" %");

  delay(1000);  
}
