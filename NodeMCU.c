#define BLYNK_TEMPLATE_ID "TMPLPdE6ipIK"
#define BLYNK_DEVICE_NAME "SMART MONITORING"
#define BLYNK_AUTH_TOKEN "vcucjjFmhOjhPG3GpVubhv_-Yd3a8OOs"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#define DHTTYPE DHT11
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE);


int flamepin=D7;

int buzzer=D8;
int LED = D4;

int SENSOR_OUTPUT_PIN = D2;

int gasleak=D6;

int relay1=D0;

int relay2=D1;

int Gas_analog = A0;

BlynkTimer timer;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Yash";
char pass[] = "shri1110";



void setup() {
  dht.begin();
  pinMode(SENSOR_OUTPUT_PIN, INPUT);

  pinMode(LED, OUTPUT);

  pinMode(flamepin,INPUT);

  pinMode(relay1,OUTPUT);

  pinMode(relay2,OUTPUT);

  pinMode(buzzer,OUTPUT);

  pinMode(Gas_analog, INPUT);

  pinMode(gasleak,OUTPUT);

  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

}


void loop() {

    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int Flame=digitalRead(flamepin);
    int gassensorAnalog = analogRead(Gas_analog);
     Blynk.virtualWrite(V5, t);
     Blynk.virtualWrite(V6, h);
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t);
    Serial.println("°C");
    Serial.println("Gas Sensor: ");
    Serial.println(gassensorAnalog);
    Blynk.virtualWrite(V0,gassensorAnalog);
  int sensorvalue = digitalRead(SENSOR_OUTPUT_PIN);
  if ((sensorvalue== HIGH)&&(Flame==1)){

    Serial.println("Human is present in the room");
    digitalWrite(LED, HIGH);
    Serial.println("Fire Not Detected");
    digitalWrite(buzzer, LOW);
    Blynk.virtualWrite(V1,1);
    digitalWrite(buzzer,LOW);
    Blynk.virtualWrite(V7,0);
    if(t>=24)
    {
      Serial.println("Temperature is more than 24.So AC is turn on");
       digitalWrite(relay1,HIGH);
       digitalWrite(relay2,LOW);
       Blynk.virtualWrite(V2,1);

    }

    if(t>=16 & t<22){
      Serial.println("Temperature is less than 22.So Fan is turn on");
       digitalWrite(relay1,LOW);
       digitalWrite(relay2,HIGH);
       Blynk.virtualWrite(V3,1);
    }
     if(t<16 && t>0){
      Serial.println("Temperature is less than 16.So Fan and AC is turned off");
       digitalWrite(relay1,LOW);
       digitalWrite(relay2,HIGH);
       Blynk.virtualWrite(V3,1);
    }
  }

    if(gassensorAnalog>600)
    {
      Blynk.logEvent("gas_leak");
      Serial.println("Gas Leak Detected");
      digitalWrite(D6,HIGH);
      Blynk.virtualWrite(V4,1);
    }
    if(gassensorAnalog<=600)
    {
      Serial.println("AC Is Working Fine");
      digitalWrite(D6,LOW);
      Blynk.virtualWrite(V4,0);
    }

  if ((sensorvalue== LOW)&&(Flame==1)) {

    Serial.println("Human is not present in the room");
    Serial.println("Fire Not Detected");
    digitalWrite(LED, LOW);
    digitalWrite(buzzer,LOW);
    Serial.println("Fan and AC is turned off");
    digitalWrite(relay1,HIGH);
    digitalWrite(relay2,HIGH);
    Blynk.virtualWrite(V2,0);
    Blynk.virtualWrite(V3,0);
    Blynk.virtualWrite(V1,0);
    Blynk.virtualWrite(V7,0);
  }
  if(Flame==0){
    Blynk.logEvent("fire");
    Serial.println("Fire Detected");
    digitalWrite(LED, LOW);
    Serial.println("Fan and AC is turned off");
    digitalWrite(relay1,HIGH);
    digitalWrite(relay2,HIGH);
    digitalWrite(buzzer,HIGH);
    Blynk.virtualWrite(V2,0);
    Blynk.virtualWrite(V3,0);
    Blynk.virtualWrite(V1,0);
    Blynk.virtualWrite(V7,1);
  }
    Blynk.run();
    timer.run();
  }