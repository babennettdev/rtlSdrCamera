#include "rtlSdrSource.h"

rtlSdrSource::rtlSdrSource():
	device_id_(0), frequency_(915000000), sample_rate_(500000)
	{
		// Do nothing
	}

rtlSdrSource::rtlSdrSource(int device_id, double center_frequency_, double sample_rate):
	device_id_(device_id), center_frequency_(center_frequency), sample_rate_(sample_rate)
	{
		// Do nothing
	}

rtlSdrSource::~rtlSdrSource(){
	rtlsdr_close(device_id_);
}


int rtlSdrSource::getDeviceId(){
	return this.device_id_;
}

double rtlSdrSource::getCenterFrequency(){
	return this.center_frequency_;
}

double rtlSdrSource::getSampleRate(){
	return this.sample_rate_;
}

void rtlSdrSource::setDeviceId(int device_id){
	this.device_id_ = device_id;
}

void rtlSdrSource::setCenterFrequency(double center_frequency){
	this.center_frequency_ = center_frequency;
}

void rtlSdrSource::setSampleRate(double sample_rate){
	this.sample_rate_ = sample_rate;
}