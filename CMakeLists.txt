cmake_minimum_required(VERSION 3.14)
project(big_integer)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(big_integer_test src/big_integer.h src/big_integer.cpp test/big_integer_test.cpp)
target_link_libraries(big_integer_test gtest_main)
include(GoogleTest)
gtest_discover_tests(big_integer_test)