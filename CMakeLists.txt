cmake_minimum_required(VERSION 3.5)

# set the project name
project(MultithreadingMutex)

include_directories(include)

file(GLOB SOURCES "src/*.c")

# add the executable
add_executable(mthread-mutext ${SOURCES})

#############################################
# Unit tests

add_subdirectory(3rd_party/google-test)

# enable CTest testing
enable_testing()

file(GLOB TEST_SOURCES "tests/*.cpp")

# Add a testing executable
add_executable(unit_tests ${TEST_SOURCES})

target_link_libraries(unit_tests
    GTest::GTest 
    GTest::Main
)

add_test(test_all unit_tests)