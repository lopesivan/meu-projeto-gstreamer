cmake_minimum_required(VERSION 3.15)
project(GStreamerDemo LANGUAGES C CXX)

find_package(GStreamer REQUIRED)

add_executable(gstreamer_demo main.cpp)

target_link_libraries(gstreamer_demo PRIVATE GStreamer::GStreamer)

set_target_properties(gstreamer_demo PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                ${CMAKE_BINARY_DIR}/bin)
