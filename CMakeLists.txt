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
find_package( PkgConfig )

# Find libusb
pkg_check_modules( PKG_LIBUSB libusb-1.0 )
find_path(LIBUSB_INCLUDE_DIR libusb.h
			HINT ${PKG_LIBUSB_INCLUDE_DIRS}
        	PATH_SUFFIXES libusb-1.0)
find_library(LIBUSB_LIBRARY usb-1.0
             HINT ${PKG_LIBUSB_LIBRARY_DIRS})

# Find rtl-sdr libraries
find_path (RTLSDR_INCLUDE_DIR rtl-sdr.h)
find_library (RTLSDR_LIBRARY librtlsdr.a)

# Print status messages for libusb and rtl-sdr
# Check if libusb is found 
if(LIBUSB_INCLUDE_DIR AND LIBUSB_LIBRARY)
	message(STATUS "Found libusb: ${LIBUSB_INCLUDE_DIR}, ${LIBUSB_LIBRARY}")
else()
	message(WARNING "Can not find libusb1.0-0-dev")
endif()

# Check if rtl-sdr is found
if(RTLSDR_INCLUDE_DIR AND RTLSDR_LIBRARY)
    message(STATUS "Found librtlsdr: ${RTLSDR_INCLUDE_DIR}, ${RTLSDR_LIBRARY}")
else()
    message(WARNING "Can not find Osmocom RTL-SDR library")
    message("Try again with environment variable PKG_CONFIG_PATH")
    message("or with -DRTLSDR_INCLUDE_DIR=/path/rtlsdr/include")
    message("        -DRTLSDR_LIBRARY=/path/rtlsdr/lib/librtlsdr.a")
endif()


# Set rtl-sdr necessary includes and libraries
set(RTLSDR_INCLUDE_DIRS ${RTLSDR_INCLUDE_DIR} ${LIBUSB_INCLUDE_DIR})
set(RTLSDR_LIBRARIES    ${RTLSDR_LIBRARY} ${LIBUSB_LIBRARY})

# Include directories for OpenCV and rtl-sdr
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( ${RTLSDR_INCLUDE_DIRS} )

# configure header file
configure_file(
    ${PROJECT_SOURCE_DIR}/cmake/rtlSdrCameraConfig.h.in
    ${PROJECT_BINARY_DIR}/rtlSdrCameraConfig.h
    )

# Add subdirectories
add_subdirectory(src)
add_subdirectory(test)

target_include_directories(rtlSdrCamera PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
