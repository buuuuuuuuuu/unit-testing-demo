#设置包含目录
include_directories(${PROJECT_SOURCE_DIR}/src/
                    ${CMAKE_BINARY_DIR}
    )

file(GLOB ALL_SOURCES "*.cpp" "./func/*.cpp")
file(GLOB ALL_HEADERS "*.h" "./func/*.h")


#设置输入执行文件名称
add_executable(unit-testing-demo ${ALL_SOURCES} ${ALL_HEADERS})


