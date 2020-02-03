cmake_minimum_required(VERSION 3.10.2)

# Set the project name and version number
project(rtlSdrCamera VERSION 0.1.0)

add_executable(rtlSdrCamera rtlSdrCamera.cpp)

configure_file(rtlSdrCameraConfig.h.in rtlSdrCameraConfig.h)

target_include_directories(rtlSdrCamera PUBLIC
							"${PROJECT_BINARY_DIR}"
							)
