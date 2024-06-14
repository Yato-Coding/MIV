cmake_minimum_required(VERSION 3.10)
project(miv)
enable_testing()

set(CMAKE_PRESET_FILE "${CMAKE_SOURCE_DIR}/cmakepresets.json")

# Set the source directory
set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add the executable
add_executable(miv ${CMAKE_SOURCE_DIR}/main.cpp ${CMAKE_SOURCE_DIR}/ModeStateMachine.cpp ${CMAKE_SOURCE_DIR}/DefaultState.cpp ${CMAKE_SOURCE_DIR}/InsertState.cpp ${CMAKE_SOURCE_DIR}/GapBuffer.cpp)

# Link ncurses library
target_link_libraries(miv ncurses)

# add_subdirectory(./tests)
