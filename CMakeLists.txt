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
#target_include_directories(Comp PUBLIC ${PROJECT_SOURCE_DIR})

if(UNIX)
	target_include_directories(encoder PUBLIC /usr/include/opencv4)
	target_link_libraries(encoder
	opencv_core
	opencv_imgcodecs
	opencv_highgui
	turbojpeg
	jpeg
	jjpeg
	)
elseif(WIN32)
	 set_target_properties( encoder PROPERTIES RUNTIME_OUTPUT_DIRECTORY 
    ${sample_project_BINARY_DIR}/build_results/bin )

	link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/opencv/win-x86_64/lib)
	link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/libjpeg-turbo64/lib)
	target_include_directories(encoder PUBLIC ${PROJECT_SOURCE_DIR}/3rdparty/opencv/include)
	target_include_directories(encoder PUBLIC ${PROJECT_SOURCE_DIR}/3rdparty/libjpeg-turbo64/include)

	target_link_libraries(encoder
	opencv_world451
	turbojpeg
	jpeg
 	)
endif()


add_subdirectory(run)



