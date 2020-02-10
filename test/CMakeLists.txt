add_executable(rtlSdrTest rtlSdrTest.cpp)

target_link_libraries( rtlSdrTest ${OpenCV_LIBS} ${RTLSDR_LIBRARIES} )