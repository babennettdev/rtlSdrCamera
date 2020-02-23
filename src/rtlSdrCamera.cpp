// main file for rtlSdrCamera

// Includes
#include <iostream>
#include <string>
#include <vector>
#include <complex>

#include <opencv2/opencv.hpp>
#include <rtl-sdr.h>
#include "rtlSdrSource.h"

#include "rtlSdrCameraConfig.h"

static rtlsdr_dev_t *dev = NULL;

int main(int argc, char* argv[])
{
	if (argc < 4){
	std::cout << argv[0] << " Version " << RTLSDRCAMERA_VERSION_MAJOR << "."
		<< RTLSDRCAMERA_VERSION_MINOR << "." << RTLSDRCAMERA_VERSION_PATCH
		<< std::endl;
	std::cout << "Usage: " << argv[0]  << "[ Device ID (default 0)] " << "[Tune frequency] " 
		<< "[Sample rate] " << std::endl;
	return 1;
	}

	// Simple OpenCV test to check if library is working... eventually move to a test directory?
	/*
	cv::Mat testImage;
	testImage = cv::imread( argv[3], 1);
	cv::namedWindow("Test Image", cv::WINDOW_AUTOSIZE );
	cv::imshow("Test Image", testImage);
	cv::waitKey(0);
	*/

	int block_size;
	block_size = 16 * 16384;

	rtlSdrSource rtl_sdr_source(atoi(argv[1]), atof(argv[2]), atof(argv[3]));
	std::vector<std::complex<double>> iq_vector (block_size);
	rtlsdr_reset_buffer(dev);
	iq_vector = rtl_sdr_source.readIqSamples(block_size);

	for (int i = 0; i < iq_vector.size(); i++){
		std::cout << iq_vector.at(i) << std::endl;
	}

	//TODO main function processing

	return 0;
}