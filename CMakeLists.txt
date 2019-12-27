
# Works with 3.11 and tested through 3.15
cmake_minimum_required(VERSION 3.11...3.16)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_CXX_STANDARD 17)

# Project name and a few useful settings. Other commands can pick up the results
project(Banking_Application
    VERSION 0.1
    DESCRIPTION "A Simple Bank Application"
    LANGUAGES CXX)




enable_testing() # needed on top-level CmakeLists.txt

add_subdirectory(dist)
add_subdirectory(src)
#add_subdirectory(test)
add_subdirectory(app)