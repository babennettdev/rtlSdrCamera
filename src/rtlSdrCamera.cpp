// main file for rtlSdrCamera

//includes
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
//#include "../build/rtlSdrCameraConfig.h"
#include "rtlSdrCameraConfig.h"

int main(int argc, char* argv[])
{
	if (argc < 3){
	std::cout << argv[0] << " Version " << RTLSDRCAMERA_VERSION_MAJOR << "."
		<< RTLSDRCAMERA_VERSION_MINOR << "." << RTLSDRCAMERA_VERSION_PATCH
		<< std::endl;
	std::cout << "Usage: " << argv[0] << "Tune frequency " << "<Test_Image_Path>" << std::endl;
	return 1;
	}

	cv::Mat testImage;
	testImage = cv::imread( argv[2], 1);
	cv::namedWindow("Test Image", cv::WINDOW_AUTOSIZE );
	cv::imshow("Test Image", testImage);
	cv::waitKey(0);
	//TODO main function processing

	return 0;
}