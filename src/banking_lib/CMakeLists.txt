file(GLOB BANK_OPER_SOURCES "*.cc")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src/banking_utils/include)
include_directories(${CMAKE_SOURCE_DIR}/dist)

add_library(bank_oper STATIC
            ${BANK_OPER_SOURCES})

target_include_directories (bank_oper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries (bank_oper LINK_PUBLIC libbank_utils.a)
install(TARGETS bank_oper DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})