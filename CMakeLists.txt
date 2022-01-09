cmake_minimum_required(VERSION 3.20)
project(parallel-array-processing VERSION 1.0)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -fopenmp")

add_executable(parallel-array-processing src/main.c src/usage.c src/usage.h src/param_handling.c src/param_handling.h src/file_processing.c src/file_processing.h src/array_initialization.c src/array_initialization.h src/average_calculation.c src/average_calculation.h src/write_result.c src/write_result.h src/float_handler.c src/float_handler.h)
target_link_libraries(parallel-array-processing m)

enable_testing()
include(CTest)

set (USAGE_REGEX "^Usage:[.]+")
set (SUCCESS_REGEX "\nWe will initialize[.]+")
set (FILE_CONTENT_ERROR_REGEX "[\r\n\t ]Error during processing the given file[\r\n\t ]")

add_test(NAME "Test 0: Show usage"
        COMMAND "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}")
set_property(TEST "Test 0: Show usage"
        PROPERTY WILL_FAIL true)
set_property(TEST "Test 0: Show usage"
        PROPERTY PASS_REGULAR_EXPRESSION "${USAGE_REGEX}")

add_test(NAME "Test 1: Pass just -r parameter"
        COMMAND "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}" -r 3)
set_property(TEST "Test 1: Pass just -r parameter"
        PROPERTY WILL_FAIL true)
set_property(TEST "Test 1: Pass just -r parameter"
        PROPERTY PASS_REGULAR_EXPRESSION "${USAGE_REGEX}")

add_test(NAME "Test 2: Pass just -c parameter"
        COMMAND "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}" -c 3)
set_property(TEST "Test 2: Pass just -c parameter"
        PROPERTY WILL_FAIL true)
set_property(TEST "Test 2: Pass just -c parameter"
        PROPERTY PASS_REGULAR_EXPRESSION "${USAGE_REGEX}")

add_test(NAME "Test 3: Pass just -f parameter"
        COMMAND "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}" -f 3)
set_property(TEST "Test 3: Pass just -f parameter"
        PROPERTY WILL_FAIL true)
set_property(TEST "Test 3: Pass just -f parameter"
        PROPERTY PASS_REGULAR_EXPRESSION "${USAGE_REGEX}")

add_test(NAME "Test 4: Pass all required parameters"
        COMMAND "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}" -n 4 -f ../test/array_example_0.txt)
set_tests_properties(
        "Test 4: Pass all required parameters"
        PROPERTIES
            FAIL_REGULAR_EXPRESSION
                "${FILE_CONTENT_ERROR_REGEX}"
        )

add_test(NAME "Test 5: Will handle random tabs and spaces between numbers in file"
        COMMAND "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}" -n 4 -f ../test/array_example_1.txt)
set_tests_properties(
        "Test 5: Will handle random tabs and spaces between numbers in file"
        PROPERTIES
        FAIL_REGULAR_EXPRESSION
        "${FILE_CONTENT_ERROR_REGEX}"
)

add_test(NAME "Test 6: Will fail as the second row contains an extra column"
        COMMAND "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}" -n 4 -f ../test/array_example_2.txt)
set_property(TEST "Test 6: Will fail as the second row contains an extra column"
        PROPERTY WILL_FAIL true)
set_tests_properties(
        "Test 6: Will fail as the second row contains an extra column"
        PROPERTIES
        FAIL_REGULAR_EXPRESSION
        "${FILE_CONTENT_ERROR_REGEX}"
)

add_test(NAME "Test 7: Will fail as the second row contains less columns"
        COMMAND "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}" -n 4 -f ../test/array_example_3.txt)
set_property(TEST "Test 7: Will fail as the second row contains less columns"
        PROPERTY WILL_FAIL true)
set_tests_properties(
        "Test 7: Will fail as the second row contains less columns"
        PROPERTIES
        FAIL_REGULAR_EXPRESSION
        "${FILE_CONTENT_ERROR_REGEX}"
)

add_test(NAME "Test 8: Will fail as the file contains an extra row"
        COMMAND "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}" -n 4 -f ../test/array_example_4.txt)
set_property(TEST "Test 8: Will fail as the file contains an extra row"
        PROPERTY WILL_FAIL true)
set_tests_properties(
        "Test 8: Will fail as the file contains an extra row"
        PROPERTIES
        FAIL_REGULAR_EXPRESSION
        "${FILE_CONTENT_ERROR_REGEX}"
)