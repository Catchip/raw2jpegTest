set(resources "images/*.jpg")
add_executable(test ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)
include_directories(test  ${PROJECT_SOURCE_DIR}/encoder)
target_include_directories(test  PUBLIC ${PROJECT_SOURCE_DIR}/encoders)
target_link_libraries(test encoder)


target_link_libraries(test opencv_world451)

set(Images images)
set(opencvdll ${PROJECT_SOURCE_DIR}/3rdparty/opencv/win-x86_64/bin/opencv_world451.dll)
set(turbodll ${PROJECT_SOURCE_DIR}/3rdparty/libjpeg-turbo64/bin/jpeg62.dll ${PROJECT_SOURCE_DIR}/3rdparty/libjpeg-turbo64/bin/turbojpeg.dll)
file(COPY ${Images} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${opencvdll} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${turbodll} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

