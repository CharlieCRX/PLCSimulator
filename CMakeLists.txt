cmake_minimum_required(VERSION 3.10)
project(plc_simulator)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

# 1. 定义一个库，包含所有的业务逻辑
add_library(plc_core
  src/register_manager.cpp
  src/protocol/modbus_parser.cpp
)

# 2. 核心库需要包含 src 目录作为头文件路径
target_include_directories(plc_core PUBLIC src)

# 3. 主程序：链接核心库
add_executable(plc_simulator src/main.cpp)
target_link_libraries(plc_simulator plc_core)

# 4. 测试程序：链接核心库和 GTest
add_executable(tests
  tests/test_main.cpp
  tests/test_register_manager.cpp
  tests/test_modbus_parser.cpp
)

target_link_libraries(tests
  plc_core      # <-- 链接核心库，这样链接器就能找到 RegisterManager 的实现了
  gtest
  gtest_main
  pthread
)

add_test(NAME run_tests COMMAND tests)