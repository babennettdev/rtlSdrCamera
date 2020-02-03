// main file for rtlSdrCamera

//includes
#include <iostream>
#include <string>
#include "rtlSdrCameraConfig.h"

int main(int argc, char* argv[])
{
	if (argc < 1){
	std::cout << argv[0] << " Version " << rtlSdrCamera_VERSION_MAJOR << "." 
		<< rtlSdrCamera_VERSION_MINOR << "." << rtlSdrCamera_VERSION_PATCH
		<< std::endl;
	std::cout << "Usage: " << argv[0] << "Tune frequency" << std::endl;
	return 1;
	}

	#TODO main function processing

	return 0;
}