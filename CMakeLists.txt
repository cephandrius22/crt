cmake_minimum_required(VERSION 3.10)

project(crt C)

# Define the library
add_library(vec3
    vec3.c
)

# Define the executable for the main program
add_executable(crt
    crt.c
)

# Link the main program with the vec3 library
target_link_libraries(crt
    PRIVATE vec3
)

# Define the executable for the tests
add_executable(test_vec3
    tests/test_vec3.c
)

target_include_directories(test_vec3 PRIVATE /opt/homebrew/include/check.h)
# Link the test suite with the vec3 library and the check library
target_link_libraries(test_vec3
    PRIVATE vec3
    /opt/homebrew/Cellar/check/0.15.2/lib/libcheck.a
)

# Enable testing for the project
enable_testing()

# Add a test using ctest
add_test(
    NAME test_vec3
    COMMAND test_vec3
)

