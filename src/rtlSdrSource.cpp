#include "rtlSdrSource.h"
#include <stdlib.h>
/**
rtlSdrSource::rtlSdrSource():
	device_id_(0), center_frequency_(915000000), sample_rate_(500000), device_(0)
	{
		// Do nothing
	}
*/

rtlSdrSource::rtlSdrSource(int device_id = 0, double center_frequency = 915000000, double sample_rate = 2560000):
	device_id_(device_id), center_frequency_(center_frequency), sample_rate_(sample_rate),
	tuner_gain_mode_(0), tuner_gain_(0),frequency_correction_(0), tuner_bandwidth_(sample_rate/2),
	automatic_gain_control_mode_(0), direct_sampling_mode_(0), device_(0)
	{
		int r;
		r = rtlsdr_open(&device_, device_id_);
		if( r != 0 ){
			std::cout << "RTL-SDR NOT OPEN" << std::endl;
			throw badRtlSdrApiCall();
		}

		r = rtlsdr_set_center_freq(this->device_, this->center_frequency_);
		if(r != 0){
			std::cout << "Error in rtlsdr_set_center_freq" << std::endl;
			throw badRtlSdrApiCall();
		}

		r = rtlsdr_set_sample_rate(this->device_, this->sample_rate_);
		if(r != 0){
			std::cout << "Error in rtlsdr_set_sample_rate" << std::endl;
			throw badRtlSdrApiCall();
		}

		r = rtlsdr_set_tuner_gain_mode(this->device_, this->tuner_gain_mode_);
		if(r != 0){
			std::cout << "Error in rtlsdr_set_tuner_gain_mode" << std::endl;
			throw badRtlSdrApiCall();
		}

		//r = rtlsdr_set_freq_correction(this->device_, this->frequency_correction_);
		if(r != 0){
			std::cout << "Error in rtlsdr_set_freq_correction" << std::endl;
			//throw badRtlSdrApiCall();
		}

		r = rtlsdr_set_tuner_bandwidth(this->device_, this->tuner_bandwidth_);
		if(r != 0){
			std::cout << "Error in rtlsdr_set_tuner_bandwidth" << std::endl;
			throw badRtlSdrApiCall();
		}

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

int rtlSdrSource::getTunerGainMode(){
	return this->tuner_gain_mode_;
}

int rtlSdrSource::getTunerGain(){
	return this->tuner_gain_;
}

int rtlSdrSource::getFrequencyCorrection(){
	return this->frequency_correction_;
}

double rtlSdrSource::getTunerBandwidth(){
	return this->tuner_bandwidth_;
}

int rtlSdrSource::getAutomaticGainControlMode(){
	return this->automatic_gain_control_mode_;
}

int rtlSdrSource::getDirectSampling(){
	return this->automatic_gain_control_mode_;
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
	int r;
	r = rtlsdr_set_sample_rate(this->device_, this->sample_rate_);
	if(r != 0){
		std::cout << "Error in rtlsdr_set_center_freq" << std::endl;
		throw badRtlSdrApiCall();
	}
}

void rtlSdrSource::setTunerGainMode(int tuner_gain_mode){
	this->tuner_gain_mode_ = tuner_gain_mode;
	int r;
	r = rtlsdr_set_tuner_gain(this->device_, this->tuner_gain_mode_);
	if(r != 0){
		std::cout << "Error in rtlsdr_set_tuner_gain" << std::endl;
		throw badRtlSdrApiCall();
	}
}

void rtlSdrSource::setTunerGain(int tuner_gain){
	this->tuner_gain_ = tuner_gain;
	if (this->tuner_gain_mode_ == 1){
		int r;
		r = rtlsdr_set_tuner_gain(this->device_, this->tuner_gain_);
		if(r != 0){
			std::cout << "Error in rtlsdr_set_tuner_gain" << std::endl;
			throw badRtlSdrApiCall();
		}
	}
}

void rtlSdrSource::setFrequencyCorrection(int frequency_correction){
	this->frequency_correction_ = frequency_correction;
	int r;
	r = rtlsdr_set_freq_correction(this->device_, this->frequency_correction_);
	if(r != 0){
		std::cout << "Error in rtlsdr_set_freq_correction" << std::endl;
		throw badRtlSdrApiCall();
	}
}

void rtlSdrSource::setTunerBandwidth(double tuner_bandwidth){
	this->tuner_bandwidth_ = tuner_bandwidth;
	int r;
	r = rtlsdr_set_tuner_bandwidth(this->device_, this->tuner_bandwidth_);
	if(r != 0){
		std::cout << "Error in rtlsdr_set_tuner_bandwidth" << std::endl;
		throw badRtlSdrApiCall();
	}
}

void rtlSdrSource::setAutomaticGainControlMode(int automatic_gain_control_mode){
	this->automatic_gain_control_mode_ = automatic_gain_control_mode_;
	int r;
	r = rtlsdr_set_agc_mode(this->device_, this->automatic_gain_control_mode_);
	if(r != 0){
		std::cout << "Error in rtlsdr_set_agc_mode" << std::endl;
		throw badRtlSdrApiCall();
	}
}

void rtlSdrSource::setDirectSampling(int direct_sampling_mode){
	this->direct_sampling_mode_ = direct_sampling_mode;
	int r;
	r = rtlsdr_set_direct_sampling(this->device_, this->direct_sampling_mode_);
	if(r != 0){
		std::cout << "Error in rtlsdr_set_direct_sampling" << std::endl;
		throw badRtlSdrApiCall();
	}
}

std::vector<std::complex<double>> rtlSdrSource::readIqSamples(int iq_block_length){
	std::vector<uint8_t> sample_block_vector (2 * iq_block_length); //we want 2 * block length to satisfy Nyquist
	std::vector<std::complex<double>> iq_sample_block_vector (iq_block_length); //IQ samples only require iq_block_length because they contain I and Q components
	
	int r, n_read, iq_sample_block_length;
	bool good_iq_sample_block = false;

	uint8_t *buffer;
	buffer = (uint8_t*) malloc((16 * 16384) * sizeof(uint8_t));

	while( !good_iq_sample_block){
		//r = rtlsdr_read_sync(this->device_, sample_block_vector.data(), (2 * iq_block_length), &n_read);
		r = rtlsdr_read_sync(this->device_, buffer, (2 * iq_block_length), &n_read);
		if( r == -1 ){
			std::cout<< "Could not find device" << std::endl;
			throw badRtlSdrApiCall();
		}
		else if( r < 0){
			std::cout << "rtlsdr_read_sync fail" << std::endl;
			throw badRtlSdrApiCall();
		}
		else if( n_read != (2 * iq_block_length)){
			std::cout << "IQ block too small; bad read" << std::endl;
			throw badRtlSdrApiCall();
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