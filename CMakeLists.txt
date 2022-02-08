cmake_minimum_required(VERSION 3.5)

# Set policies up to 3.9 since we want to enable the IPO option
if(${CMAKE_VERSION} VERSION_LESS 3.9)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
	cmake_policy(VERSION 3.9)
endif()

# This can be read from ${PROJECT_NAME} after project() is called
project(luaparse)
set(PROJECT_NAME_CAPITALIZED "LuaParse")

set(CMAKE_CXX_STANDARD 11)
set(GCC_MINIMUM_VERSION "5.1")
set(CLANG_MINIMUM_VERSION "3.5")

if(NOT CMAKE_BUILD_TYPE)
	# Default to release
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type: Debug or Release" FORCE)
endif()

# Installation
set(BINDIR "bin")

# Subdirectories
add_subdirectory(src)