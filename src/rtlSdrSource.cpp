#include "rtlSdrSource.h"

/**
rtlSdrSource::rtlSdrSource():
	device_id_(0), center_frequency_(915000000), sample_rate_(500000), device_(0)
	{
		// Do nothing
	}
*/

rtlSdrSource::rtlSdrSource(int device_id = 0, double center_frequency = 915000000, double sample_rate = 500000, int frequency_correction, double tuner_bandwidth = 5000000):
	device_id_(device_id), center_frequency_(center_frequency), sample_rate_(sample_rate),
	device_(0)
	{
		int r;
		r = rtlsdr_open(&device_, device_id_);
		if( r < 0 ){
			// TODO Handle rtlsdr_open error 
			std::cout << "RTL-SDR NOT OPEN" << std::endl;
		}
		rtlsdr_set_center_freq(this->device_, this->center_frequency_);
		rtlsdr_set_sample_rate(this->device_, this->sample_rate_);
		rtlsdr_set_tuner_gain(this->device_, this->tuner_gain_;
		rtlsdr_set_freq_correction(this->device_, this->frequency_correction_);
		rtlsdr_set_tuner_bandwidth(this->device_, this->tuner_bandwidth_);

	}

rtlSdrSource::~rtlSdrSource(){
	rtlsdr_close(device_);
}

/** Getters */
int rtlSdrSource::getDeviceId(){
	return this->device_id_;
}

double rtlSdrSource::getCenterFrequency(){
	return this->center_frequency_;
}

double rtlSdrSource::getSampleRate(){
	return this->sample_rate_;
}
/*
int getTunerGain(){
	return this->tuner_gain_;
}
*/
int getFrequencyCorrection(){
	return this->frequency_correction_;
}

double getTunerBandwidth(){
	return this->tuner_bandwidth_;
}

/** Setters */
void rtlSdrSource::setDeviceId(int device_id){
	this->device_id_ = device_id;
}

void rtlSdrSource::setCenterFrequency(double center_frequency){
	this->center_frequency_ = center_frequency;
	rtlsdr_set_center_freq(this->device_, this->center_frequency_);
}

void rtlSdrSource::setSampleRate(double sample_rate){
	this->sample_rate_ = sample_rate;
	rtlsdr_set_sample_rate(this->device_, this->sample_rate_);
}
/*
void setTunerGain(int tuner_gain){
	this->tuner_gain_ = tuner_gain;
	rtlsdr_set_tuner_gain(this->device_, this->tuner_gain_);
}
*/
void setFrequencyCorrection(int frequency_correction){
	this->frequency_correction_ = frequency_correction;
	rtlsdr_set_freq_correction(this->device_, this->frequency_correction_);
}

void setTunerBandwidth(int tuner_bandwidth){
	this->tuner_bandwidth_ = tuner_bandwidth;
	rtlsdr_set_tuner_bandwidth(this->device_, this->tuner_bandwidth_);
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