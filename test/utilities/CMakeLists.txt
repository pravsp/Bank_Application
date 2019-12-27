################
# Define a test
file(GLOB UTILITIES_TEST_SOURCES "*.cc")

include_directories(${PROJECT_SOURCE_DIR}/src/lib/include)
add_executable(utilities_test ${UTILITIES_TEST_SOURCES})
target_link_libraries(utilities_test gtest_main)
set_property(TARGET utilities_test PROPERTY CXX_STANDARD 17)
######################################

######################################
# Configure the test to use GoogleTest
#
# If used often, could be made a macro.

# add_dependencies(template_test gtest)
# include_directories(${source_dir}/include)
# target_link_libraries(template_test ${binary_dir}/libgtest.a)
# target_link_libraries(template_test ${binary_dir}/libgtest_main.a)
target_link_libraries(utilities_test ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/lbank_utils.a)

##################################
# Just make the test runnable with
#   $ make test

enable_testing()
add_test(NAME    utilities_test 
         COMMAND utilities_test)