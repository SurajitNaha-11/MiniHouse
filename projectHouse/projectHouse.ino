const int LDR_PIN = A0;
const int NTC_PIN = A1;
const int ROOM_LIGHT_PIN = 2;
//------------------------
const int US_OPIN = 3;
const int US_IPIN = 4;
const int ALARM_LED = 6;
const int BUZZER = 5;
//------------------------
void setup() { 
  pinMode(ROOM_LIGHT_PIN, OUTPUT);
  pinMode(NTC_PIN, INPUT);
  //------------------------
  pinMode(US_OPIN, OUTPUT);
  pinMode(US_IPIN, INPUT);
  pinMode(ALARM_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrControl();
  securityControl();
  temperatureControl();
}

void ldrControl() {
  int value = analogRead(LDR_PIN);

  if (value > 500) {
    digitalWrite(ROOM_LIGHT_PIN, HIGH);
  } else {
    digitalWrite(ROOM_LIGHT_PIN, LOW);
  }
}

void securityControl() {
  digitalWrite(US_OPIN, LOW);
  delayMicroseconds(5);
  digitalWrite(US_OPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_OPIN, LOW);

  float t = pulseIn(US_IPIN, HIGH);
  float d = t * 0.034;
  d = d / 2;

  Serial.print("Distance: ");
  Serial.println(d);

  if (d < 20) {
    digitalWrite(ALARM_LED, HIGH);
    //    tone(BUZZER, 800);
  } else {
    digitalWrite(ALARM_LED, LOW);
    noTone(BUZZER);
  }
}

void temperatureControl() {
  int tempValue = analogRead(NTC_PIN);
  Serial.print("Temperature: ");
  Serial.println(tempValue);
  // Simple threshold for warning; adjust based on sensor values
  if (tempValue > 600) {
    digitalWrite(ALARM_LED, HIGH);
    tone(BUZZER, 800);
  } else {
    digitalWrite(ALARM_LED, LOW);
    noTone(BUZZER);
  }
}