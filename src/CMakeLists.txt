add_executable(
	rtlSdrCamera 
	rtlSdrCamera.cpp
	rtlSdrSource.cpp
	)

target_link_libraries(
	rtlSdrCamera 
	${OpenCV_LIBS} 
	${RTLSDR_LIBRARIES}
	)

