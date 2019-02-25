//ultrasonic sensor
const int trigPin = 12;
const int echoPin = 13;

//motor output
const int motorPin = 9;

int dist; //cm
int motorOutput; //analog

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {
  
  dist = ping(trigPin, echoPin);
  Serial.print("dist ");

  //map function doesn't constrain values
  dist = constrain(dist, 10, 60);
  Serial.println(dist);

  //translate distance into analog output
  motorOutput = map(dist, 10, 60, 0, 255);
  
  Serial.print("motor ");
  Serial.println(motorOutput);

  //set motor output
  analogWrite(motorPin, motorOutput);
  
  delay(50);
  
}

//returns distance from ultrasonic sensor in cm
int ping(int trigPin, int echoPin) {
  
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); //send wave
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 

    //time it took for trigPin wave to come back to echoPin
    long duration = pulseIn(echoPin, HIGH); //echo pin is PWM

    //convert sensor value to cm
    int centimetres = duration / 58.2;

    return centimetres;
    
}
