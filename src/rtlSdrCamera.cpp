// main file for rtlSdrCamera

// Includes
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
	std::cout << "Usage: " << argv[0]  << "Device ID (default 0)" << "Tune frequency " 
		<< "<Test_Image_Path>" << std::endl;
	return 1;
	}

	// Simple OpenCV test to check if library is working... eventually move to a test directory?
	cv::Mat testImage;
	testImage = cv::imread( argv[3], 1);
	cv::namedWindow("Test Image", cv::WINDOW_AUTOSIZE );
	cv::imshow("Test Image", testImage);
	cv::waitKey(0);



	//TODO main function processing

	return 0;
}