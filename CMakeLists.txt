cmake_minimum_required(VERSION 3.10)

# set the project site_name

project(Comp)


file(GLOB_RECURSE ItkLS_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/encoders/*.cpp)

#if(UNIX)
	#link_directories(${PROJECT_SOURCE_DIR}/opencv/linux-x86_64/bin)
#elseif(WIN32)
	#link_directories(${PROJECT_SOURCE_DIR}/opencv/win-x86_64/lib)
#endif()

add_library(encoder ${ItkLS_SOURCES})
add_subdirectory(3rdparty/libjjpeg)
#target_include_directories(Comp PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(encoder PUBLIC /usr/include/opencv4)
target_include_directories(encoder PUBLIC 3rdparty)

target_link_libraries(encoder
	opencv_core
	opencv_imgcodecs
	opencv_highgui
	turbojpeg
	jpeg
	jjpeg
)

add_subdirectory(run)



