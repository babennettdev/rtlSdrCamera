cmake_minimum_required(VERSION 3.10.2)

# Set the project name and version number
project(rtlSdrCamera CXX)

add_executable(rtlSdrCamera rtlSdrCamera.cpp)

# configure header file
configure_file(
    ${PROJECT_SOURCE_DIR}/cmake/rtlSdrCameraConfig.h.in
    ${PROJECT_BINARY_DIR}/rtlSdrCameraConfig.h
    )

add_subdirectory(src)

# Project version
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)