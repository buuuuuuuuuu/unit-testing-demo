#cmake 最小版本要求
cmake_minimum_required(VERSION 3.1.0)

#工程名
project(unit-testing-demo)
set(NAME "unit-testing-demo")

# 设置C++标准为 C++ 11
set(CMAKE_CXX_STANDARD 11)


if (NOT (${CMAKE_BUILD_TYPE} MATCHES "Debug"))
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")
endif ()


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# 添加子模块test
add_subdirectory(src)
add_subdirectory(tests)

