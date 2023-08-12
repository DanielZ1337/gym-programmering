cmake_minimum_required(VERSION 3.1)

project( Drone )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/opencv/build")
find_package( OpenCV REQUIRED )
include_directories( include ${OpenCV_INCLUDE_DIRS} )

add_executable( Drone main.cpp)
target_link_libraries( Drone PRIVATE ${OpenCV_LIBS} )

