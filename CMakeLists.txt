cmake_minimum_required(VERSION 3.15)
project(GStreamerDemo LANGUAGES C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GStreamer REQUIRED)

add_executable(gstreamer_demo main.cpp)

target_link_libraries(gstreamer_demo PRIVATE gstreamer::gstreamer)

set_target_properties(gstreamer_demo PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                ${CMAKE_BINARY_DIR}/bin)
