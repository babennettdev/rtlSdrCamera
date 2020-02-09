add_executable(rtlSdrCamera rtlSdrCamera.cpp)

target_link_libraries( rtlSdrCamera ${OpenCV_LIBS} ${RTLSDR_LIBRARIES} )