add_executable(
	rtlSdrUnitTests 
	rtlSdrTest.cpp
	)

target_link_libraries(
	rtlSdrUnitTests
	${OpenCV_LIBS} 
	${RTLSDR_LIBRARIES}
	unit_test_sources
	)