add_library(Controller STATIC Controller.cpp)

target_include_directories(Controller PUBLIC include)

target_link_libraries(Controller Joystick)