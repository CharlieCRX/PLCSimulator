cmake_minimum_required(VERSION 3.10)

project(plc_simulator)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable(plc_simulator
  src/main.cpp
)

add_executable(tests
  tests/test_main.cpp
  tests/test_register_manager.cpp
)

target_link_libraries(tests
  gtest
  gtest_main
  pthread
)

add_test(NAME run_tests COMMAND tests)