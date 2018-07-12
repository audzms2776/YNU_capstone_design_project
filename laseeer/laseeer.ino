unsigned long distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT);

  digitalWrite(4, LOW);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = pulseIn(2, HIGH);
  distance = distance / 10;

  Serial.println(distance);
}
