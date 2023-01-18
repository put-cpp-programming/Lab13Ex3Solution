# CMakeList.txt : CMake project for Ex3, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Ex3")

# Add source to this project's executable.
add_executable (Ex3 "main.cpp" "main.h" "student.h" "student.cpp" "menagestudents.cpp" "menagestudents.h" "ex3.h" "ex3.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Ex3 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
