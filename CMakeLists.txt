cmake_minimum_required(VERSION 3.16)
project(msdc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin")

find_library(WIRINGPI_LIBRARIES NAMES wiringPi)
find_package(Threads REQUIRED)

add_subdirectory(Controller)
add_subdirectory(Joystick)
add_subdirectory(Motor)
add_subdirectory(Utilities)

add_executable(run main.cpp)
target_link_libraries(run Controller Joystick Motor Utilities ${WIRINGPI_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})