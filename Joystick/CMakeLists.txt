add_library(Joystick STATIC Joystick.cpp JoystickControl.cpp)

target_include_directories(Joystick PUBLIC include)

target_link_libraries(Joystick ${OpenCV_LIBS})
target_link_libraries(Joystick Utilities Motor)