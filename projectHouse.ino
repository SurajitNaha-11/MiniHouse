const int LDR_PIN = A0;
const int ROOM_LIGHT_PIN = 2;
//------------------------
const int IR_PIN =3;
const int ALARM_LED =4;
const int BUZZER =5;
//------------------------
void setup() {
  pinMode(ROOM_LIGHT_PIN, OUTPUT);
//------------------------
  pinMode(IR_PIN, INPUT);
  pinMode(ALARM_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  ldrControl();
  securityControl();
  
}

void ldrControl() {
  int value = analogRead(LDR_PIN);
  Serial.println(value);
  if (value > 500) {
    digitalWrite(ROOM_LIGHT_PIN, HIGH);
  } else {
    digitalWrite(ROOM_LIGHT_PIN, LOW);
  }
  delay(1000);
}
void securityControl() {
  int irState = digitalRead(IR_PIN);

  if (irState == LOW) {
    digitalWrite(ALARM_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  }
  else {
    digitalWrite(ALARM_LED, LOW);
    digitalWrite(BUZZER, LOW);
  }
  delay(500);
}