// main file for rtlSdrCamera

//includes
#include <iostream>
#include <string>
//#include "../build/rtlSdrCameraConfig.h"
#include "rtlSdrCameraConfig.h"

int main(int argc, char* argv[])
{
	if (argc < 2){
	std::cout << argv[0] << " Version " << RTLSDRCAMERA_VERSION_MAJOR << "."
		<< RTLSDRCAMERA_VERSION_MINOR << "." << RTLSDRCAMERA_VERSION_PATCH
		<< std::endl;
	std::cout << "Usage: " << argv[0] << "Tune frequency" << std::endl;
	return 1;
	}

	//TODO main function processing

	return 0;
}