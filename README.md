# BQ24160_Arduino
Arduino Library for BQ24160

BQ24160 is a 2.5A, Dual-Input, Single-Cell Switched-Mode Li-Ion Battery Charger with Power Path Management and I2C Interface

This library contain several function for BQ24160

  void begin(void);//begin BQ24160
  
	void resetWD(void);//reset watch dog timer
  
	void setBatVolt(byte reg);//Set battery charge voltage, refer datasheet
  
	void setReg(byte addr, byte val);//Set value for any register
  
	void getAll(void);//print all current settings
  
	void safetyTimer(Timers time);//safety timer option
  
	void rechargeEvent(void);//call when need to initiate a new charging cycle
  
	void resetAll(void);//reset all settings to default
