#include "BQ24160.h"

BQ24160 bq24160;
unsigned long lastTime;
void setup() {
  Serial.begin(9600);
  bq24160.begin();//start bq24160
  bq24160.resetWD();//reset watch dog
  bq24160.setBatVolt(0x78);//set charge voltage to 4.1V
  bq24160.safetyTimer(TIMER_DISABLE);//diable safety timers
  lastTime=millis();
  
}

void loop() {
  //reset watch dog timer in every 5 second
  bq24160.resetWD();
  Serial.println("Start");
  bq24160.getAll();
  Serial.println("End");
  delay(5000);
  //starting a new charging cycle after every 5 min
  if(millis()-lastTime>=300000){
    bq24160.rechargeEvent();
    Serial.println("-----------------------Charge loop");
    lastTime=millis();
  }
}
