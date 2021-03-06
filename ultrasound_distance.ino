int trigger =4; //giving output for transmitting the ultrasound waves
int echo=3; //taking input from the pin that how later it received the waves back
long duration; // duration from transmitting till receiving
float distance; // distance between sensor and surface
void setup() {
  //start serial connection
  Serial.begin(9600);
  //configure pins for input and output
  pinMode(trigger, OUTPUT);
  pinMode(echo,INPUT);

  // setting trigger to LOW, for not transmitting any waves
  digitalWrite(trigger,LOW);

}

void loop() {
  delay(1000);

  //setting trigger to HIGH for transmitting waves for 10 microsecond by using 10 microsecond delay
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);

  //stopping transmission
  digitalWrite(trigger,LOW);

  //taking duration in microseconds for which the echo was HIGH
  duration = pulseIn(echo,HIGH);

  // distance= velocity of sound*time(or duration)/2
  distance=1.0*333*duration*(1e-6)/2;
  
  //printing Duration and Distance
  Serial.print("Duration:");
  Serial.println(duration);
  Serial.print("Distance:");
  Serial.println(distance);
}
