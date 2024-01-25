cmake_minimum_required (VERSION 3.27)


project(
Borderlands
DESCRIPTION  "Borderlands 2D fan game"
LANGUAGES    CXX
)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Default build type as Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Find required external libraries
find_package( SFML COMPONENTS system window graphics REQUIRED)


# Add the src subdirectory
add_subdirectory(src)