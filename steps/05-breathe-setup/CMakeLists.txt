cmake_minimum_required(VERSION 3.15)

project(doxysphinx VERSION 0.1.0)

# Add the cmake folder for custom modules
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_executable(doxysphinx  src/main.cpp
        src/my-math.cpp)


add_subdirectory(docs/)
