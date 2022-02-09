project(luaparse)

INCLUDE(CheckIncludeFiles)
INCLUDE(CheckLibraryExists)

# Surpress some useless warnings
add_definitions ( /D "_CRT_SECURE_NO_DEPRECATE" /W1 )
# Get M_PI to work
add_definitions(/D "_USE_MATH_DEFINES")
# Dont define min/max macros in minwindef.h
add_definitions(/D "NOMINMAX")

set(PLATFORM_LIBS ws2_32.lib version.lib shlwapi.lib winmm.lib)

include_directories(
	./lua
    .
)

add_subdirectory(md4c)

add_executable(parse main.cpp)
target_link_libraries(parse ${CMAKE_SOURCE_DIR}/src/lua/lua51.lib md4c)

install (TARGETS parse DESTINATION ${CMAKE_SOURCE_DIR}/bin)