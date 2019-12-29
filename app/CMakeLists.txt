file(GLOB BANKING_APP_SOURCES "*.cc")
include_directories(${CMAKE_SOURCE_DIR}/src/banking_lib/include)
include_directories(${CMAKE_SOURCE_DIR}/src/banking_utils/include)
include_directories(${CMAKE_SOURCE_DIR}/dist)

add_executable(banking_app ${BANKING_APP_SOURCES})


target_compile_features(banking_app PRIVATE cxx_std_17)

target_link_libraries(banking_app PRIVATE ${CMAKE_SOURCE_DIR}/lib/libbank_oper.a)
target_link_libraries(banking_app PRIVATE ${CMAKE_SOURCE_DIR}/lib/libbank_utils.a)
target_link_libraries(banking_app PRIVATE ${CMAKE_SOURCE_DIR}/lib/libjsoncpp.a)

