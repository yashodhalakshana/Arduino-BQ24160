we
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>
#include "BQ24160.h"

void BQ24160::begin(){
  Wire.begin();
  Wire.setClock(SPEED); 
  Wire.beginTransmission(BQ24160_ADDRESS);
  Wire.write(BQ24160_STATUS);  // set register for read start register
  Wire.endTransmission(false); // false to not release the line

  Wire.requestFrom(BQ24160_ADDRESS, LENGTH); // request bytes from register XY
  byte buff[LENGTH];
  Wire.readBytes(buff, LENGTH);
  for (int i = 0; i < LENGTH; i++) {
    Serial.println(buff[i], BIN);
  }
}
void BQ24160::resetWD(){
	Wire.beginTransmission(BQ24160_ADDRESS);
  	Wire.write(BQ24160_STATUS); 
	Wire.write(0x80);//reset
	Wire.endTransmission();
}

void BQ24160::setBatVolt(byte reg){
	Wire.beginTransmission(BQ24160_ADDRESS);
  	Wire.write(BQ24160_BATTERY); 
	Wire.write(reg);//reset
	Wire.endTransmission();
}
void BQ24160::setReg(byte addr, byte val){
	Wire.beginTransmission(BQ24160_ADDRESS);
  	Wire.write(addr); 
	Wire.write(val);//reset
	Wire.endTransmission();
}

void BQ24160::getAll(){
  Wire.requestFrom(BQ24160_ADDRESS, LENGTH); // request bytes from register XY
  byte buff[LENGTH];
  Wire.readBytes(buff, LENGTH);
  for (int i = 0; i < LENGTH; i++) {
    Serial.println(buff[i], BIN);
  }
}

void BQ24160::safetyTimer(Timers time){
	switch(time){
		case 0:
		BQ24160::setReg(BQ24160_SAF_NTC,0x18);
		break;
		case 1:
		BQ24160::setReg(BQ24160_SAF_NTC,0x38);
		break;
		case 2:
		BQ24160::setReg(BQ24160_SAF_NTC,0x58);
		break;
		case 3:
		BQ24160::setReg(BQ24160_SAF_NTC,0x78);
		break;
	}
}

void BQ24160::rechargeEvent(){
	BQ24160::setReg(BQ24160_CONTROL,0x0E);
	delay(100);
	BQ24160::setReg(BQ24160_CONTROL,0x0C);
}
void BQ24160::resetAll(){
	BQ24160::setReg(BQ24160_CONTROL,0x8C);
}