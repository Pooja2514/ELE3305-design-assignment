#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);  // Common I2C address: 0x27
int buzzer = 8;
int distance;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("Waiting for data");
}

void loop() {
  if (Serial.available()) {
    distance = Serial.parseInt();  // Read from RS232 (Serial Monitor)

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print("cm");

    if (distance < 20) {
      lcd.setCursor(0, 1);
      lcd.print("WARNING: OBSTACLE");

      int delayTime = map(distance, 0, 20, 50, 300);  // dynamic beep rate
      tone(buzzer, 1000);  // 1kHz warning tone
      delay(delayTime);
      noTone(buzzer);
      delay(delayTime);
    } else {
      lcd.setCursor(0, 1);
      lcd.print("Safe Distance     ");
      noTone(buzzer);
    }
  }
}
