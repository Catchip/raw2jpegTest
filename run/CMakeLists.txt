add_executable(test ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)
add_executable(cal ./calmem.cpp)

add_executable(testcpu ${CMAKE_CURRENT_SOURCE_DIR}/testcpu.cpp)
#include_directories(test  ${PROJECT_SOURCE_DIR}/encoder)
target_include_directories(test  PUBLIC ${PROJECT_SOURCE_DIR}/encoders)
target_link_libraries(test encoder)

target_include_directories(testcpu  PUBLIC ${PROJECT_SOURCE_DIR}/encoders)
target_link_libraries(testcpu encoder)

set(Images images)
file(COPY ${Images} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(cal  PUBLIC ${PROJECT_SOURCE_DIR}/encoders)
target_link_libraries(cal encoder)

