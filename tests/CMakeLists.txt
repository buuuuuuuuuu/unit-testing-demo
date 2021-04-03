# 设置测试程序名字
set(PROJECT_NAME_TEST
    ${PROJECT_NAME}_test)

#可访问private
ADD_COMPILE_OPTIONS(-fno-access-control)
ADD_COMPILE_OPTIONS(-fno-inline)
#添加-fno-inline编译选项，禁止内联，能获取到函数地址，可以对内联函数进行打桩
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-inline")

# 添加gocv覆盖率文件的输出
set(CMAKE_CXX_FLAGS "-g -fprofile-arcs -ftest-coverage")

#test files
AUX_SOURCE_DIRECTORY(./ MAIN)
LIST(APPEND SRC_LIST ${MAIN})
AUX_SOURCE_DIRECTORY(./func FUNC)
LIST(APPEND SRC_LIST ${FUNC})


file(GLOB ALL_HEADERS "../src/func/*.h")
file(GLOB ALL_SOURCES "../src/func/*.cpp")


#将test文件，源文件，源头文件，moc文件加入到test程序中
add_executable(${PROJECT_NAME_TEST} ${SRC_LIST} ${ALL_HEADERS} ${ALL_SOURCES})


target_link_libraries(${PROJECT_NAME_TEST} gmock gmock_main gtest gtest_main pthread)

# 添加 QTest 测试
add_test(${PROJECT_NAME_TEST} COMMAND ${PROJECT_NAME_TEST})


#------------------------------ 创建'make test'指令---------------------------------------
add_custom_target(test
    COMMAND echo " =================== TEST BEGIN ==================== "
    COMMAND mkdir -p coverageResult
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMAND ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME_TEST}
    COMMAND echo " =================== TEST END ==================== "
)

#'make test'命令依赖与我们的测试程序
add_dependencies(test ${PROJECT_NAME_TEST})
