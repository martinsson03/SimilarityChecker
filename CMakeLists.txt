cmake_minimum_required(VERSION 3.5.0)
project(SimilarityChecker VERSION 0.1.0 LANGUAGES C CXX)

# Automatically find all source and header files
file(GLOB SOURCE_FILES src/*.cpp)
file(GLOB HEADER_FILES include/*.h)

# Add executable and specify source files
add_executable(SimilarityChecker ${SOURCE_FILES})

# Include the header files directory
target_include_directories(SimilarityChecker PRIVATE include)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
