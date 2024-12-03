# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(MyProject)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include all .c files in the src directory
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src/*.c)

# Include all .h files in the inc directory
include_directories(${CMAKE_SOURCE_DIR}/inc)

# Add the executable
add_executable(MyProject ${SOURCES})

# Set the output directory for executables (forces all configurations to use bin/)
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG_UPPER)
    set_target_properties(MyProject PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG_UPPER} ${CMAKE_SOURCE_DIR}/bin
    )
endforeach()
