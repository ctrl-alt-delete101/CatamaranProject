cmake_minimum_required(VERSION 3.5)
project(catamaran)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-pthread -Wall -Wextra -Wpedantic)
endif()

# Libraries

#find_package(SDL2)
#include_directories(${SDL2_INCLUDE_DIRS})

include_directories(include/catamaran)
include_directories(vendor/pigpio)

add_executable(laptop
  src/laptop.cpp include/catamaran/laptop.hpp)
target_link_libraries(laptop ${SDL2_LIBRARIES})

add_executable(catamaran src/catamaran.cpp
  include/catamaran/thrusters.hpp src/thrusters.cpp)
target_link_libraries(catamaran pthread pigpiod_if2)
