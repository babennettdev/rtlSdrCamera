// main file for rtlSdrCamera

//includes
#include <iostream>
#include <string>
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
	std::cout << "Usage: " << argv[0]  << "Device ID (default 0)" << "Tune frequency " << "<Test_Image_Path>" << std::endl;
	return 1;
	}

	// Simple OpenCV test to check if library is working... eventually move to a test directory?
	cv::Mat testImage;
	testImage = cv::imread( argv[3], 1);
	cv::namedWindow("Test Image", cv::WINDOW_AUTOSIZE );
	cv::imshow("Test Image", testImage);
	cv::waitKey(0);

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

	//TODO main function processing

	return 0;
}