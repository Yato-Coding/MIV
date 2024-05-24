cmake_minimum_required(VERSION 3.10)
project(miv)

# Set the source directory
set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(CMAKE_CXX_STANDARD 20)

# Add the executable
add_executable(miv ${CMAKE_SOURCE_DIR}/main.cpp ${CMAKE_SOURCE_DIR}/ModeStateMachine.cpp ${CMAKE_SOURCE_DIR}/DefaultState.cpp ${CMAKE_SOURCE_DIR}/InsertState.cpp ${CMAKE_SOURCE_DIR}/GapBuffer.cpp)

# Set the output directory for the executable
set_target_properties(miv PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./../bin)

# Link ncurses library
target_link_libraries(miv ncurses)

add_subdirectory(./tests)

enable_testing()
