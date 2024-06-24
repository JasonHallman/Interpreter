cmake_minimum_required(VERSION 3.10)

# Set the project name
project(interpreter)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Add include directories
include_directories(include)

# Add the executable
add_executable(interpreter
	src/main.cpp
	src/token.cpp
	src/lexer.cpp
)

# Add the tests
add_subdirectory(tests)
