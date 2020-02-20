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

# Adding a library with sources for unit testing
add_library(unit_test_sources "")
target_sources(
    unit_test_sources
    PRIVATE
        rtlSdrSource.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/rtlSdrSource.h
    )
target_include_directories(
    unit_test_sources
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )