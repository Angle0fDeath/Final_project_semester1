#include "pitches.h"
#define STEP_PIN 2
#define DIR_PIN 3
#define laserPin 7
#define inPin 12
#define sensorPin A0
#define LS 10
#define RS 11
int sensorValue = 0; // Variable to store the value coming from the sensor
int val = 0;     // Variable for reading the button status
int sP = 1; // Position

int melody[] = {
  NOTE_D1, NOTE_A2, NOTE_FS3, NOTE_A3, NOTE_C4, NOTE_DS4, NOTE_FS4, NOTE_AS4
};
// Notes
bool dirHigh;

void setup()
{
  dirHigh = true;
  digitalWrite(DIR_PIN, HIGH);
  digitalWrite(STEP_PIN, LOW);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(laserPin, OUTPUT);
  pinMode(inPin, INPUT);
  pinMode(LS, OUTPUT);
  pinMode(RS, OUTPUT);
  Serial.begin(9600);
  while (val != HIGH)
    val = digitalRead(inPin);
}

void loop()
{
  // Toggle the DIR pin to change direction.
  val = digitalRead(inPin);
  Serial.println(val);
  if (val == HIGH && dirHigh == true)
    delay(5000);
  else
  {
    if (dirHigh)
    {
      dirHigh = false;
      digitalWrite(DIR_PIN, LOW);
    }
    else
    {
      dirHigh = true;
      digitalWrite(DIR_PIN, HIGH);
    }
    for (int i = 0; i < 7; i++)
    {
      Serial.print("     pozitie  ");
      Serial.println(sP);
      sensorValue = analogRead(sensorPin); // read the value from the sensor
      Serial.println(sensorValue); //prints the values coming from the sensor on the screen
      if (sensorValue > 150) // Check if above threshold and play notes if needed
      { 
        tone(RS, melody[sP - 1], 50);
        tone(LS, melody[sP - 1], 50);
        delay(65);
        noTone(RS);
        noTone(LS);
      }
      else
        delay(65);
      if (dirHigh == true) //Changing the position accordingly
        sP--;
      else
        sP++;
      digitalWrite(laserPin, LOW); //Stops laser
      digitalWrite(STEP_PIN, HIGH); // Moves stepper
      delayMicroseconds(500);
      digitalWrite(STEP_PIN, LOW);
      delayMicroseconds(500);
      digitalWrite(STEP_PIN, HIGH);
      delayMicroseconds(500);
      digitalWrite(STEP_PIN, LOW);
      digitalWrite(laserPin, HIGH); // Starts laser
      delayMicroseconds(500);
    }
    Serial.print("     pozitie  ");
    Serial.println(sP);
    sensorValue = analogRead(sensorPin); // read the value from the sensor
    Serial.println(sensorValue); //prints the values coming from the sensor on the screen
    if (sensorValue > 150)
    { tone(RS, melody[sP - 1], 50);
      tone(LS, melody[sP - 1], 50);
      delay(65);
      noTone(RS);
      noTone(LS);
    }
  }
}
