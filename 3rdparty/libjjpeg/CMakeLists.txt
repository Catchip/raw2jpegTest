# ----------------------------------------------------------------------------
#  CMake file for libjpeg. See root CMakeLists.txt
#
# ----------------------------------------------------------------------------

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB lib_srcs *.c)
file(GLOB lib_hdrs *.h)


add_library(jjpeg SHARED ${lib_srcs} ${lib_hdrs})


