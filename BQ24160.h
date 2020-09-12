
#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>

#define BQ24160_ADDRESS	(0x6B)
#define BQ24160_STATUS	(0x00)
#define BQ24160_SUPPLY	(0x01)
#define BQ24160_CONTROL	(0x02)
#define BQ24160_BATTERY	(0x03)
#define BQ24160_PART	(0x04)
#define BQ24160_CHARGE	(0x05)
#define BQ24160_DPPM	(0x06)
#define BQ24160_SAF_NTC	(0x07)

#define SPEED 			100000
#define LENGTH			8

enum Timers{
	TIMER_27MIN,
	TIMER_6HR,
	TIMER_9HR,
	TIMER_DISABLE
};

class BQ24160{
public:
	void begin(void);//begin BQ24160
	void resetWD(void);//reset watch dog timer
	void setBatVolt(byte reg);//Set battery charge voltage, refer datasheet
	void setReg(byte addr, byte val);//Set value for any register
	void getAll(void);//print all current settings
	void safetyTimer(Timers time);//safety timer option
	void rechargeEvent(void);//call when need to initiate a new charging cycle
	void resetAll(void);//reset all settings to default
};