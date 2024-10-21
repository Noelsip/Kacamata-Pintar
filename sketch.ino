const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 5;

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.println("Kacamata Pintar Start");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  // Serial.print("Duration: ");
  // Serial.println(duration);


  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance  <= 100 && distance > 0){
    tone(buzzerPin, 1000);
  }else{
    noTone(buzzerPin);
  }
  
  delay(200);

}
