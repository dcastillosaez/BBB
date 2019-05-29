/**
 *
 * PWMuniv.cpp
 * Author: Jose Simo (2017)
 * Universitat Politecnica de Valencia. AI2-DISCA
 * Creative Commons.
 *
 */

#include "PWMuniv.h"
#include "util.h"

#include <iostream>
#include <cstdlib>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

using namespace std;

namespace BBB {

string getPWMChipPath(string parent) {
	  DIR *dirp;
	  struct dirent *direntp;
	  string retval = "";
	  if ((dirp = opendir(parent.c_str())) == NULL){
		  fprintf(stderr, "Could not open %s dir_pathname: %s\nPlease, load universal overlay\nTerminate program.",
				          parent.c_str(), strerror(errno));
		  exit(0); //Terminate program.
	  }
	  while ( (direntp = readdir(dirp)) != NULL) {
		  string auxName = string(direntp->d_name);
		  if ((auxName.compare(".") != 0) && (auxName.compare("..") != 0)) {
			  retval = parent + auxName + "/";

		  }
	  }
	  closedir(dirp);
	  return(retval);
}


PWM::PWM(pinPWM pinName_p) {

	this->analogFrequency = 100000;
	this->analogMax = 3.3;

	switch (pinName_p) {
	  	case P9_22:   //EHRPWM0-A Default pin
	  		pinName = "P9.22";
	  		system_export_param = "0";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48300000.epwmss/48300200.ehrpwm/pwm/");
	  		break;
	  	case P9_31:   //EHRPWM0-A Alternative pin
	  		pinName = "P9.31";
	  		system_export_param = "0";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48300000.epwmss/48300200.ehrpwm/pwm/");
	  		break;
	  	case P9_21:   //EHRPWM0-B Default pin
	  		pinName = "P9.21";
	  		system_export_param = "1";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48300000.epwmss/48300200.ehrpwm/pwm/");
	  		break;
	  	case P9_29:   //EHRPWM0-B Alternative pin
	  		pinName = "P9.29";
	  		system_export_param = "1";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48300000.epwmss/48300200.ehrpwm/pwm/");
	  		break;
	  	case P9_42:   //ECAPPWM0 unique pin
	  		pinName = "P9.42";
	  		system_export_param = "0";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48300000.epwmss/48300100.ecap/pwm/");
	  		break;
	  	case P9_14:   //EHRPWM1-A Default pin
	  		pinName = "P9.14";
	  		system_export_param = "0";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48302000.epwmss/48302200.ehrpwm/pwm/");
	  		break;
	  	case P8_36:   //EHRPWM1-A Alternative pin
	  		pinName = "P8.36";
	  		system_export_param = "0";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48302000.epwmss/48302200.ehrpwm/pwm/");
	  		break;
	  	case P9_16:   //EHRPWM1-B Default pin
	  		pinName = "P9.16";
	  		system_export_param = "1";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48302000.epwmss/48302200.ehrpwm/pwm/");
			break;
	  	case P8_34:  //EHRPWM1-B Alternative pin
	  		pinName = "P8.34";
	  		system_export_param = "1";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48302000.epwmss/48302200.ehrpwm/pwm/");
			break;

	  	case P8_19:  //EHRPWM2-A Default pin
	  		pinName = "P8.19";
	  		system_export_param = "0";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48304000.epwmss/48304200.ehrpwm/pwm/");
			break;
		case P8_45:  //EHRPWM2-A Alternative pin
			pinName = "P8.45";
	  		system_export_param = "0";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48304000.epwmss/48304200.ehrpwm/pwm/");
			break;
		case P8_13:  //EHRPWM2-B Default pin
			pinName = "P8.13";
	  		system_export_param = "1";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48304000.epwmss/48304200.ehrpwm/pwm/");
			break;
		case P8_46:  //EHRPWM2-B Alternative pin
			pinName = "P8.46";
	  		system_export_param = "1";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48304000.epwmss/48304200.ehrpwm/pwm/");
			break;
		case P9_28:  //ECAPPWM2 unique pin
			pinName = "P9.28";
	  		system_export_param = "0";
	  		chipPath = getPWMChipPath("/sys/devices/platform/ocp/48304000.epwmss/48304100.ecap/pwm/");
			break;
	  }
	path = chipPath + "pwm" + system_export_param + "/";

	string command_pin = "/usr/bin/config-pin " + pinName + " pwm";
	string comand_export = "/bin/echo "+ system_export_param + " > " + chipPath + "export";
	cout << command_pin << endl;
	system(command_pin.c_str());
	cout << comand_export << endl;
	system(comand_export.c_str());
	usleep(100000);
	//cout << path << endl;
}

PWM::~PWM() {
	stop();
	string command_freepin = "/usr/bin/config-pin " + pinName + " gpio";
	string comand_unexport = "/bin/echo "+ system_export_param + " > " + chipPath + "unexport";
	cout << command_freepin << endl;
	system(command_freepin.c_str());
	cout << comand_unexport << endl;
	system(comand_unexport.c_str());
	usleep(100000);
}


int PWM::setPeriod(unsigned int period_ns){
	return write(this->path, PWM_PERIOD, period_ns);
}

unsigned int PWM::getPeriod(){
	return atoi(read(this->path, PWM_PERIOD).c_str());
}

float PWM::period_nsToFrequency(unsigned int period_ns){
	float period_s = (float)period_ns/1000000000;
	return 1.0f/period_s;
}

unsigned int PWM::frequencyToPeriod_ns(float frequency_hz){
	float period_s = 1.0f/frequency_hz;
	return (unsigned int)(period_s*1000000000);
}

int PWM::setFrequency(float frequency_hz){
	return this->setPeriod(this->frequencyToPeriod_ns(frequency_hz));
}

float PWM::getFrequency(){
	return this->period_nsToFrequency(this->getPeriod());
}

int PWM::setDutyCycle(unsigned int duty_ns){
	return write(this->path, PWM_DUTY, duty_ns);
}

int PWM::setDutyCycle(float percentage){
	if ((percentage>100.0f)||(percentage<0.0f)) return -1;
	unsigned int period_ns = this->getPeriod();
	float duty_ns = period_ns * (percentage/100.0f);
	this->setDutyCycle((unsigned int) duty_ns );
	return 0;
}

unsigned int PWM::getDutyCycle(){
	return atoi(read(this->path, PWM_DUTY).c_str());
}

float PWM::getDutyCyclePercent(){
	unsigned int period_ns = this->getPeriod();
	unsigned int duty_ns = this->getDutyCycle();
	return 100.0f * (float)duty_ns/(float)period_ns;
}

int PWM::setPolarity(PWM::POLARITY polarity){
	return write(this->path, PWM_POLARITY, polarity);
}

void PWM::invertPolarity(){
	if (this->getPolarity()==PWM::ACTIVE_LOW) this->setPolarity(PWM::ACTIVE_HIGH);
	else this->setPolarity(PWM::ACTIVE_LOW);
}

PWM::POLARITY PWM::getPolarity(){
	if (atoi(read(this->path, PWM_POLARITY).c_str())==0) return PWM::ACTIVE_LOW;
	else return PWM::ACTIVE_HIGH;
}

int PWM::calibrateAnalogMax(float analogMax){ //must be between 3.2 and 3.4
	if((analogMax<3.2f) || (analogMax>3.4f)) return -1;
	else this->analogMax = analogMax;
	return 0;
}

int PWM::analogWrite(float voltage){
	if ((voltage<0.0f)||(voltage>3.3f)) return -1;
	this->setFrequency(this->analogFrequency);
	this->setPolarity(PWM::ACTIVE_LOW);
	this->setDutyCycle((100.0f*voltage)/this->analogMax);
	return this->run();
}

int PWM::run(){
	return write(this->path, PWM_RUN, 1);
}

bool PWM::isRunning(){
	string running = read(this->path, PWM_RUN);
	return (running=="1");
}

int PWM::stop(){
	return write(this->path, PWM_RUN, 0);
}


} /* namespace BBB */
