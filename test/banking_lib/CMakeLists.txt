################
# Define a test
file(GLOB BANK_CFG_TEST_SOURCES "*.cc")

include_directories(${PROJECT_SOURCE_DIR}/src/banking_lib/include)
include_directories(${PROJECT_SOURCE_DIR}/src/banking_utils/include)
include_directories(${PROJECT_SOURCE_DIR}/dist)
add_executable(bank_cfg_test ${BANK_CFG_TEST_SOURCES})
target_link_libraries(bank_cfg_test gtest_main)
set_property(TARGET bank_cfg_test PROPERTY CXX_STANDARD 17)
######################################

######################################
# Configure the test to use GoogleTest
#
# If used often, could be made a macro.

# add_dependencies(template_test gtest)
# include_directories(${source_dir}/include)
# target_link_libraries(template_test ${binary_dir}/libgtest.a)
# target_link_libraries(template_test ${binary_dir}/libgtest_main.a)
target_link_libraries(bank_cfg_test ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libbank_utils.a)
target_link_libraries(bank_cfg_test ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libbank_oper.a)
target_link_libraries(bank_cfg_test ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/libjsoncpp.a)

##################################
# Just make the test runnable with
#   $ make test

enable_testing()
add_test(NAME    bank_cfg_test 
         COMMAND bank_cfg_test)
