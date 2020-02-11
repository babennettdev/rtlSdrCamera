#include "rtlSdrSource.h"

/**
rtlSdrSource::rtlSdrSource():
	device_id_(0), center_frequency_(915000000), sample_rate_(500000), device_(0)
	{
		// Do nothing
	}
*/

rtlSdrSource::rtlSdrSource(int device_id = 0, double center_frequency = 915000000, double sample_rate = 500000):
	device_id_(device_id), center_frequency_(center_frequency), sample_rate_(sample_rate),
	device_(0)
	{
		// Do nothing
	}

rtlSdrSource::~rtlSdrSource(){
	rtlsdr_close(device_);
}


int rtlSdrSource::getDeviceId(){
	return this->device_id_;
}

double rtlSdrSource::getCenterFrequency(){
	return this->center_frequency_;
}

double rtlSdrSource::getSampleRate(){
	return this->sample_rate_;
}

/** This getter does not work... I'm not sure if it's necessary anyway
*rtlsdr_dev_t getDeviceObject(){
	return this->device_;
}
*/

void rtlSdrSource::setDeviceId(int device_id){
	this->device_id_ = device_id;
}

void rtlSdrSource::setCenterFrequency(double center_frequency){
	this->center_frequency_ = center_frequency;
}

void rtlSdrSource::setSampleRate(double sample_rate){
	this->sample_rate_ = sample_rate;
}