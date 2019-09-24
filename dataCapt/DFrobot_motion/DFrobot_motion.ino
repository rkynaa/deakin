#include <RTClib.h>


RTC_PCF8523 rtc;

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

int soundPin = A0;
int sensorValue = 0;

void setup() {

  while (!Serial) {
    delay(1);  // for Leonardo/Micro/Zero
  }

  Serial.begin(57600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.initialized()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead (soundPin);
  String actin;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.print(" -> ");
  if (digitalRead(6) == HIGH) {
    actin = "Active";
  }else {
    actin = "Inactive";
  }
  // put your main code here, to run repeatedly:
  if (digitalRead(6) == HIGH && distance <= 50 && sensorValue >=  38) {
    digitalWrite(7, LOW);
    digitalWrite(5, HIGH);
    Serial.println("Active");
  }
  else {
    digitalWrite(5, LOW);
    digitalWrite(7, HIGH);
    Serial.println("Inactive");
  }
  Serial.print("Motion? ");
  Serial.println(actin);
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("Sound: ");
  Serial.println (sensorValue, DEC);
  delay(500);
}
