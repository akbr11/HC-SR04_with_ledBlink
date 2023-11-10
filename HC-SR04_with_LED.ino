#define ledLamp 8
#define trigPin 3
#define echoPin 2

long durasi;
int jarak;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(ledLamp, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durasi = pulseIn(echoPin, HIGH);
  jarak = durasi * 0.034 / 2;

  // delay(500);
  if (jarak <= 20) {
    Serial.println("Bahaya Mendekat ...");
    digitalWrite(ledLamp, HIGH);
    delay(500);
    digitalWrite(ledLamp, LOW);
    delay(500);
  } else {
    Serial.println("Aman ...");
    delay(500);
  }
}
