//define the pins for ultrasonic sensor here
#define trigPin 12
#define echoPin 13
#define spkrPin 8

const int HOLD_MS = 200;

//setup trig is output and echo is input for the sound. Read serial fastest possible speed
void setup() {
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

//below methods for beep speed
void beepFastest(){
  // play a note on pin 8 for 200 ms:
  tone(spkrPin, 440, HOLD_MS);
  beepNo(50, 100);
}

void beepFast(){
  // play a note on pin 8 for 200 ms:
  tone(spkrPin, 440, HOLD_MS);
  beepNo(50, 300);
}

void beepMedium(){
  tone(spkrPin, 440, HOLD_MS);
  beepNo(200, 300);
}

void beepSlow(){
  tone(spkrPin, 440, HOLD_MS);
  beepNo(500, 300);
}

void searchBeep() {
  delay(2775); 
  tone(spkrPin, 220, HOLD_MS);
  delay(105);
  tone(spkrPin, 880, HOLD_MS);
  delay(95);
  tone(spkrPin, 1760, HOLD_MS);
  delay(75);
  tone(spkrPin, 3520, HOLD_MS);
  beepNo(300, 300);
}

void hesDeadJim() {
  tone(spkrPin, 440, HOLD_MS);
  delay(50);
  tone(spkrPin, 659, HOLD_MS);
  beepNo(50, 0);
}

//no beep here
void beepNo(int x, int y){
  delay(x);
  noTone(spkrPin);
  delay(y);
}

//send a pulse and calculate how long it took to travel
void loop() { 
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  Serial.print(distance);
  Serial.println(" cm");

  //then check the distance and beep if it is in the range
  if (distance <=5) {
    hesDeadJim();
  }
  else if (distance >=5 && distance <=15){
    beepFastest();
  }
  else if (distance >15 && distance <=30){
    beepFast();
  }
  else if (distance >=31 && distance <=60) {
    beepMedium();
  }
  else if (distance >=61 && distance <= 90){
    beepSlow();
  }
  else {
    searchBeep();
  }

} 


