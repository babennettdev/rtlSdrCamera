cmake_minimum_required(VERSION 3.10.2)

# Set the project name and version number
project(rtlSdrCamera CXX)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -ggdb")

# Project version
set(rtlSdrCamera_VERSION_MAJOR "0")
set(rtlSdrCamera_VERSION_MINOR "1")
set(rtlSdrCamera_VERSION_PATCH "0")

# Find packages
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# configure header file
configure_file(
    ${PROJECT_SOURCE_DIR}/cmake/rtlSdrCameraConfig.h.in
    ${PROJECT_BINARY_DIR}/rtlSdrCameraConfig.h
    )

add_subdirectory(src)




target_include_directories(rtlSdrCamera PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
