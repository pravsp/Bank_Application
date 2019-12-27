
##################################
# Download and install JsonCpp
##################################


################

file(GLOB BANK_UTILS_SOURCES "*.cc")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/dist)

add_library(bank_utils STATIC
            ${BANK_UTILS_SOURCES})
target_link_libraries(bank_utils libjsoncpp.a)



#target_include_directories(bank_utils PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/jsoncpp/src/jsoncpp)
target_include_directories (bank_utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
install(TARGETS bank_utils DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})