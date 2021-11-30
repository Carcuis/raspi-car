add_library(Controller STATIC ChassisControl.cpp ArmControl.cpp)

target_include_directories(Controller PUBLIC include)

target_link_libraries(Controller Joystick)