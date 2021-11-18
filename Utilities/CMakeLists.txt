add_library(Utilities STATIC Utilities.cpp)

target_include_directories(Utilities PUBLIC include)

target_link_libraries(Utilities Joystick)