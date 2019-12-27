file(GLOB JSONCPP_SOURCES "*.cpp")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/json)

add_library(jsoncpp STATIC
            ${JSONCPP_SOURCES})

target_include_directories (jsoncpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/json)
install(TARGETS jsoncpp DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})