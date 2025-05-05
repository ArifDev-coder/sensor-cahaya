#define Buzzer 2
#define ledBlue 3
#define ledRed 4

void setup() {
  Serial.begin(9600);
  
  pinMode(A5, INPUT);

  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}

void alertSound(int speed, int freq) {
  tone(Buzzer, freq);
  delay(speed);
  noTone(Buzzer);
}

void ledBlueBlink(int speed) {
  digitalWrite(ledBlue, HIGH);
  delay(speed);
  digitalWrite(ledBlue, LOW);
}
void ledRedBlink(int speed) {
  digitalWrite(ledRed, HIGH);
  delay(speed);
  digitalWrite(ledRed, LOW);
}

void loop() {
  int light_insensity = analogRead(A5);
  Serial.println(light_insensity);

  if (light_insensity < 25 || light_insensity > 500) {
    ledRedBlink(100);
    alertSound(300, 5000);
    ledBlueBlink(100);
  }
}
