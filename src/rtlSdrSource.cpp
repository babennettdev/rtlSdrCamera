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
		int r;
		r = rtlsdr_open(&device_, device_id_);
		if( r < 0 ){
			// TODO Handle rtlsdr_open error 
			std::cout << "RTL-SDR NOT OPEN" << std::endl;
		}
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

std::vector<std::complex<double>> rtlSdrSource::readIqSamples(int iq_block_length){
	std::vector<uint8_t> sample_block_vector (2 * iq_block_length); //we want 2 * block length to satisfy Nyquist
	std::vector<std::complex<double>> iq_sample_block_vector (iq_block_length); //IQ samples only require iq_block_length because they contain I and Q components
	int r, n_read, iq_sample_block_length;
	bool good_iq_sample_block = false;


	while( !good_iq_sample_block){
		r = rtlsdr_read_sync(this->device_, sample_block_vector.data(), (2 * iq_block_length), &n_read);
		if( r == -1 ){
			std::cout<< "Could not find device" << std::endl;
		}
		else if( r < 0){
			std::cout << "rtlsdr_read_sync fail" << std::endl;
		}
		else if( n_read != (2 * iq_block_length)){
			std::cout << "IQ block too small; bad read" << std::endl;
		}
		else{
			good_iq_sample_block = true;
		}
	}

	for(int i = 0; i < iq_block_length; i++){
		int32_t real_value = sample_block_vector[2 * i];
		int32_t imaginary_value = sample_block_vector[2 * i + 1];
		real_value = ( (real_value - 128) / 128);
		imaginary_value = ( (imaginary_value - 128) / 128);
		std::complex<double> temp_iq_sample(real_value, imaginary_value);
		iq_sample_block_vector[i] = temp_iq_sample;
	}

	return iq_sample_block_vector;
}