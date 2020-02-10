/** 
* Test file to test the functionality of the rtl-sdr dongle 
*
*/

// Includes
#include <iostream>
#include <string>
#include "rtlSdrSource.h"

static rtlsdr_dev_t *dev = NULL;

int main(int argc, char* argv[])
{
	std::cout << argv[0] << " Version " << RTLSDRCAMERA_VERSION_MAJOR << "."
		<< RTLSDRCAMERA_VERSION_MINOR << "." << RTLSDRCAMERA_VERSION_PATCH
		<< std::endl;
	if (argc < 4){
		std::cout << "Usage: " << argv[0]  << " [Device ID]" << " [Tune frequency]" 
			<<  " [Sample rate]" << std::endl;
		
		rtlSdrSource rtl_sdr_source = new rtlSdrSource();
		string str_device_id = to_string(rtl_sdr_source.getDeviceId());
		string str_center_frequency = to_string(rtl_sdr_source.getCenterFrequency());
		string str_sample_rate = to_string(rtl_sdr_source.getSampleRate());

		std::cout << "Setting defaults: " << argv[0] << " " << str_device_id << " " 
			<< str_center_frequency << " " << str_sample_rate << std::endl;
	}
	else{
		int device_id = atoi(argv[2]);
		double center_frequency = atof(argv[3]);
		double sample_rate = atof(argv[4]);
		
		rtlSdrSource rtl_sdr_source = new rtlSdrSource(device_id, center_frequency, sample_rate);
		string str_device_id = to_string(rtl_sdr_source.getDeviceId());
		string str_center_frequency = to_string(rtl_sdr_source.getCenterFrequency());
		string str_sample_rate = to_string(rtl_sdr_source.getSampleRate());

		std::cout << "Setting defaults: " << argv[0] << " " << str_device_id << " " 
			<< str_center_frequency << " " << str_sample_rate << std::endl;
	}

	// Simple rtl-sdr test to check if library is working... eventually move to a test directory?
	int r;
	int dev_index;
	//static rtlsdr_dev_t *dev = NULL;

	dev_index = atoi(argv[1]);
	if (dev_index < 0 ){
		exit(1);
	}


	r = rtlsdr_open(&dev, (uint32_t)dev_index);
	if ( r < 0 ){
		std::cout << "Failed to open rtlsdr " << dev_index << std::endl;
	}
	
	std::cout << "RTLSDR IS OPEN!" << std::endl;

	rtlsdr_close(dev);
	std::cout << "RTLSDR IS CLOSED!" << std::endl;

	//TODO main function processing

	return 0;
}